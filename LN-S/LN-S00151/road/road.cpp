#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mk make_pair
#define pii pair<ll,ll>
const ll N=1e6+10;
ll w[N],v[N],u[N],c[100],d[N];
ll n,m,k,fa[N],ans;
priority_queue<pii,vector<pii>,greater<pii>>q;
inline ll find(ll x)
{
    if(fa[x]==x)
    {
        return x;
    }
    else
    {
        fa[x]=find(fa[x]);
        return fa[x];
    }
}
inline bool ck(ll x,ll y)
{
    if(find(x)==find(y))return false;
    return true;
}
inline void he(ll x,ll y)
{
    fa[find(x)]=find(y);
}
inline void kruskal()
{
    for(int i=1;i<=m;i++)
    {
        q.push(mk(w[i],i));
    }
    n--;
    while(n--)
    {
        ll c=q.top().second;
        if(ck(v[c],u[c]));
        {
            he(v[c],u[c]);
            ans+=q.top().first;
        }
        q.pop();
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    cin>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int i=1;i<=n;i++)
        {
            cin>>d[i];
        }
    }
    kruskal();
    cout<<ans;
}