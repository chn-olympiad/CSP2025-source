#include<bits/stdc++.h>
using namespace std;
string s,number;
int a[10];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin >>s;
for(int i = 0;i<=s.size();i++){
    if(s[i]=='1') a[1]++;
    else if(s[i]=='2') a[2]++;
    else if(s[i]=='3') a[3]++;
    else if(s[i]=='4') a[4]++;
    else if(s[i]=='5') a[5]++;
    else if(s[i]=='6') a[6]++;
    else if(s[i]=='7') a[7]++;
    else if(s[i]=='8') a[8]++;
    else if(s[i]=='9') a[9]++;
    else if(s[i]=='0') a[0]++;
}for(int i = 9;i>=0;i--){
if(a[i]!=0){
    if(i == 9){
        for(int j = 1;j<=a[i];j++){
            number+='9';
        }
    }
    if(i == 8){for(int j = 1;j<=a[i];j++){
            number+='8';
        }}

    if(i ==7){for(int j = 1;j<=a[i];j++){
            number+='7';
        }}
    if(i == 6){for(int j = 1;j<=a[i];j++){
            number+='6';
        }}
    if(i == 5){for(int j = 1;j<=a[i];j++){
            number+='5';
        }}
    if(i == 4){for(int j = 1;j<=a[i];j++){
            number+='4';
        }}
    if(i == 3){for(int j = 1;j<=a[i];j++){
            number+='3';
        }}
    if(i == 2){for(int j = 1;j<=a[i];j++){
            number+='2';
        }}
   if(i == 1){for(int j = 1;j<=a[i];j++){
            number+='1';
        }}
    else if(i == 0){
        if(number != ""){
            for(int j = 1;j<=a[i];j++){
            number+='0';
        }
        }
    }
}
}
if(number == "") cout<<0;
else cout<<number;
fclose(stdin);
fclose(stdout);
return 0;
}



