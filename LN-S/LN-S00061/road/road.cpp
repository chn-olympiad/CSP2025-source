#include<bits/stdc++.h>
using namespace std;
int n,m,k,head[500010],cnt,dis[500010],ans,u,v,w;
bool vis[500010];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
struct edge
{
    int to,val,nxt;
}e[500010];
void add(int u,int v,int w)
{
    e[++cnt].nxt=head[u];
    e[cnt].to=v;
    e[cnt].val=w;
    head[u]=cnt;
}
void prim()
{
    for(int i=1;i<=n;i++)dis[i]=2147483647;
    dis[1]=0;
    q.push({0,1});
    while(!q.empty())
    {
        u=q.top().second;w=q.top().first;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].nxt)
        {
            if(dis[e[i].to]>dis[u]+e[i].val)
            {
                ans+=e[i].val;
                dis[e[i].to]=dis[u]+e[i].val;
                q.push({e[i].val,e[i].to});
            }
        }
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1;i<=k;i++)
    {
        cin>>u;
        for(int j=1;j<=n;j++)cin>>v;
    }
    prim();
    cout<<ans;
}
