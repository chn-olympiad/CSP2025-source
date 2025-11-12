#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,i;
    int ans=0;
    cin>>n;
    int a[n+1];
    int dp[n+1];
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=0;i<=n;i++)dp[i]=0;
    dp[n-1]=1;
    dp[n-2]=1;
    sort(a+1,a+n+1);
    while(dp[0]==0)
    {
        int j=n;
        while(dp[j]==1)
        {
            dp[j]=0;
            j=j-1;
        }
        dp[j]=1;
        int cnt=0;
        for(i=1;i<=n;i++)if(dp[i]==1)cnt=cnt+a[i];
        if(cnt>2*a[j])ans=ans+1;
    }
    cout<<ans%998244353;
    return 0;
}
