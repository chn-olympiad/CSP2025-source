#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+5;
const ll M=1e4+5;
ll n,m,k;
ll cost[11];
ll a[N];
ll s,e,c;
ll ans;
ll road[M][M];
map<ll,ll>pointroad;
ll findmin(ll i)
{
    ll x=0x3f3f3f3f;
    for(int j=1;j<=n;j++)
        if(j!=i)
            x=min(x,road[i][j]);
    return x;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(road,0x3f3f3f,sizeof(road));
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld",&s,&e,&c);
        road[s][e]=road[e][s]=c;
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%lld",&cost[i]);
        for(int j=1;j<=n;j++)
        {
            scanf("%lld",&a[j]);
            if(a[j]==0)
                pointroad[j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {

        if(!pointroad[i])
            ans+=findmin(i);

    }
    printf("%lld",ans);
    return 0;
}
