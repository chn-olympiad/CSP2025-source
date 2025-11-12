#include<bits/stdc++.h>
using namespace std;
const long long N=5005,mod=998244353;
long long n,A[N],ans,f[N*N],sum;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>A[i],sum+=A[i];
    sum++;
    stable_sort(A+1,A+1+n);
    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=sum;j>A[i];j--)
            ans=(ans+f[j])%mod;
        for(int j=sum;j>=A[i];j--)
            f[j]=(f[j]+f[j-A[i]])%mod;
    }
    cout<<ans<<endl;
    return 0;
}
