#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,a[100005][3],ans,cnt0,cnt1,cnt2,x[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--)
    {
        ans=cnt0=cnt1=cnt2=0;
        cin>>n;
        for(ll i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
        for(ll i=1;i<=n;i++)
        {
            ll now=max(a[i][0],max(a[i][1],a[i][2]));
            ans+=now;
            if(now==a[i][0]) cnt0++;
            else if(now==a[i][1]) cnt1++;
            else cnt2++;
        }
        if(cnt0>(n>>1))
        {
            for(ll i=1;i<=n;i++)
            {
                ll now=max(a[i][0],max(a[i][1],a[i][2]));
                if(now!=a[i][0]) x[i]=1e9;
                else x[i]=a[i][0]-max(a[i][1],a[i][2]);
            }
            sort(x+1,x+n+1);
            for(ll i=1;i<=cnt0-(n>>1);i++) ans-=x[i];
        }
        if(cnt1>(n>>1))
        {
            for(ll i=1;i<=n;i++)
            {
                ll now=max(a[i][0],max(a[i][1],a[i][2]));
                if(now!=a[i][1]) x[i]=1e9;
                else x[i]=a[i][1]-max(a[i][0],a[i][2]);
            }
            sort(x+1,x+n+1);
            for(ll i=1;i<=cnt1-(n>>1);i++) ans-=x[i];
        }
        if(cnt2>(n>>1))
        {
            for(ll i=1;i<=n;i++)
            {
                ll now=max(a[i][0],max(a[i][1],a[i][2]));
                if(now!=a[i][2]) x[i]=1e9;
                else x[i]=a[i][2]-max(a[i][0],a[i][1]);
            }
            sort(x+1,x+n+1);
            for(ll i=1;i<=cnt2-(n>>1);i++) ans-=x[i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}
