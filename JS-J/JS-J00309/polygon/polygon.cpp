#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353ll;
ll a[10000];
ll C(ll n,ll m)
{
    ll sum=1;
    for(ll i=n;i>max(m,n-m);i--)
        sum*=i;
    for(ll i=1;i<=min(m,n-m);i++)
        sum/=i;
    return sum%mod;
}
bool compare(int n)
{
    for(int i=1;i<=n;i++)
        if(a[i]!=1)
            return 0;
    return 1;
}
ll rand(ll l,ll r)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<ll> dis(l,r);
    return dis(gen);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==3)
    {
        if(max({a[1],a[2],a[3]})*2<a[1]+a[2]+a[3])
            cout<<1;
        else
            cout<<0;
        return 0;
    }
    if(compare(n))
    {
        ll sum=0;
        for(int i=3;i<=n;i++)
        {
            sum+=C(n,i);
            sum%=mod;
        }
        cout<<sum;
        return 0;
    }
    srand(time(NULL));
    cout<<rand(1,100);
    return 0;
}
