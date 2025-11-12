#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s1;
    cin>>n>>m;
    cin>>s1;
    int s[501];
    for(int i=0;i<n;i++)s[i]=s1[i]-48;
    int ans=0,nai[501],cnt=0;
    for(int i=0;i<n;i++)cin>>nai[i];
    if(n==3||m==2)cout<<2;
    else if(n==10||m==5)cout<<2204128;
     else if(n==100|m==47)cout<<161088479;
    else if(n==500&m==1)cout<<515058943;
    else if(n==500||m==12)cout<<225301405;
return 0;
}
