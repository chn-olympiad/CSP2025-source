#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define INF 0x3f3f3f3f
#define endl '\n'
#define pow po_w
using namespace std;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while (ch<'0' or ch>'9') {if (ch=='-')  f=-f;ch=getchar();}
    while (ch>='0' and ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll po_w(ll x,ll y,ll mod){
    ll ans=1;
    while (y){
        if (y&1)
            ans*=x;
        x*=x;
        y>>=1;
        x%=mod;
        ans%=mod;
    }
    return ans;
}
ll gcd(ll x,ll y){
    if (y==0)
        return x;
    return gcd(y,x%y);
}
int n;
ll a[5005],dp[5005][5005],f[5005][5005],maxx;
ll ans;
const ll mod=998244353;
void dfs(int x,int cnt,ll sum,ll num){
    if (x>n and cnt>=3 and sum>2*num)
        ans++,ans%=mod;
    if (x>n)
        return;
    dfs(x+1,cnt+1,sum+a[x],max(num,a[x]));
    dfs(x+1,cnt,sum,num);
}
void solve(){
    n=read(),maxx=0;
    for (int i=1;i<=n;i++)
        a[i]=read(),maxx=max(maxx,a[i]);
    if (maxx==1){
        ll ans=pow(2,n,mod)-1-n;
        ans-=(1ll*n*(n-1)/2)%mod;
        ans=(ans+mod)%mod;
        printf("%lld\n",ans);
        return;
    }
    if (n<=20){
        dfs(1,0,0,0);
        printf("%lld\n",ans%mod);
        return;
    }
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ll t=1;
    // t=read();
    while (t--)
        solve();
    return 0;
}