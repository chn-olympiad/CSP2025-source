#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
priority_queue< pii,vector< pii >,greater< pii > > q[5];
const ll N=1e5;
ll t,n,a[N+5][5],cnt[5],ans;
ll cal(ll p)
{
    ll xx=max(max(a[p][1],a[p][2]),a[p][3]);
    if(xx==a[p][1])
        return a[p][1]-max(a[p][2],a[p][3]);
    else if(xx==a[p][2])
        return a[p][2]-max(a[p][1],a[p][3]);
    else return a[p][3]-max(a[p][1],a[p][2]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--)
    {
        ans=0;
        for(int i=1;i<=3;i++)
        {
            cnt[i]=0;
            while(!q[i].empty()) q[i].pop();
        }
        scanf("%lld",&n);
        for(ll i=1;i<=n;i++)
            scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
        for(ll i=1;i<=n;i++)
        {
            ll t=max(max(a[i][1],a[i][2]),a[i][3]);
            for(int j=1;j<=3;j++)
                if(a[i][j]==t)
                {
                    q[j].push({cal(i),i})
                    ,cnt[j]++,ans+=a[i][j];
                    break;
                }
        }
        for(int j=1;j<=3;j++)
        {
           // cout<<"*"<<cnt[j]<<endl;
            while(cnt[j]>n/2)
            {
                pii x=q[j].top();
                q[j].pop();cnt[j]--;
                ans-=x.first;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
