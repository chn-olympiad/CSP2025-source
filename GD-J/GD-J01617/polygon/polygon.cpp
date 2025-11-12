#include<bits/stdc++.h>
using namespace std;
#define int    long long
const int mod=998244353;
//const int mod=1e18;
int n;
int a[10005];
int mem[1005][105];
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
//    cout<<mod<<endl;
    cin>>n;
    int debug_mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        debug_mx=max(debug_mx,a[i]);
    }
    if(debug_mx==1)
    {
        int fact[10005];
        fact[0]=fact[1]=1;
        for(int i=2;i<=n;i++)
        {
            fact[i]=(1ll*fact[i-1]*i)%mod;
        }
        int ans=0;
        for(int i=3;i<=n;i++)
        {
            ans=(ans+1ll*(fact[n]/(fact[n-i]*fact[i]))%mod)%mod;
        }
        cout<<ans<<endl;
        return 0;
    }
    int ans=0;
    for(int i=0;i<(1<<n);i++)
    {
        int cnt=0;
        int mx=0,sum=0;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                cnt++;
                mx=max(mx,a[j+1]);
                sum+=a[j+1];
            }
        }
        if(cnt<3)continue;
        if(sum<=mx*2)continue;
        ans++;
        while(ans>=mod)ans-=mod;
    }
    cout<<ans<<endl;
}
