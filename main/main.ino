#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include "Credentials.h"

#ifndef WIFI_SSID
  #define WIFI_SSID "_WIFI_NAME_"
#endif
#ifndef WIFI_PSK
  #define WIFI_PSK "_WIFI_PASSWORD_"
#endif

void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());

  Serial.println(myWiFiManager->getConfigPortalSSID());
}

void setup() {
    Serial.begin(115200);
    WiFiManager wm;


    bool res;
    wm.setAPCallback(configModeCallback);
    res = wm.autoConnect(WIFI_SSID, WIFI_PSK);

    if(!res) {
        Serial.println("Failed to connect");
        // ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("connected...yay :)");
    }

}

void loop() {
    // put your main code here, to run repeatedly:   
}
