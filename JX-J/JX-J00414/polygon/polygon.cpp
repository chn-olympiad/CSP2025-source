#include<bits/stdc++.h>
using namespace std;
int a[5005];
const long long MOD=998244353;
long long calc(int n)
{
    if(n==0)return 1;
    long long ret=1;
    for(int i=2;i<=n;i++)
    {
        ret=(ret*i)%MOD;
    }
    return ret;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    bool f=1;
    int n;
    long long ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]!=1)f=0;
    }
    if(n<3)
    {
        printf("0");
        return 0;
    }
    else if(n==3)
    {
        if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))printf("1");
        else printf("0");
        return 0;
    }

    if(f)
    {
        for(int i=3;i<=n;i++)
        {
            ans=(ans+calc(n)/calc(i)/calc(n-i))%MOD;
        }
        printf("%lld",ans);
        return 0;
    }
    printf("0");
    return 0;
}
