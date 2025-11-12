#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r"stdin);
freopen("number.out","w"stdout);
char s[101],a;
int n;
cin>>n;
for(int i=0;i<n;i++){
cin>>s[i];}
for(int i=0;i<n;i++){
if(s[i]=='1'&&s[i]=='2'&&s[i]=='3'&&s[i]=='4'&&s[i]=='5'&&s[i]=='6'&&s[i]=='7'&&s[i]=='8'&&s[i]=='9'&&s[i]=='0'){
if(s[i]<s[i+1]){
a=s[i];
s[i]=s[i+1];
s[i+1]=a;
}
}
}
for(int i=0;i<n;i++){
cout<<s[i];}
return 0;}
