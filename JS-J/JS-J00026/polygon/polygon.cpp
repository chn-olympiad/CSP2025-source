#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int len=5e3+5,mod=998244353;
int n,a[len];
ll ans,dp[len];
map<int,int>f;
ll qpow(ll b,ll p){
    ll res=1;
    while(p){
        if(p&1) res=res*b%mod;
        b=b*b%mod;;
        p/=2;
    }
    return res;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=len;j>=a[i];j--){
            dp[j]=(dp[j]+dp[j-a[i]])%mod;
        }
    }
    for(int i=1;i<=len;i++) dp[i]=(dp[i]+dp[i-1])%mod;
    ans=qpow(2,n);
    for(int i=1;i<=n;i++){
        f[a[i]]++;
        ans=((ans+mod-dp[a[i-1]])%mod+mod-f[a[i]])%mod;
    }
    cout<<ans<<'\n';
    return 0;
}
