#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5;
long long n,m,k;
struct Edge
{
    long long u,v,w,ta;
} e[2*N];
long long cnt;
long long fa[N];
long long c[N],vit[N],siz[N],vis[N];
long long find(long long x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void merge(long long u,long long v)
{
    long long x=find(u),y=find(v);
    if(x!=y) fa[x]=y,siz[y]+=siz[x];
}
void add(long long u,long long v,long long w,long long ta)
{
    e[++cnt].u=u,e[cnt].v=v,e[cnt].w=w,e[cnt].ta=ta;
}
bool cmp(Edge &a,Edge &b)
{
    return a.w<b.w;
}
long long ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        add(u,v,w,0);
    }
    if(k==0)
    {
        sort(e+1,e+cnt+1,cmp);
        for(long long i=1;i<=n;i++) fa[i]=i,siz[i]=1;
        for(long long i=1;i<=cnt;i++)
        {
            if(find(e[i].u)!=find(e[i].v))
            {
                ans+=e[i].w;
                merge(e[i].u,e[i].v);
            }
        }
        cout<<ans;
        return 0;
    }
    for(long long i=1;i<=k;i++)
    {
        cin>>c[i];
        for(long long j=1;j<=n;j++)
        {
            long long w;
            cin>>w;
            add(n+i,j,w+c[i],i);
        }
    }
    sort(e+1,e+cnt+1,cmp);
    for(long long i=1;i<=n;i++) fa[i]=i,siz[i]=1;
    for(long long i=n+1;i<=n+k;i++) fa[i]=i;
    for(long long i=1;i<=cnt;i++)
    {
        if(find(e[i].u)!=find(e[i].v) && e[i].u<=n && e[i].v<=n)
        {
            ans+=e[i].w;
            merge(e[i].u,e[i].v);
            vit[e[i].ta]++;
            if(siz[find(e[i].u)]==n) break;
        }
        if(find(e[i].u)!=find(e[i].v) && (e[i].u>n || e[i].v>n)) vit[e[i].ta]++;
    }
    for(long long i=1;i<=n;i++) fa[i]=i,siz[i]=1;
    for(long long i=n+1;i<=n+k;i++) fa[i]=i;
    ans=0;
    for(long long i=1;i<=cnt;i++)
    {
        if(find(e[i].u)!=find(e[i].v))
        {
            if(e[i].u>n && vit[e[i].ta]<=1) continue;
            if(e[i].v>n && vit[e[i].ta]<=1) continue;
            ans+=e[i].w;
            merge(e[i].u,e[i].v);
            vis[e[i].ta]++;
            if(siz[find(e[i].u)]==n) break;
        }
    }
    for(long long i=1;i<=k;i++)
    {
        if(vis[i]) ans-=(vis[i]-1)*c[i];
    }
    cout<<ans;
    return 0;
}
