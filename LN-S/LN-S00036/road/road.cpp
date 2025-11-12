#include <iostream>
#include <algorithm>
#define int long long
const int N=1e4+25,M=1e6+N;
int n,m,K,fa[N],c[15],a[15][N],vc[M];
struct pii {int u,v;} tal[M];
int hed[M],nxt[M],cnte;
void de(int u,const pii &v) {tal[++cnte]=v,nxt[cnte]=hed[u],hed[u]=cnte;}
struct Edge
{
    int u,v,w;
    bool operator <(const Edge &g) const {return w<g.w;}
} e[M],E[N];
int gf(int x) {return x==fa[x]?x:fa[x]=gf(fa[x]);}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    std::cin.tie(0)->sync_with_stdio(0);
    std::cin>>n>>m>>K;
    for(int i=1,u,v,w;i<=m;i++) std::cin>>u>>v>>w,e[i]={u,v,w};
    int sz=0;
    for(int i=1;i<=K;i++)
    {
        std::cin>>c[i];
        for(int j=1;j<=n;j++) std::cin>>a[i][j],vc[++sz]=a[i][j];
    }
    std::sort(e+1,e+m+1);
    for(int i=1;i<=n;i++) fa[i]=i;
    int len=0;
    for(int i=1;i<=m;i++)
    {
        int u=gf(e[i].u),v=gf(e[i].v);
        if(u==v) continue;
        E[++len]=e[i],fa[u]=v,vc[++sz]=e[i].w;
    }
    std::sort(vc+1,vc+sz+1),sz=std::unique(vc+1,vc+sz+1)-vc-1;
    for(int i=1;i<=K;i++) for(int j=1;j<=n;j++)
        a[i][j]=std::lower_bound(vc+1,vc+sz+1,a[i][j])-vc;
    for(int i=1;i<n;i++) E[i].w=std::lower_bound(vc+1,vc+sz+1,E[i].w)-vc;
    int ans=1e18;
    for(int s=0;s<1<<K;s++)
    {
        for(int i=1;i<=sz;i++) hed[i]=0;
        for(;cnte;cnte--) nxt[cnte]=0;
        for(int i=1;i<n;i++) de(E[i].w,{E[i].u,E[i].v});
        len=n-1;
        for(int i=1;i<=n+K;i++) fa[i]=i;
        int sum=0;
        for(int i=1;i<=K;i++) if(s>>i-1&1)
        {
            sum+=c[i];
            for(int j=1;j<=n;j++) de(a[i][j],{i+n,j});
        }
        for(int i=1;i<=sz;i++) for(int j=hed[i];j;j=nxt[j])
        {
            int u=gf(tal[j].u),v=gf(tal[j].v);
            if(u==v) continue;
            sum+=vc[i],fa[u]=v;
        }
        ans=std::min(ans,sum);
    }
    std::cout<<ans;
}