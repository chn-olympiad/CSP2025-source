#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int MOD=998244353;
int a[5141];
int sum[5141];
int dp[25000000][3][2];
void clean(int I,int J,int K)
{
    for(int i=0;i<=I;i++)
        for(int j=0;j<=J;j++)
            dp[i][j][K]=0;
}
int add(int a,int b)
{
    LL c=a%MOD;
    c=c+b%MOD;
    c=c%MOD;
    return int(c%2147483647);
}
int g(int a,int b)
{
    LL c=a%MOD;
    c=c*(b%MOD);
    c=c%MOD;
    return int(c%2147483647);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1,x;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1,x;i<=n;++i)
    {
        sum[i]=sum[i-1]+a[i];
    }
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        clean(sum[i-2],2,i%2);
        for(int j=0;j<=sum[i-1];j++)
        {
            //cout<<'('<<dp[j][0][(i-1)%2]<<','<<dp[j][1][(i-1)%2]<<','<<dp[j][2][(i-1)%2]<<')';
            if(j>a[i])
            {
                ans=add(ans,dp[j][2][(i-1)%2]);
                //cout<<':'<<dp[j][2][(i-1)%2]<<' ';
            }
            dp[j+a[i]][1][i%2]=add(dp[j+a[i]][1][i%2],dp[j][0][(i-1)%2]);
            dp[j+a[i]][2][i%2]=add(dp[j+a[i]][2][i%2],dp[j][1][(i-1)%2]);
            dp[j+a[i]][2][i%2]=add(dp[j+a[i]][2][i%2],dp[j][2][(i-1)%2]);
            dp[j][0][i%2]=add(dp[j][0][i%2],dp[j][0][(i-1)%2]);
            dp[j][1][i%2]=add(dp[j][1][i%2],dp[j][1][(i-1)%2]);
            dp[j][2][i%2]=add(dp[j][2][i%2],dp[j][2][(i-1)%2]);
        }
        //cout<<endl;
    }
    cout<<ans;
    return 0;
}
/*
*/
