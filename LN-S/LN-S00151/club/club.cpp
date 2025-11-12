#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define mk make_pair
const ll N=1e5+10;
ll T;
ll n,a[N][4],vis[N],ans;
vector<ll> v1,v2,v3;
priority_queue<pii> q;
ll b[N][4],c[N][4];
inline void deal(vector<ll> v,ll x)
{
    ll y,z;
    if(x==1)y=2,z=3;
    else if(x==2)y=1,z=3;
    else y=1,z=2;
    for(int i=0;i<v.size();i++)
    {
        ll k=v[i];
        q.push(mk(a[k][y]-a[k][x],k));
        q.push(mk(a[k][z]-a[k][x],k));
    }
    ll cnt=0;
    // cout<<v.size()-n/2<<"123";
    while(cnt<(v.size()-n/2))
    {
        auto u=q.top();
        q.pop();
        if(!vis[u.second])
        {
            vis[u.second]=1;
            ans+=u.first;
            cnt++;
        }
        // cout<<u.first;
    }
}
inline void init()
{
    v1.clear();
    v2.clear();
    v3.clear();
    ans=0;
    memset(a,0,sizeof(a));
    memset(vis,0,sizeof(vis));
    while(!q.empty())q.pop();
}
inline void solve()
{
    init();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][1])
        {
            v1.push_back(i);
            ans+=a[i][1];
        }
        else if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][2])
        {
            v2.push_back(i);
            ans+=a[i][2];
        }
        else
        {
            v3.push_back(i);
            ans+=a[i][3];
        }
    }
    if(v1.size()>(n/2))
    {
        deal(v1,1);
    }
    if(v2.size()>(n/2))
    {
        // cout<<232<<" ";
        deal(v2,2);
    }
    if(v3.size()>(n/2))
    {
        deal(v3,3);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>T;
    while(T--)
    {
        solve();
        cout<<ans<<"\n";
    }
    return 0;
}