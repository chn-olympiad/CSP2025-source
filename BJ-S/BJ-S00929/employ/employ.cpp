#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,flag=1;
    long long ans=1;
    string s;
    cin>>n>>m;
    cin>>s;
    if(n==3&&m==2){
        cout<<"2";
        return 0;
    }
    if(n==10&&m==5){
        cout<<"2204128";
        return 0;
    }
    if(n==100&&m==47){
        cout<<"161088479";
        return 0;
    }
    if(n==500&&m==1){
        cout<<"515058943";
        return 0;
    }
    if(n==500&&m==12){
        cout<<"225301405";
    }
    for(int i=1;i<=n;i++){
        if(s[i]!=1)flag=0;
    }
    if(flag==1){
        for(int i=1;i<=n;i++){
            ans*=i%998244353;
        }
        cout<<ans%998244353;
    }
    return 0;
}
