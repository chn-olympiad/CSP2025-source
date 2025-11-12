#include<bits/stdc++.h>
using namespace std;
int cnt;
bool cmp(int a,int b){
return a>b;}
int main(){

freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
cin>>s;
for(int i=0;i<s.size();i++){
if(s[i]>='0'&&s[i]<='9'){
cnt++;
}
}
int t[cnt]={0};
int j=0;
for(int i=0;i<s.size();i++){
    if(s[i]>='0'&&s[i]<='9'){
        t[j]=s[i]-'0';
        j++;
}
}
sort(t,t+cnt,cmp);
if(t[0]==0){
cout<<0;
return 0;}
for(int i=0;i<cnt;i++){
cout<<t[i];}

    return 0;
}
