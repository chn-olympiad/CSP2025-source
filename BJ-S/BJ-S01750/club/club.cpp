#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=100005;
ll a[N],b[N],c[N];
ll ans=0;
ll n;
ll visb[5];
bool vis[N];
struct st{
    ll y,d,bm,x;
}k[N*3];
bool cmp2(st xx,st yy)
{
    if(xx.d==yy.d)return xx.y>yy.y;
    return xx.d>yy.d;
}
void solve()
{
    ll cnt=0;
    for(ll i=1;i<=3;i++)visb[i]=0;
    for(ll i=1;i<=n;i++)
    {
        vis[i]=0;
        k[++cnt].x=i;
        k[cnt].bm=1;
        k[cnt].y=a[i];
        k[cnt].d=min(a[i]-b[i],a[i]-c[i]);
        k[++cnt].x=i;
        k[cnt].bm=2;
        k[cnt].y=b[i];
        k[cnt].d=min(b[i]-c[i],b[i]-a[i]);
        k[++cnt].x=i;
        k[cnt].bm=3;
        k[cnt].y=c[i];
        k[cnt].d=min(c[i]-a[i],c[i]-b[i]);
    }
    sort(k+1,k+n*3+1,cmp2);
    for(ll i=1;i<=3*n;i++)
    {
        if(!vis[k[i].x]&&visb[k[i].bm]<n/2)
        {
            vis[k[i].x]=1;
            visb[k[i].bm]++;
            ans+=k[i].y;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        solve();
    }
    return 0;
}


