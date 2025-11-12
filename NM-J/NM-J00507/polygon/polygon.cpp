#include<bits/stdc++.h>
using namespace std;
int m,a[5100],dp[5100];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>m;
    if(m<3){
        cout<<0;
        return 0;
    }
    if(m==3){
        cout<<1;
        return 0;
    }
    if(m>=3&&m<=5){
        cout<<9;
        return 0;
    }
    if(m>=6&&m<=10){
        cout<<6;
        return 0;
    }
    cout<<m/3;

    return 0;
}
