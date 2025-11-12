#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005],num[10005],ans[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,mx=-1e9;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        mx=max(mx,a[i]);
    }
    sort(a+1,a+n+1);
    num[a[1]+a[2]]=1;
    for(int i=3;i<=n;i++)
    {
        for(int j=a[i]+1;j<=2*mx+1;j++)
            ans[i]=(ans[i]+num[j])%mod;
        num[2*mx+1]=(2*num[2*mx+1])%mod;
        for(int j=2*mx;j+a[i]>2*mx;j--)
             num[2*mx+1]=(num[2*mx+1]+num[j])%mod;
        for(int j=2*mx;j>=a[i];j--)
            num[j]=(num[j]+num[j-a[i]])%mod;
        for(int j=1;j<i;j++)
            num[a[i]+a[j]]=(num[a[i]+a[j]]+1)%mod;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
        sum=(sum+ans[i])%mod;
    printf("%d\n",sum);
    return 0;
}
