#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[5005];
int mod=998244353;
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,ans=0,mx=-1e9;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    sort(a+1,a+n+1);
    if(n<=2)
    {
        cout<<0;
        return 0;
    }
    if(mx==1 && n>=20)
    {
        int res=1,num=1;
        for(int i=1;i<=n;i++)
        {
            res=(res*(n-i+1))%mod;
            num=(i*num)%mod;
            if(i>=3)
                ans=(ans+res/num)%mod;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<(1<<n);i++)
    {
        int x=i,last,sum=0;
        for(int j=1;j<=n;j++)
        {
            if(x&1)
            {
                last=j;
                sum+=a[j];
            }
            x>>=1;
        }
        if(sum>a[last]*2)
            ans=(ans+1ll)%mod;
    }
    cout<<ans;
}
