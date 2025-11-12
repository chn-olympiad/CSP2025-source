#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const int N=1e3;
const int K=10;
ll n,m,k,adj[N+5][N+5],c[K+5],co[K+5][N+5],cnt,ans,f[N+5];
struct Node
{
    ll u,v,w;
}e[N*N+10];
bool cmp(Node a,Node b)
{
    if(a.w<b.w) return true;
    else return false;
}
ll Find(ll x)
{
    if(f[x]==x) return x;
    return f[x]=Find(f[x]);
}
void Merge(ll x,ll y)
{
    f[Find(x)]=Find(y);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(adj,0x3f,sizeof(adj));
    scanf("%lld%lld%lld",&n,&m,&k);
    for(ll i=1;i<=m;i++)
    {
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        adj[u][v]=adj[v][u]=w;
    }
    for(ll i=1;i<=k;i++)
    {
        scanf("%lld",&c[i]);
        for(ll j=1;j<=n;j++)
            scanf("%lld",&co[i][j]);
    }
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
        {
            if(i==j) continue;
            for(ll a=1;a<=k;a++)
                adj[i][j]=min(adj[i][j],co[a][i]+c[a]+co[a][j]);
            cnt++,e[cnt]={i,j,adj[i][j]};
        }
    sort(e+1,e+cnt+1,cmp);
    for(ll i=1;i<=n;i++) f[i]=i;
    for(ll i=1;i<=cnt;i++)
    {
        //cout<<
        //cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
        if(Find(e[i].u)==Find(e[i].v)) continue;
        Merge(e[i].u,e[i].v);
        ans+=e[i].w;
    }
    printf("%lld",ans);
    return 0;
}
