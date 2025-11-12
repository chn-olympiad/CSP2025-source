#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5005],s[5005],sum;
//vector<ll> v;
void solve(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    if(n==3){
        if(a[1]+a[2]>a[3]) cout<<1;
        else cout<<0;
    }
    else{
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(s[j]-s[i-1]>a[j]*2) sum++;
                for(ll k=i+1;k<=j-1;k++){
                    if(s[j]-s[i-1]-s[k]>a[j]*2) sum++;
                }
            }
        }
        cout<<sum%244;
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;//cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
