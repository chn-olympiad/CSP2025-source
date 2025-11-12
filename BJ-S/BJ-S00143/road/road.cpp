#include<bits/stdc++.h>
using namespace std;
struct Node
{
    long long id,val;
};
vector<Node> g[2000002];
long long c[12],a[12][2000002],u[2000002],v[2000002],w[2000002],tmp[202];
bool vis[2000002];
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;
long long n,m,k,minn=1e18,cost;
void minnshengchengtree()
{
    while(!q.empty())
    {
        int lval=q.top().first,lid=q.top().second;
        q.pop();
        if(vis[lid])
            continue;
        cost+=lval;
        vis[lid]=true;
        for(int i=0;i<g[lid].size();i++)
        {
            if(!vis[g[lid][i].id])
                q.push({g[lid][i].val,g[lid][i].id});
        }
    }
}
void DFS(long long x)
{
    if(x==k+1)
    {
        while(!q.empty())
            q.pop();
        cost=0;
        for(long long i=1;i<=n+k;i++)
            vis[i]=false,g[i].clear();
        long long dmin=1e18,minx,miny;
        for(long long i=1;i<=m;i++)
        {
            g[u[i]].push_back({v[i],w[i]}),g[v[i]].push_back({u[i],w[i]});
            if(w[i]<dmin)
                dmin=w[i],minx=u[i],miny=v[i];
        }
        for(long long i=1;i<=k;i++)
        {
            if(tmp[i]==1)
            {
                cost+=c[i];
                for(long long j=1;j<=n;j++)
                {
                    g[n+i].push_back({j,a[i][j]}),g[j].push_back({n+i,a[i][j]});
                    if(a[i][j]<dmin)
                        dmin=a[i][j],minx=n+i,miny=j;
                }
            }
        }
        vis[minx]=true,vis[miny]=true;
        cost+=dmin;
        for(long long i=0;i<g[minx].size();i++)
        {
            if(!vis[g[minx][i].id])
                q.push({g[minx][i].val,g[minx][i].id});
        }
        for(long long i=0;i<g[miny].size();i++)
        {
            if(!vis[g[miny][i].id])
                q.push({g[miny][i].val,g[miny][i].id});
        }
        minnshengchengtree();
        minn=min(minn,cost);
        return;
    }
    tmp[x]=1;
    DFS(x+1);
    tmp[x]=0;
    DFS(x+1);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool f=true;
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++)
        cin>>u[i]>>v[i]>>w[i];
    for(long long i=1;i<=k;i++)
    {
        cin>>c[i];
        if(c[i]!=0)
            f=false;
        for(long long j=1;j<=n;j++)
            cin>>a[i][j];
    }
    if(f)//A
    {
        cost=0;
        long long dmin=1e18,minx,miny;
        for(long long i=1;i<=m;i++)
        {
            g[u[i]].push_back({v[i],w[i]}),g[v[i]].push_back({u[i],w[i]});
            if(w[i]<dmin)
                dmin=w[i],minx=u[i],miny=v[i];
        }
        for(long long i=1;i<=k;i++)
        {
            for(long long j=1;j<=n;j++)
            {
                g[n+i].push_back({j,a[i][j]}),g[j].push_back({n+i,a[i][j]});
                if(a[i][j]<dmin)
                    dmin=a[i][j],minx=n+i,miny=j;
            }
        }
        vis[minx]=true,vis[miny]=true;
        cost+=dmin;
        for(long long i=0;i<g[minx].size();i++)
        {
            if(!vis[g[minx][i].id])
                q.push({g[minx][i].val,g[minx][i].id});
        }
        for(long long i=0;i<g[miny].size();i++)
        {
            if(!vis[g[miny][i].id])
                q.push({g[miny][i].val,g[miny][i].id});
        }
        minnshengchengtree();
        cout<<cost;
        return 0;
    }
    DFS(1);
    cout<<minn;
    return 0;
}