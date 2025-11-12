#include<bits/stdc++.h>
#define Std_Maker lhm
#define ll long long
using namespace std;
const int N=5e6+1,M=2e4+1;
ll n,m,k,c[11][M],fa[M],ans=0,cnt;
bool A=1;
struct lhm
{
    ll u,v,w;
}e[N];
bool cmp(lhm a,lhm b)
{
    return a.w<b.w;
}
ll find(ll x)
{
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
void kruskal(ll n,ll m)
{
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        ll u=find(e[i].u),v=find(e[i].v);
        if(u==v) continue;
        ans+=e[i].w;
        fa[u]=v;
    }
    return;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=n;j++) cin>>c[i][j];
    }
    for(int i=1;i<=k;i++)
    {
        if(c[i][0]!=0) A=0;
    }
    if(k==0)
    {
        kruskal(n,m);
        cout<<ans;
        return 0;
    }
    if(A==1)
    {
        cnt=m;
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                e[++cnt].u=n+i,e[cnt].v=j,e[cnt].w=c[i][j];
            }
        }
        kruskal(n+k,cnt);
        cout<<ans;
        return 0;
    }
    return 0;
}
//26min 16pts
