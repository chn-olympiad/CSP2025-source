#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=2e6+5;
const ll N=1e4+5;
ll n,m,k;
struct edge
{
    ll u,v,w;
    friend bool operator<(edge a,edge b)
    {
        return a.w<b.w;
    }
} e[M];
ll fa[N],c[N];
ll find(ll x)
{return fa[x]==x?x:fa[x]=find(fa[x]);}
ll solve1();
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m>>k;
    for (ll i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    for (ll i=1;i<=k;i++)
    {
        cin>>c[i];
        for (ll j=1;j<=n;j++)
        {
            m++;
            cin>>e[m].w;
            e[m].u=c[i],e[m].v=j;
        }
    }
    cout<<solve1()<<"\n";
    
    return 0;
}
ll solve1()
{
    sort(e+1,e+1+m);
    iota(fa+1,fa+1+n,1);
    ll cnt=0,ans=0;
    for (ll i=1;i<=m;i++)
    {
        ll u=e[i].u,v=e[i].v,w=e[i].w;
        ll fu=find(u),fv=find(v);
        if (fu!=fv)
        {
            fa[fu]=fv;
            cnt++;
            ans+=w;
        }
    }
    return ans;
}