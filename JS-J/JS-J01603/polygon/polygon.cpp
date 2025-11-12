#include <bits/stdc++.h>
#define int long long
#define st first
#define nd second
#define MP make_pair
#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=5e3+5,mod=998244353;
int quickpow(int a,int b,int mod){
    int ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int n,a[N],dp[N],len,v[N],ans;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    rep(i,0,n)cin>>a[i];
    if(n>500){
        cout<<(quickpow(2,n,mod)+mod-1-n-(n*(n-1)/2%mod))%mod;
        return 0;
    }
    rep(i,0,n){
        len=0;
        rep(j,0,i)if(a[j]<=a[i])v[len++]=a[j];
        rep(j,i+1,n)if(a[j]<a[i])v[len++]=a[j];
        rep(j,0,a[i]+1)dp[j]=0;
        dp[0]=1;
        rep(j,1,len+1)REP(k,a[i],v[j-1])dp[k]=(dp[k]+dp[k-v[j-1]])%mod;
        ans=(ans+quickpow(2,len,mod))%mod;
        rep(j,0,a[i]+1)ans=(ans+mod-dp[j])%mod;
    }
    cout<<ans;
    return 0;
}
