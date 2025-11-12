#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans=0;
ll a[5009];
ll stick[5009];
ll bj[5009];
void answer(ll x,ll k,ll j)
{
    if(x>k)
    {
        ll cnt=0,MAX=LONG_LONG_MIN;
        for(ll i=1;i<=k;i++)
        {
            cnt+=stick[i];
            MAX=max(MAX,stick[i]);
        }
        if((2*MAX)<cnt)
            ans++;
        return;
    }
    for(ll i=j+1;i<=n;i++)
    {
        stick[x]=a[i];
        answer(x+1,k,i);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(ll i=3;i<=n;i++)
        answer(1,i,0);
    cout<<ans;
    return 0;
}
