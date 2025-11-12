//第一次CSP-S考试 RP++
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=8e3+10,maxm=1e6+10;

ll n,m,k,tot,w[maxn],fa[maxn],dis[maxn][maxn];

struct Edge
{
    int v,u;
    ll w;
}e[maxn*maxn];

void add(int u,int v,ll w)
{
    e[++tot].u=u;
    e[tot].v=v;
    e[tot].w=w;
}

bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}

int find(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}

void merge(int u,int v)
{
    int x=find(u);int y=find(v);
    fa[y]=x;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m>>k;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dis[i][j]=2e18;
    for(int i=1;i<=n;i++) fa[i]=i;

    for(ll i=1;i<=m;i++)
    {
        ll u,v,w;cin>>u>>v>>w;
        dis[u][v]=min(dis[u][v],w);
        dis[v][u]=min(dis[v][u],w);
    }

    for(int i=1;i<=k;i++)
    {
        ll c;cin>>c;
        for(int l=1;l<=n;l++)
        {
            cin>>w[l];
            for(int j=1;j<l;j++)
            {
                dis[l][j]=min(dis[l][j],w[j]+w[l]+c);
                dis[j][l]=min(dis[j][l],w[j]+w[l]+c);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            add(i,j,dis[i][j]);
        }
    }

    sort(e+1,e+tot+1,cmp);

    ll ans=0;
    for(ll i=1;i<=tot;i++)
    {
        int u=e[i].u,v=e[i].v;
        ll w=e[i].w;
        if(find(u)==find(v)) continue;
        merge(u,v);
        ans+=w;
    }

    cout<<ans<<"\n";

    return 0;
}
