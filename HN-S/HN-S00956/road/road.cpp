#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define all(v) v.begin(),v.end()
#define pb push_back
#define ppb pop_back
using namespace std;
const ll N=1e4+5,M=2e6+5,K=15;
ll n,m,tot,fa[N],a[K][N];
ll find(ll x){return x==fa[x]?x:fa[x]=find(fa[x]);}
struct edge
{
    ll x,y,z;
    bool operator<(const edge o)const{return z<o.z;}
}e[M],e1[M],e2[N*K];
void solveA()
{
    for(ll i=1;i<=m;i++)
        e[i]=e1[i];
    for(ll i=1;i<=tot;i++)
        for(ll j=1;j<=n;j++)
            e[++m]={n+i,j,a[i][j]};
    sort(e+1,e+m+1);
    for(ll i=1;i<=n+tot;i++)
        fa[i]=i;
    ll ans=0;
    for(ll i=1;i<=m;i++)
    {
        ll x=find(e[i].x),y=find(e[i].y);
        if(x^y) fa[y]=x,ans+=e[i].z;
    }
    cout<<ans<<'\n';
}
void force()
{
    ll m1=m;m=0;
    for(ll i=1;i<=m1;i++)
        cin>>e1[i].x>>e1[i].y>>e1[i].z;
    sort(e1+1,e1+m1+1);
    for(ll i=1;i<=tot;i++)
    {
        for(ll j=0;j<=n;j++)
            cin>>a[i][j];
    }
    ll ans=1e18;
    for(ll S=0;S<(1ll<<tot);S++)
    {
        ll p=0,sum=0,m2=0;m=0;
        for(ll i=1;i<=tot;i++)
        {
            if(S>>i-1&1^1) continue;
            sum+=a[i][0];
            for(ll j=1;j<=n;j++)
                e2[++m2]={n+i,j,a[i][j]};
        }
        sort(e2+1,e2+m2+1);
        for(ll i=1;i<=m2;i++)
        {
            while(p<m1&&e1[p+1].z<=e2[i].z)
                p++,e[++m]=e1[p];
            e[++m]=e2[i];
        }
        while(p<m1) p++,e[++m]=e1[p];
        for(ll i=1;i<=n+tot;i++)
            fa[i]=i;
        for(ll i=1;i<=m;i++)
        {
            ll x=find(e[i].x),y=find(e[i].y);
            if(x^y) fa[y]=x,sum+=e[i].z;
        }
        ans=min(ans,sum);
    }
    cout<<ans<<'\n';
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>tot;
    for(ll i=1;i<=m;i++)
        cin>>e1[i].x>>e1[i].y>>e1[i].z;
    sort(e1+1,e1+m+1);
    bool ck=1;
    for(ll i=1;i<=tot;i++)
    {
        for(ll j=0;j<=n;j++)
            cin>>a[i][j];
        bool ck1=!a[i][0],ck2=0;
        for(ll j=1;j<=n;j++)
            ck2|=!a[i][j];
        ck&=ck1&ck2;
    }
    if(ck) return solveA(),0;
    return force(),0;
}