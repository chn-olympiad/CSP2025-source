#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ll n;
    cin>>n;
    ll a[5005];
    ll ans=0;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=3;i++)
    {
        for(ll j=1;j<=n;j++)if(a[j]+a[j+1]>max(a[j],a[j+1]))ans++;
    }
    for(ll i=1;i<=4;i++)
    {
        for(ll j=1;j<=n;j++)if(a[j]+a[j+1]>max(a[j],a[j+1]))ans++;
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)if(a[j]+a[j+1]>max(a[j],a[j+1]))ans++;
    }
    cout<<ans%998244353;
    return 0;
}
