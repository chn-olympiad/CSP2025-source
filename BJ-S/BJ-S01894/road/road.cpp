#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
ll n,m,k;
struct pst{
    ll u,v,w;
};
pst g[1000010];
ll fa[100010];
ll find(ll x)
{
    if(x==fa[x])
    {
        return fa[x];
    }
    fa[x]=find(fa[x]);
    return fa[x];
}
bool cmp(pst x,pst y)
{
    return x.w<y.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        g[i]=((pst){u,v,w});
    }
    sort(g+1,g+1+m,cmp);
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    ll ans=0;
    for(int i=1;i<=m;i++)
    {
        ll x=find(g[i].u);
        ll y=find(g[i].v);
        if(x!=y)
        {
            fa[x]=fa[y];
            ans+=g[i].w;
        }
    }
    cout<<ans;
    return 0;
}
