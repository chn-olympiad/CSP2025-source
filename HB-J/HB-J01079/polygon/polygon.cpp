#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005],ans,sum,n;
void dfs(int x,int num,int maxn)
{
    if(!num)
    {
        if(sum>2*maxn)
            ans++;
        ans%=998244353;
        return ;
    }
    for(int i=x;i<=n;i++)
    {
        sum+=a[i];
        dfs(i+1,num-1,max(maxn,a[i]));
        sum-=a[i];
    }
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    int z=0,flag=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]>1)
            flag=1;
        if(a[i]==1)
            z++;
    }
    if(!flag)
    {
        for(int i=3;i<=n;i++)
            ans+=(1+(z-i+1))*(z-i)/2;
        printf("%lld",ans);
        return 0;
    }
    for(int i=3;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            sum=a[j];
            dfs(j+1,i-1,a[j]);
        }
    }
    printf("%lld",ans);
    return 0;
}
