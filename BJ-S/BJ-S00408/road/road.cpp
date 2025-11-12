#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+50,MAXM=1e6+50;
struct node
{
    int u,v,w;
    bool operator < (const node &T) const
    {
        return w<T.w;
    }
};
node g[MAXM+15*MAXN];
int cnt,ans,c[15],deg[15],tmp[15],fa[MAXN],a[15][MAXN];
int getfa(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=getfa(fa[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,u,v,w;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        g[++cnt]={u,v,w};
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            g[++cnt]={n+i,j,a[i][j]};
        }
    }
    sort(g+1,g+m+n*k+1);
    for(int i=1;i<=n+k;i++)
        fa[i]=i;
    for(int i=1;i<=m+k*n;i++)
    {
        u=g[i].u;
        v=g[i].v;
        w=g[i].w;
        int fu=getfa(u),fv=getfa(v);
        if(fu==fv)
            continue;
        ans+=w;
        fa[fu]=fv;
        if(u>n)
        {
            tmp[u-n]=v;
            deg[u-n]++;
        }
        if(v>n)
        {
            tmp[v-n]=u;
            deg[v-n]++;
        }
    }
    for(int i=1;i<=k;i++)
    {
        if(deg[i]==1)
            ans-=a[i][tmp[i]];
        else
            ans+=c[i];
    }
    cout<<ans;
    return 0;
}
