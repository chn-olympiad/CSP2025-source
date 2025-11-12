#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005];
int dp[100005][2];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=a[i]+1;j<=sum;j++)
        {
            ans+=dp[j][1];
            ans%=mod;
        }
        for(int j=sum;j>=a[i];j--)
        {
            dp[j][1]+=dp[j-a[i]][0];
            dp[j][1]%=mod;
            dp[j][1]+=dp[j-a[i]][1];
            dp[j][1]%=mod;
        }
        dp[a[i]][0]++;
        dp[a[i]][0]%=mod;
    }
    printf("%d",ans);
    return 0;
}
