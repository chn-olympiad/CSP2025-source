#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=10054,M=1000006;
int n,m,k,fa[N],sz[N];
ll w[15];
struct edge{ll x,y,w,id;}e[M<<1];
int ask(int x)
{
    if(fa[x]!=x) fa[x]=ask(fa[x]);
    return fa[x];
}
bool cmp(edge x,edge y)
{
    return x.w<y.w;
}
inline void read(ll &x)
{
    x=0;
    char c=getchar();
    while(c<48) c=getchar();
    while(c>=48) x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    ll ans=0;
    for(int i=1;i<=m;i++) read(e[i].x),read(e[i].y),read(e[i].w),ans+=e[i].w;
    for(int i=1;i<=k;i++)
    {
        ll x;
        read(w[i]);
        for(int j=1;j<=n;j++)
        {
            read(x);
            e[++m]={i+n,j,x,i};
        }
    }
    sort(e+1,e+m+1,cmp);
    for(int s=0;s<(1<<k);s++)
    {
        ll now=0;
        for(int i=0;i<k;i++)
            if((1<<i)&s) now+=w[i+1];
        if(now>ans) continue;
        for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
        for(int i=1;i<=k;i++) fa[i+n]=i+n,sz[i+n]=0;
        for(int i=1;i<=m;i++)
        {
            ll x=e[i].x,y=e[i].y,id=e[i].id;
            int fx=ask(x),fy=ask(y);
            if(fx==fy) continue;
            if(id) if(((1<<(id-1))&s)==0) continue;
            if(sz[ask(1)]==n) break;
            if(sz[fx]>=sz[fy]) fa[fy]=fx,sz[fx]+=sz[fy];
            else fa[fx]=fy,sz[fy]+=sz[fx];
            now+=e[i].w;
            if(now>=ans) break;
        }
        if(now<ans&&sz[ask(1)]==n) ans=now;
    }
    printf("%lld",ans);
    /*puts("yes");*/
    return 0;
}

