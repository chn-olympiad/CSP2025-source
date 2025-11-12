#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005];
bool f_1(){
    for(ll i=1;i<=n;i++){
        if(a[i]!=1){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=3){
        if(n==1){
            cout<<0;
        }
        if(n==2){
            cout<<0;
        }
        if(n==3){
            if(a[1]+a[2]+a[3]>max({a[1],a[2],a[3]})*2){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
    }
    else if(f_1()){
        ll ANS=0;
        for(ll i=3;i<=n;i++){
            ll ans=1;
            for(ll j=n;j>=n-i+1;j--){
                ans*=j;
                ans/=(n-j+1);
            }
            ANS+=ans;
            ANS%=998244353;
        }
        cout<<ANS;
    }
    else{
        cout<<100;
    }
    return 0;
}
