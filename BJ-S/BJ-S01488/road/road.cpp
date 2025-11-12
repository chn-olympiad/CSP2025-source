#include <bits/stdc++.h>
using namespace std;
int n,m,k,fa[10001],cnt;
long long c[11],a[11][10001],ans;
struct edge
{
    int u,v;
    long long w;
}e[2000000];
int find(int u)
{
    return (u==fa[u])?u:(fa[u]=find(fa[u]));
}
void merge(int u,int v)
{
    fa[u]=v;
}
bool cmp(edge x,edge y)
{
    return x.w<y.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n+k;i++)
        fa[i]=i;
    for (int i=1;i<=m;i++)
        scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
    cnt=m;
    for (int i=1;i<=k;i++)
    {
        scanf("%lld",&c[i]);
        for (int j=1;j<=n;j++)
        {
            scanf("%lld",&e[++cnt].w);
            e[cnt].u=j;
            e[cnt].v=n+i;
        }
    }
    sort(e+1,e+cnt+1,cmp);
    for (int i=1;i<=cnt;i++)
    {
        int u=find(e[i].u),v=find(e[i].v);
        if (u!=v)
        {
            merge(u,v);
            ans+=e[i].w;
        }
    }
    cout<<ans;
}