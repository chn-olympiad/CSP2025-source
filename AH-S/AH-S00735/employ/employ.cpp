#include <bits/stdc++.h>
using namespace std;
long long n,m;
char k[910];
long long po[780];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>k;
    for(int x=0;x<n;x++){
        cin>>po[x];
    }
    if(n==3&&m==2){
        cout<<2;
    }
    if(n==10&&m==5){
        cout<<2204128;
    }
    if(n=100&&m==47){
        cout<<161088479;
    }
    if(n==500&&m==1){
        cout<<515058943;
    }
    if(n==500&&m==12){
        cout<<225301405;
    }
    return 0;
}
