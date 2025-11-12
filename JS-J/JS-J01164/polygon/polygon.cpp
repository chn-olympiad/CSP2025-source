#include<bits/stdc++.h>
using namespace std;
# define mod1 998244353
long long n,ans,a[1001],t,maxn,s=0,a1;
void dfs(long long num)
{
    if(num==n+1)
    {
        if(t>maxn*2&&s>=3)
        {
            ans=(ans+1)%mod1;
        }
    }
    else
    {
        long long n1=maxn;
        maxn=max(a[num],maxn);
        s++;
        t+=a[num];
        dfs(num+1);
        t-=a[num];
        s--;
        maxn=n1;
        dfs(num+1);
    }
}
int jc(long long num)
{
    long long s=1;
    for(long long i=2;i<=num;i++)
    s=(s*i)%mod1;
    return s;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        a1=max(a1,a[i]);
    }
    if(a1!=1)
    {
        dfs(1);
        cout<<ans%mod1;
    }
    else
    {
        for(long long i=3;i<=n;i++)
        {
            long long k=(jc(n)/(jc(i)*jc(n-i)))%mod1;
           ans=(ans+k)%mod1;
        }
        cout<<ans%mod1;
    }
}
