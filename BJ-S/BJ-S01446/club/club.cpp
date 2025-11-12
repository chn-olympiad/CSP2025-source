#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;

ll n,ans;
ll dp[N];
bool vis[N];
struct node
{
    ll a,b,c;
}s[N];
bool cmpA(node x, node y)
{
    return x.a>y.a;
}


//as we can see here you cant be greedy here
//what else do we have?
//should we dp?
/*
*/
inline void neonic_green()
{
}
//dfs
inline void dfs(ll x, ll y, ll z, ll cur,ll cnt)
{
    if(cur==n)
    {
        ans = max(ans,cnt);
        return;
    }
    if(x+1<=n/2)
    {
        dfs(x+1,y,z,cur+1,cnt+s[cur+1].a);
    }
    if(y+1<=n/2)
    {
        dfs(x,y+1,z,cur+1,cnt+s[cur+1].b);
    }
    if(z+1<=n/2)
    {
        dfs(x,y,z+1,cur+1,cnt+s[cur+1].c);
    }
    vis[cur] = 0;
    return;
}
inline void solve()
{
    bool flagA = true,flagB = true;
    ans = 0;
    memset(vis,0,sizeof(vis));
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>s[i].a>>s[i].b>>s[i].c;
        if(s[i].b!=0||s[i].c!=0)
        {
            flagA = false;
        }
        if(s[i].c!=0)
        {
            flagB = false;
        }
    }
    if(flagA==true)
    {
        sort(s+1,s+1+n,cmpA);
        for(int i = 1;i<=n/2;i++)
        {
            ans+=s[i].a;
        }
        cout<<ans<<'\n';
        return;
    }
    else dfs(0,0,0,0,0);
    cout<<ans<<'\n';
    return;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);


    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }

    return 0;
}
