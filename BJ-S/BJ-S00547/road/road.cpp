#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,k,dis[10001],vis[10001],c[11];
struct edge{
    int v;
    int w;
};
struct pot{
    int pos;
    int dis;
    bool operator< (const pot &x) const{
        return x.dis<dis;
    }
};
vector<edge> e[10001];
priority_queue<pot> q;
void dijkstra(int s)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=0x3f3f3f3f;
        vis[i]=0;
    }
    dis[s]=0;
    q.push((pot){s,0});
    while(!q.empty())
    {
        pot t=q.top();
        q.pop();
        int d=t.dis;
        int k=t.pos;
        if(vis[k]) continue;
        vis[k]=1;
        bool flag=false;
        for(int j=0;j<e[k].size();j++)
        {
            int kv=e[k][j].v;
            int kw=e[k][j].w;
            if(k>m && !flag)
            {
                kw+=c[k];
                flag=true;
            }
            dis[kv] = min(dis[kv],dis[k]+kw);
            if(!vis[kv]) q.push((pot){kv,dis[kv]});
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
        int u,v,w;
        cin>>u>>v>>w;
        edge p;
        p.v = v;
        p.w = w;
        e[u].push_back(p);
        p.v = u;
        e[v].push_back(p);
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n+1;j++)
        {
            int a[10001];
            cin>>c[j];
            int u=m+j;
            for(int k=1;k<=n;k++)
            {
                cin>>a[k];
                int v=k;
                int w=a[k];
                edge p;
                p.v=v;
                p.w=w;
                e[u].push_back(p);
                p.v=u;
                e[v].push_back(p);
            }
        }
    }
}