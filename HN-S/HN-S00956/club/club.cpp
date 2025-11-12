#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define all(v) v.begin(),v.end()
#define pb push_back
#define ppb pop_back
using namespace std;
const ll N=1e5+5;
ll n,p1[N],a[N][3];
vector<ll> c[3];
void solve()
{
    for(ll i=0;i<3;i++)
        c[i].clear();
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        ll p=0;
        for(ll j=0;j<3;j++)
        {
            cin>>a[i][j];
            if(a[i][j]>a[i][p])
                p=j;
        }
        p1[i]=!p?1:0;
        for(ll j=0;j<3;j++)
            if(j^p&&a[i][j]>a[i][p1[i]])
                p1[i]=j;
        c[p].pb(i);
    }
    for(ll i=0;i<3;i++)
    {
        if(c[i].size()*2<=n) continue;
        sort(all(c[i]),[&](ll x,ll y){return a[x][p1[x]]-a[x][i]<a[y][p1[y]]-a[y][i];});
        while(c[i].size()*2>n)
        {
            ll x=c[i].back();
            c[i].ppb(),c[p1[x]].pb(x);
        }
        break;
    }
    for(ll i=0;i<3;i++)
        assert(c[i].size()*2<=n);
    ll ans=0;
    for(ll i=0;i<3;i++)
        for(auto j:c[i])
            ans+=a[j][i];
    cout<<ans<<'\n';
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin>>T;
    while(T--) solve();
    return 0;
}