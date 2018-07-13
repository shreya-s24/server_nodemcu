#include <Wire.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
const char* ssid = "Shreya";  // Enter SSID here
const char* password = "123456789";  //Enter Password here

ESP8266WebServer server(80);
 
 
void setup() {
  Serial.begin(9600); delay(200); Wire.begin(4,5);
  pinMode(LED_BUILTIN, OUTPUT); 
  
 //sda,scl for i2c // put your setup code here, to run once: //void begin(int sda, int scl);
mlx.begin();
  Serial.println("Connecting to ");
  Serial.println(ssid);
  //connect to your local wi-fi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());


  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  Serial.println(mlx.readAmbientTempC());
  delay(1000); Serial.println("objnow");
  Serial.println(mlx.readObjectTempC());
  Serial.println("next iteration");
  delay(1000);

  
  // put your main code here, to run repeatedly:

}
 String SendHTML(uint8_t led){
  String ptr = "<!DOCTYPE html>\n";
  ptr +="<html>\n";
  ptr +="<head>\n";
  ptr +="<title>LED Control</title>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<p>hi there </p>";
  if(mlx.readObjectTempC()>55 && mlx.readObjectTempC() >45)
  ptr +="unsafe\n";
else
ptr +="safe\n";
  
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
   digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
                                    // but actually the LED is on; this is because 
                                    // it is active low on the ESP-01)
  delay(1000);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(2000);   
}
  
  
