#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5005,mod=998244353;
int n,a[N];
ll ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    sum[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=3;i<=n;i++)
    {
        ll sum=1;
        for(int j=1;j<=i;j++)
        {
            sum*=j;
            sum%=mod;
        }
        ans+=sum;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
