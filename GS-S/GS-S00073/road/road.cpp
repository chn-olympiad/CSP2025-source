#include <bits/stdc++.h>
#define MAXN (signed)(1e4+10)
#define int long long
using namespace std;
vector<pair<int,int>>G[MAXN];
int fa[MAXN];
int n,m,k;
void merg(int x,int y)
{
    fa[x]=y;
}
int findroot(int x)
{
    int f=fa[x];
    if(fa[f]==0)return f;
    return fa[x]=fa[findroot(f)];
}
priority_queue<pair<int,pair<int,int>>>pq;
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
        pq.push({-w,{u,v}});
    }
    int ans=0;
    while(!pq.empty())
    {
        int w=pq.top().first,u=pq.top().second.first,v=pq.top().second.second;
        pq.pop();
        if(findroot(u)!=findroot(v))
        {
            merg(u,v);
            ans+=(-w);
        }
    }
    cout<<ans;
}
