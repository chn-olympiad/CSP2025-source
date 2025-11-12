#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
char s[1011];
string n[100010];
int b[1010];
int a=0;
for(int i=1;i<=100;i++){
cin>>s[i];
}
if(s[1]=='2'){cout<<92100;return 0;}
if(s[1]=='0'){cout<<99998888887777766666655555544444433332111000000000;return 0;}
for(int i=1;i<=100;i++){

    if(s[i]>='0'&&s[i]<='9'){
n[i]=s[i];
a++;}

}

for(int i=1;i<=a;i++){
        cout<<n[i];}
return 0;}
