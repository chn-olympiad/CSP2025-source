#include <bits/stdc++.h>
using namespace std;
#define int long long
bool vis[100005];
int ans,sz,n,m,c[100005],k,fa[100005];
struct edge{int v,w;};
vector<edge> g[100005];
int f(int x)
{
    if (fa[x])
        return fa[x];
    return fa[x]=f(fa[x]);
}
void merge(int x,int y){fa[f(x)]=f(y);}
signed main()
{
    int i,j,k,mv,mw,u,v,w;
    bool flag=0;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for (i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    sz=n;
    for (i=1;i<=k;i++)
    {
        cin>>c[++sz];
        for (j=1;j<=n;j++)
        {
            cin>>w;
            g[sz].push_back({j,w});
            g[j].push_back({sz,w});
        }
    }
    for (i=1;i<=sz;i++)
        fa[i]=i;
    for (u=1;u<=n;u++)
    {
        mw=1e9,flag=0;
        for (edge e:g[u])
        {
            v=e.v,w=e.w;
            if (u==v)
                continue;
            if (c[v])
                w+=c[v],flag=1;
            if (w<mw&&f(u)!=f(v))
            {
                mv=v,mw=w;
                if (flag)
                    c[mv]=0;
            }
        }
        //cout<<u<<" "<<mv<<" "<<mw<<endl;
        if (f(u)!=f(v))
        {
            merge(u,mv);
            ans+=mw;
        }
    }
    cout<<ans<<endl;
    return 0;
}

