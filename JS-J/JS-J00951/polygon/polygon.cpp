#include <bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n;
long long a[5010];
long long f[5010];
long long ans[5010];
void add(long long k,long long p)
{
    if (k<=5000)
    {
        f[k]+=p;
        f[k]%=MOD;
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    add(a[1]+a[2],1);
    for (int i=3;i<=n;i++)
    {
        ans[i]=1;
        for (int j=1;j<i;j++)
        {
            ans[i]*=2;
            ans[i]%=MOD;
        }
        ans[i]-=i;
        ans[i]+=MOD;
        ans[i]%=MOD;
        for (int j=a[i];j>=1;j--)
        {
            ans[i]-=f[j];
            ans[i]+=MOD;
            ans[i]%=MOD;
        }
        for (int j=5000;j>=1;j--)
        {
            if (f[j]>0)
            {
                add(a[i]+j,f[j]);
            }
        }
        for (int j=1;j<i;j++)
        {
            add(a[j]+a[i],1);
        }
    }
    long long sum=0;
    for (int i=1;i<=n;i++)
    {
        sum+=ans[i];
        sum%=MOD;
    }
    cout<<sum;
    return 0;
}
