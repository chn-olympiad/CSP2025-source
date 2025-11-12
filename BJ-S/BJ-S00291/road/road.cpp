#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fst first
#define scd second
using namespace std;
const int N=1e4+5;
const int M=1e6+2e5+5;
const int inf=1e18;
int n,m,k;
struct Edge { int u,v,w; }e[M],e2[M];
int ex[12][N],c[12];
int fa[N],ans;

int find_fa(int x) { return fa[x]==x?x:fa[x]=find_fa(fa[x]); }
inline bool cmp(Edge x,Edge y) { return x.w<y.w; }
inline int kruskal(int s)
{
    int res=0; int cnt=m;
    for (int i=1;i<=m;i++) e[i]=e2[i];
    for (int i=1;i<=k;i++)
    {
        if (!(s&(1ll<<i-1))) continue;
        res+=c[i];
        for (int j=1;j<=n;j++) e[++cnt]={n+i,j,ex[i][j]};
    }
    sort(e+1,e+1+cnt,cmp);
    for (int i=1;i<=n+k;i++) fa[i]=i;
    for (int i=1;i<=cnt;i++)
    {
        int u=find_fa(e[i].u),v=find_fa(e[i].v);
        if (u==v) continue;
        res+=e[i].w; fa[u]=v;
    }
    return res;
}
int read()
{
    int f=0; char c=getchar();
    while (c<'0'||c>'9') c=getchar();
    while (c>='0'&&c<='9') f=(f<<3)+(f<<1)+(c^48),c=getchar();
    return f;
}
inline int init()
{
    int res=0;
    for (int i=1;i<=m;i++) e[i]=e2[i];
    sort(e+1,e+1+m,cmp);

    for (int i=1;i<=n;i++) fa[i]=i;
    int cnt=0;
    for (int i=1;i<=m;i++)
    {
        int u=find_fa(e[i].u),v=find_fa(e[i].v);
        if (u==v) continue;
        res+=e[i].w;
        fa[u]=v;
        e2[++cnt]={e[i].u,e[i].v,e[i].w};
    }
    m=cnt;
    return res;
}
inline pii MIN(pii a,pii b) { return a.fst<b.fst?a:b; }
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    n=read(),m=read(),k=read(); int u,v,w;
    for (int i=1;i<=m;i++) e2[i].u=read(),e2[i].v=read(),e2[i].w=read();
    for (int i=1;i<=k;i++)
    {
        c[i]=read(); pii mn={inf,0};
        for (int j=1;j<=n;j++) ex[i][j]=read(),mn=MIN(mn,{ex[i][j],j});
        if (mn.fst==0&&c[i]==0) { for (int j=1;j<=n;j++) e2[++m]={mn.scd,j,ex[i][j]}; k--,i--; }
    }
    ans=init(); 
    for (int i=1;i<(1<<k);i++) ans=min(ans,kruskal(i));
    cout<<ans<<"\n"; return 0;
}