#include <bits/stdc++.h>
using namespace std;
#define piii pair<int,pair<int,int> >
#define fi first
#define se second
#define endl '\n'
#define int long long
int n,m,k,ans,cnt;
//vector<pii > v[10020];
priority_queue<piii,vector<piii >,greater<piii > > q;
int fa[10020],a[10010];
bool vis[10020];
int findfa(int x)
{
    return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
void solve()
{//////xing zhi A A A
    cin>>n>>m>>k;
    for(int i=1;i<=n+20;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        //v[a].push_back({w,b});
        //v[b].push_back({w,a});
        q.push({w,{a,b}});
    }
    for(int i=1;i<=k;i++)
    {
        int c;
        cin>>c;//wu shi, yiwei A
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
        }
        for(int j=1;j<=n;j++)
        {
            for(int l=j+1;l<=n;l++)
            {
                q.push({a[j]+a[l],{j,l}});
            }
        }
    }
    while(!q.empty()&&cnt<n)//cnt ->city(only)
    {
        piii x=q.top();
        q.pop();
        int w=x.fi,u=x.se.fi,v=x.se.se;
        if(findfa(u)==findfa(v))continue;
        ans+=w;
        if(vis[u]==0)
        {
            vis[u]=1;
            cnt++;
        }
        if(vis[v]==0)
        {
            vis[v]=1;
            cnt++;
        }
        fa[findfa(v)]=findfa(u);
    }
    cout<<ans;
    return;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T=1;
    while(T--)solve();
    return 0;
}
