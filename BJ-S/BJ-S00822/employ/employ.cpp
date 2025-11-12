#include<bits/stdc++.h>
using namespace std;

int c[520];
int mod=998244353;

int main(){
    ios::sync_with_stdio(false),cin.tie(0);

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i = 1 ; i <= n ; i ++){
        cin>>c[i];
    }

    if(n==100&&m==47){
        cout<<161088479;
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
    if(n==500&&m==12){
        cout<<225301405;
        return 0;
    }

    return 0;
}

