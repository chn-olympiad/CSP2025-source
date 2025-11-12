#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,ans=0;
ll a[100009];
ll sum[100009]={0};
ll getxor(ll l,ll r)
{
    return sum[r]^sum[l-1];
}
void check(ll l,ll r)
{
    for(ll i=l;i<=r;i++)
        for(ll j=i;j<=r;j++)
            if(getxor(i,j)==k)
            {
                //cout<<i<<"-"<<j<<",";
                ans++;
                i=j;
                break;
            }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]^a[i];
        if(a[i]==k)
            ans++;
    }
    cout<<"\n";
    a[n+1]=LONG_LONG_MAX;
    ll m1=1,m2=0;
    for(ll i=1;i<=n+1;i++)
    {
        if(a[i]==k||i==n+1)
        {
            m2=i-1;
            check(m1,m2);
            m1=i+1;
        }
    }
    cout<<ans;
    return 0;
}
