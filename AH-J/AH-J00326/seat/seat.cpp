#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[105][105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    ll ans=1;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)cin>>a[i][j];
    }
    ll sum=a[1][1];
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(sum<a[i][j])ans++;
        }
    }

    if(n/ans==0)cout<<n/ans+n<<" ";
    else cout<<n/ans<<" ";
    if(ans%n==0)cout<<ans-ans%n;
    else
    {
        if(ans%n==0)cout<<ans%n;
        else cout<<ans%n;
    }
    return 0;
}
