#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5000+10;
const int mod=998244353;
int n,ans,a[N],vis[N],cur[N];
int fac[N],inv[N];
int qpow(int a,int b){
    int res=1;
    while(b){
        if(b&1) res=(res*a)%mod;
        a=a*a%mod; b>>=1;
    }
    return res;
}
void check(int x){
    --x; int mx=0,sm=0;
    for(int i=1;i<=x;++i){
        mx=max(mx,cur[i]);
        sm+=cur[i];
    }
    if(sm>2*mx) ++ans;
    else return;
}
void dfs(int cnt,int bef){
    if(cnt>n+1) return;
    if(cnt>3) check(cnt);
    for(int i=bef+1;i<=n;++i){
        if(vis[i]) continue;
        vis[i]=1,cur[cnt]=a[i];
        dfs(cnt+1,i);
        vis[i]=0,cur[cnt]=0;
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n; ans=0;
    for(int i=1;i<=n;++i) cin>>a[i];
    if(n<=20) dfs(1,0);
    else{
        fac[0]=fac[1]=1; inv[0]=inv[1]=1;
        for(int i=2;i<=n;++i) fac[i]=fac[i-1]*i%mod;
        // for(int i=2;i<=n;++i) cout<<fac[i]<<" ";
        // cout<<'\n';
        for(int i=2;i<=n;++i) inv[i]=qpow(fac[i],mod-2);
        // for(int i=2;i<=n;++i) cout<<inv[i]<<" ";
        // cout<<'\n';
        for(int i=3;i<=n;++i){
            int res=fac[n];
            res=(res*inv[i])%mod;
            res=(res*inv[n-i])%mod;
            ans=(ans+res)%mod;
        }
    }
    cout<<ans%mod;  return 0;
}