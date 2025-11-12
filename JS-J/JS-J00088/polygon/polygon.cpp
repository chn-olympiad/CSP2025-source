#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],jl[5005],f[5005],ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
    {
        int ls=0;
        for(int j=a[i]+1;j<=5000;++j) ls=(ls+jl[j])%mod;
        f[i]=(ls+jl[5001])%mod;
        for(int j=5001;j>=1;--j)
        {
            if(j+a[i]>5000) jl[5001]=(jl[5001]+jl[j])%mod;
            else jl[j+a[i]]=(jl[j+a[i]]+jl[j])%mod;
        }
        jl[a[i]]=(jl[a[i]]+1)%mod;
    }
    for(int i=3;i<=n;++i) ans=(ans+f[i])%mod;
    cout<<ans%mod;
    return 0;
}