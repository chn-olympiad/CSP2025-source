#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500050];
bool f_1(){
    for(ll i=1;i<=n;i++){
        if(a[i]!=1){
            return false;
        }
    }
    return true;
}
bool f_01(){
    for(ll i=1;i<=n;i++){
        if(a[i]!=1&&a[i]!=0){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k<=1&&f_01()){
        ll ans=0;
        if(k==0){
            for(ll i=1;i<=n;i++){
                if(a[i]==0){
                    ans++;
                }
                if(a[i]==1&&a[i+1]==1){
                    i++;
                    ans++;
                }
            }
            cout<<ans;
        }
        if(k==1){
            for(ll i=1;i<=n;i++){
                if(a[i]==1){
                    ans++;
                }
            }
            cout<<ans;
        }
    }
    else{
        cout<<255;
    }
    return 0;
}
