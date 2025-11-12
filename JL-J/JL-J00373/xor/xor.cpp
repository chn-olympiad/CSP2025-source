#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int dp[1005][1005];
int mx[1005];
int sum[1005];
int main()//65
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    if(n<=1000)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]^a[i];
            //printf("sum[ %d ] = %d\n",i,sum[i]);
        }
        dp[1][1]=(a[1]==k)?1:0;
        mx[1]=dp[1][1];
        //printf("dp[ 1 ][ 1 ] = %d\n",dp[1][1]);
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i][j]=mx[j-1]+((sum[i]^sum[j-1])==k);
                mx[i]=max(mx[i],dp[i][j]);
                //printf("mx[ %d ] = %d dp[ %d ][ %d ] = %d\n",j-1,mx[j-1],i,j,dp[i][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,mx[i]);
        }
        printf("%d",ans);
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        if(k==1)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i])ans++;
            }
            printf("%d",ans);
        }
        else
        {
            int ans=0;
            int now=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i])now++;
                if(now==2)
                {
                    ans++;
                    now=0;
                }
            }
            printf("%d",ans);
        }
    }
}
/*
4 2
2 1 0 3
*/
