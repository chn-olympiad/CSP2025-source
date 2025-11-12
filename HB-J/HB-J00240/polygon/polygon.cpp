#include <iostream>
#include <cstdio>
using namespace std;
long long n,a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    if(n<3)
    {
        printf("%d",0);
    }
    else if(n==3)
    {
        if(a[1]+a[2]>a[3])
        {
            printf("%d",1);
        }
        else
        {
            printf("%d",0);
        }
    }
    else
    {
        long long num=1,num1=1,ans=0;
        for(long long i=3;i<=n;i++)
        {
            for(long long j=n;j>=n-i+1;j--)
            {
                num*=j;
                num%=998244353;
            }
            for(long long k=i;k>=1;k--)
            {
                num1*=k;
                num1%=998244353;
            }
            ans+=num/num1;
            ans%=998244353;
        }
        printf("%lld",ans);
    }
    return 0;
}
