#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int c[20],a[20][10010];
struct Edge
{
    int u,v,w;
    bool operator<(const Edge &nxt)const
    {
        return w<nxt.w;
    }
}edge[1000010];

vector<Edge>g,e;

int f[10100];

int find(int x)
{
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}

long long kru()
{
    sort(e.begin(),e.end());
    for(int i=1;i<=n+k;i++)f[i]=i;
    long long res=0;
    for(int i=0;i<e.size();i++)
    {
        int u=e[i].u,v=e[i].v,w=e[i].w;
        if(find(u)!=find(v))
        {
            f[find(u)]=find(v);
            res+=w;
        }
    }
    return res;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    for(int i=1;i<=k;i++)
    {
        cin >> c[i];
        for(int j=1;j<=n;j++)
            cin >> a[i][j];
    }
    sort(edge+1,edge+m+1);
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        if(find(u)!=find(v))
        {
            f[find(u)]=find(v);
            g.push_back({u,v,w});
        }
    }
    long long ans=1e18;
    for(int i=0;i<(1<<k);i++)
    {
        long long res=0;
        e.clear();
        for(Edge j:g)
            e.push_back(j);
        for(int j=0;j<k;j++)
        {
            if(i&(1<<j))
            {
                res+=c[j+1];
                for(int x=1;x<=n;x++)
                    e.push_back({n+j+1,x,a[j+1][x]});
            }
        }
        res+=kru();
        ans=min(ans,res);
    }
    cout << ans << '\n';
    return 0;
}