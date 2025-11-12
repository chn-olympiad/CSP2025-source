#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=5005;
long long n,a[N],ans,f[N*N],k,cnt,top,fl=1;
int b[N*N];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)fl=0;
    }
    if(fl)
    {
        for(int i=3;i<=n;i++)
        {
            long long h=(long long)(pow(2,i-1)-i)%mod;
            ans=(ans+h)%mod;
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    b[0]=1;
    for(int i=1;i<=n;i++)
    {
        if(i>=3)
        {
            long long sum=0;
            for(int j=a[i];j>=1;j--)
            {
                sum+=b[j];
            }
            ans=(ans+(cnt-sum+mod)%mod)%mod;
        }
        cnt=(long long)pow(2,i)-1;
        for(int j=50000;j>=0;j--)
        {
            b[j+a[i]]+=b[j];
        }
    }
    cout<<ans;
    return 0;
}
