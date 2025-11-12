#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
const int M=1e6+6;
int n,m,k,fa[N],ans,a[10][N],c[N];
struct Edge
{
    int u,v,w;
}e[M];
void init()
{
    int i;
    for(i=1;i<=n;i++) fa[i]=i;
    return ;
}
int fin(int x)
{
    if(x==fa[x]) return x;
    fa[x]=fin(fa[x]);
    return fa[x];
}
bool merg(int x,int y)
{
    int u=fin(x),v=fin(y);
    if(u==v) return false;
    fa[v]=u;
    return true;
}
bool cmp(Edge x,Edge y)
{
    return x.w<y.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int i,j;
    cin>>n>>m>>k;
    init();
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    for(i=1;i<=k;i++)
    {
        scanf("%d",&c[i]);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    sort(e+1,e+1+m,cmp);
    for(i=1;i<=m;i++)
    {
        if(merg(e[i].u,e[i].v))
        {
            ans+=e[i].w;
        }
    }
    printf("%d",ans);
    return 0;
}
