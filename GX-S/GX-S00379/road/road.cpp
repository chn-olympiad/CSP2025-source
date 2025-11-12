#include<bits/stdc++.h>
#define ll long long
#define N 10100
#define M 1100010
#define K 12
using namespace std;
int n,m,k;
int cnt_edge,cnt_point;
int buildw[K],use_times[K];
ll ans=0;
struct edge
{
    int u,v,w;
    friend bool operator < (const edge &x,const edge &y)
    {
        return x.w<y.w;
    }
}e[M];
int fa[N];
int Find(int x)
{
    return x==fa[x]?x:fa[x]=Find(fa[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[i].u=u;e[i].v=v;e[i].w=w;
    }
    cnt_point=n;
    cnt_edge=m;
    for(int i=1;i<=k;i++)
    {
        ++cnt_point;
        scanf("%d",&buildw[i]);
        for(int i=1;i<=n;i++)
        {
            int w;
            scanf("%d",&w);
            ++cnt_edge;
            e[cnt_edge].u=cnt_point;
            e[cnt_edge].v=i;
            e[cnt_edge].w=w+buildw[i];
        }
    }
    for(int i=1;i<=n+k;i++) fa[i]=i;
    sort(e+1,e+1+cnt_edge);
    for(int i=1;i<=cnt_edge;i++)
    {
        int ou=e[i].u,ov=e[i].v;
        int u=Find(ou),v=Find(ov);
        if(u!=v)
        {
            if(ou>n)
            {
                int nw=ou-n;
                use_times[nw]++;
            }
            ans+=e[i].w;
            fa[u]=v;
        }
    }
    for(int i=1;i<=k;i++)
        if(use_times[i]) ans-=buildw[i]*(use_times[i]-1);
    printf("%lld",ans);
    return 0;
}
