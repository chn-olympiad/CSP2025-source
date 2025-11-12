#include<bits/stdc++.h>
#define ll long
using namespace std;
ll vim[15][10005];
ll f[10005];
ll fi(ll x)
{
    return x==f[x]?x:f[x]=fi(f[x]);
}
void merge_(ll x,ll y)
{
    f[x]=y;
    return;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,m,k;
    cin>>n>>m>>k;
    vector<array<ll,3>>a;
    for(ll i=1;i<=n;i++)f[i]=i;
    for(ll i=1;i<=m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        a.push_back({w,u,v});
    }
    for(ll i=1;i<=k;i++)
    {
        ll p;
        cin>>p;
        for(ll j=1;j<=n;j++)
        {
            cin>>vim[i][j];
        }
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            ll mn=INT_MAX*3;
            for(ll f=1;f<=k;f++)
            {
                mn=min(mn,vim[f][i]+vim[f][j]);
            }
            a.push_back({mn,i,j});
        }
    }
    ll ans=0;
    sort(a.begin(),a.end());
    for(auto[w,u,v]:a)
    {
        if(fi(u)!=fi(v))
        {
            merge_(fi(u),fi(v));
            ans+=w;
        }
    }
    //cout<<a.size()<<"\n";
    cout<<ans;
    return 0;
}
