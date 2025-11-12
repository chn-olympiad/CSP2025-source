#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010,mod=998244353;
int n,a[N];
ll ans;
int f[N];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    f[0]=1;
    ll sum=0,mul=1;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+mul)%mod;
        for(int j=0;j<=a[i];j++)ans=((ans-f[j])%mod+mod)%mod;
        mul=mul*2%mod;
        sum+=a[i];
        for(int j=min(sum,(ll)a[n]);j>=a[i];j--)
            f[j]=(f[j]+f[j-a[i]])%mod;
    }
    cout<<ans<<"\n";
    return 0;
}
