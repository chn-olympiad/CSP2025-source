#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353
#define rep(i,s,t) for(ll i = s;i <= t;++i)
#define per(i,t,s) for(ll i = t;i >= s;--i)
const ll N = 5e3 + 5;
ll n;
ll ans;
ll a[N] = {};
bool vis[N] = {};
ll c[N][N] = {};
inline void openfile(string s)
{
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
inline void closefile()
{
    fclose(stdin);
    fclose(stdout);
}
inline bool check()
{
    ll maxn = 0;
    rep(i,1,n)
        maxn = max(a[i],maxn);
    return maxn == 1;
}
inline void solve()
{
    rep(i,1,n)
    {
        c[i][0] = 1;
        c[i][i] = 1;
        rep(j,1,i - 1)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
    rep(i,3,n)
        ans = (ans + c[n][i]) % MOD;
    printf("%lld",ans);
}
inline void dfs(ll sum,ll maxn,ll cnt)
{
    if(sum > (maxn << 1) && cnt >= 3)
        ans = (ans + 1) % MOD;
    rep(i,1,n)
    {
        if(!vis[i])
        {
            vis[i] = true;
            dfs(sum + a[i],max(maxn,a[i]),cnt + 1);
            vis[i] = false;
        }
    }
}
int main()
{
    openfile("polygon");
    scanf("%lld",&n);
    rep(i,1,n)
        scanf("%lld",&a[i]);
    if(check())
    {
        solve();
        return 0;
    }
    dfs(0,0,0);
    printf("%lld",ans);
    closefile();
    return 0;
}
