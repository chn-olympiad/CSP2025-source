#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PLL pair<ll,ll>
struct node
{
    ll u,v,w;
}p[1000010];
ll fa[100010];
ll n,m,k,ans;
bool cmp(node x,node y)
{
    return x.w<y.w;
}
ll find(ll x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void kru()
{
    for(ll i=1;i<=n;i++)
        fa[i]=i;
    sort(p+1,p+m+1,cmp);
    for(ll i=1;i<=m;i++)
    {
        auto [u,v,w]=p[i];
        u=find(u),v=find(v);
        if(u==v)continue;
        ans+=w;
        fa[u]=v;
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0)
    {
        for(ll i=1;i<=m;i++)
        {
            ll u,v,w;
            cin>>p[i].u>>p[i].v>>p[i].w;
        }
        kru();
        cout<<ans<<'\n';
    }
    return 0;
}
