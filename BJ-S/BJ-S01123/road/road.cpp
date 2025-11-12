#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
struct edge
{
    ll u,v,w;
    bool operator <(const edge &tmp) const
    {
        return w<tmp.w;
    }
}mp[2000001];
ll fa[10001];
ll find(ll x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void merge(ll x,ll y)
{
    if(find(x)!=find(y)) fa[find(x)]=find(y);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,k,ans=0,l=0,t1,t2;
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++) fa[i]=i;
    for(ll i=1;i<=m;i++)
    {
        l++;
        cin>>mp[l].u>>mp[l].v>>mp[l].w;
    }
    for(ll i=1;i<=k;i++)
    {
        cin>>t1;
        for(ll j=1;j<=n;j++)
        {
            cin>>t2;
            l++;
            mp[l].u=i;
            mp[l].v=j;
            mp[l].w=t1+t2;
        }
    }
    sort(mp+1,mp+l+1);
    for(ll i=1;i<=l;i++)
    {
        if(find(mp[i].u)!=find(mp[i].v))
        {
            ans+=mp[i].w;
            merge(mp[i].u,mp[i].v);
            //cerr<<mp[i].u<<' '<<mp[i].v<<' '<<mp[i].w<<endl;
        }
    }
    cout<<ans<<endl;
    cout<<flush;
    return 0;
}
