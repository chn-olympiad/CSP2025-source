#include<bits/stdc++.h>
#define ll long long
#define pr pair<int,int>
#define fi first
#define se second
using namespace std;
const ll N=1e3+10,mod=998244353;
ll n,m,c[N],vis[N],ans;
string s;
void dfs(int dep,int cnt)
{
    if(cnt>n-m) return;
    if(dep>n){
        ans=(ans+1)%mod;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        if(s[dep-1]=='0' || c[i]<=cnt ) dfs(dep+1,cnt+1);
        else dfs(dep+1,cnt);
        vis[i]=0;
    }
}
ll qpow(ll base,int x)
{
    ll res=1;
    while(x){
        if(x&1) res=(res*base)%mod;
        base=(base*base)%mod;
        x>>=1;
    }
    return res%mod;
}
void calc()
{
    ll x=1,y=1;
    for(int i=1;i<=n;i++) x=(x*i)%mod;
    // for(int i=1;i<=m;i++) y=(y*i)%mod;
    // y=(y*m)%mod;
    for(int i=1;i<=(n-m);i++) y=(y*i)%mod;
    // cout<<x<<" "<<y<<endl;
    y=qpow(y,mod-2);
    ans=(x*y)%mod;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int flg=0;
    for(int i=0;i<s.size();i++)
        if(s[i]=='0'){
            flg=1; break;
        }
    // calc();
    if(flg==1 || n<=10) dfs(1,0);
    else calc();
    cout<<ans<<endl;
    return 0;
}