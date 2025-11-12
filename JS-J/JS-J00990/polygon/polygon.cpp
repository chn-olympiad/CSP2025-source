#include<bits/stdc++.h>
using namespace std;
int n,a[5005],dp[2][50005],pre[2][50005],jq;
int main()
{
    //long long file memory
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dp[0][0]=1;
    pre[0][0]=1;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        pre[0][0]=1;
        for(int j=1;j<=50000;j++)
        {
            jq=j-a[i];
            if(jq>=0)
            {
                dp[1][j]=pre[0][jq];
            }
            else
            {
                dp[1][j]=0;
            }
            pre[1][j]=pre[0][j]+dp[1][j];
            dp[1][j]%=998244353;
            pre[1][j]%=998244353;
            //if(j<20)
            //{
            //    cerr<<dp[1][j]<<' ';
            //}
            if(j>=a[i]*2+1)
            {
                ans+=dp[1][j];
            }
        }
        for(int j=0;j<=50000;j++)
        {
            dp[0][j]=dp[1][j];
            pre[0][j]=pre[1][j];
        }
        ans%=998244353;
        //cerr<<endl;
    }
    cout<<ans;
    return 0;
}
