#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
long long n,a[maxn],e[maxn],p=998244353,ans,max1,d[maxn],dd[maxn];
long long ksm(long long x,long long y)
{
    long long z=1;
    while(y)
    {
        if(y&1)z=z*x%p;
        x=x*x%p;
        y>>=1;
    }
    return z;
}
long long chu(long long x,long long y)
{
    return x*ksm(y,p-2)%p;
}
long long C(long long x,long long y)
{
    return chu(chu(e[y],e[y-x]),e[x]);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    e[0]=1;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        e[i]=e[i-1]*i%p;
        max1=max(max1,a[i]);
    }
    for(int i=3;i<=n;i++)ans=(ans+C(i,n))%p;
    for(int i=1;i<=n;i++)
    {
        for(int j=max1;j>=a[i];j--)
        {
            d[j]=(d[j]+dd[j-a[i]])%p;
            dd[j]=(dd[j]+dd[j-a[i]]+1)%p;
        }
    }
    for(int i=1;i<=n;i++)ans=(ans-d[a[i]]+p)%p;
    cout<<ans;
}