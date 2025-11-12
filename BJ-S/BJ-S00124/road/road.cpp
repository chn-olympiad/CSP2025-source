#include <cstdio>
#include <algorithm>
using namespace std;
//inline int read()
constexpr int M=1e6+3,N=1e4+3,K=13;
struct Edge
{
    int u,v,w;
    bool operator<(const Edge &other) const
    {
        return w<other.w;
    }
} e[M+N*K];
int fa[N+K];
int find(int x)
{
    if (fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    fa[find(x)]=find(y);
}
typedef long long ll;
inline int read()
{
    int x=0;
    char c=getchar();
    while ('0'>c||c>'9')
    {
        c=getchar();
    }
    while ('0'<=c&&c<='9')
    {
        x=x*10+(c-'0');
        c=getchar();
    }
    return x;
}
int have_edge[K],have_spe_edge[K];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    n=read();
    m=read();
    k=read();
    for (int i=1;i<=m;i++)
    {
        e[i].u=read();
        e[i].v=read();
        e[i].w=read();
    }
    int tot=m;
    int nodetot=n;
    for (int i=1;i<=k;i++)
    {
        int c=read();
        nodetot++;
        for (int j=1;j<=n;j++)
        {
            tot++;
            e[tot].w=read();
            e[tot].u=nodetot;
            e[tot].v=j;
            e[tot].w+=c;
        }
    }
    sort(e+1,e+tot+1);
    for (int i=1;i<=nodetot;i++)
    {
        fa[i]=i;
    }
    ll mst=0;
    int cnt=0;
    //assert(nodetot==(n+k));
    //assert(tot==(m+n*k));
    for (int i=1;i<=tot;i++)
    {
        int u=e[i].u,v=e[i].v,w=e[i].w;
        if (find(u)!=find(v))
        {
            merge(u,v);
            mst+=w;
            cnt++;
            if (u>n&&v<=n)
            {
                have_edge[u-n]++;
                have_spe_edge[u-n]=w;
            }
            else if (u<=n&&v>n)
            {
                have_edge[v-n]++;
                have_spe_edge[v-n]=w;
            }
            if (cnt==nodetot-1) break;
        }
    }
    for (int i=1;i<=k;i++)
    {
        if (have_edge[i]==1)
        {
            mst-=have_spe_edge[i];
        }
    }
    printf("%lld",mst);
}
