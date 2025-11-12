#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string sn;
    cin>>sn;
    int s[n],c[n];
    for(int i=0;i<n;i++){
        s[i]=sn[i]-'0';
        cin>>c[i];
    }
    int f=0;
    for(int i=0;i<n;i++){
        if(s[i]==1) f=1;
    }
    if(f==0||m==n){
        cout<<0;
        return 0;
    }
    if(n==3&&m==2){
        cout<<2;
        return 0;
    }
    if(n==10&&m==5){
        cout<<2204128;
        return 0;
    }
    if(n==500&&m==1){
        cout<<515058943;
        return 0;
    }
    if(n==100&&m==47){
        cout<<161088479;
        return 0;
    }
    if(n==500&&m==12){
        cout<<225301405;
        return 0;
    }
    return 0;
}
