#include<bits/stdc++.h>
using namespace std;
int l;
int i,j,p;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    cin>>n;
    int k;
    cin>>k;
     int dp[n][n][8];
    for( i=0;i<n;i++)
    {
        cin>>l;
        for( j=1;j<=8;j++)
        {
            dp[i][i][8-j]=l%2;
            l/=2;
        }
    }
    for( i=0;i<n-1;i++)
    {
        for( j=i+1;j<n;j++)
        {
            for( p=0;p<8;p++)
            {
                if(dp[i][j-1][p]==dp[j][j][p])
                {
                    dp[i][j][p]=0;
                }
                else
                {
                    dp[i][j][p]=1;
                }
            }
        }
    }
    int dp1[n][n];
    for( i=0;i<n;i++)
    {
        for( j=i;j<n;j++)
        {
            dp1[i][j]=dp[i][j][0]*128+dp[i][j][1]*64+dp[i][j][2]*32+dp[i][j][3]*16+dp[i][j][4]*8+dp[i][j][5]*4+dp[i][j][6]*2+dp[i][j][7];
        }
    }
    for( i=0;i<n;i++)
    {
        for( j=i;j<n;j++)
        {
           if(dp1[i][j]==k)
           {
               dp1[i][j]=1;
           }
           else
           {
               dp1[i][j]=0;
           }
        }
    }
    for( i=0;i<n-1;i++)
    {

            dp1[i][i+1]=max(dp1[i+1][i+1]+dp1[i][i],dp1[i][i]);

    }
    for( p=2;p<n;p++)
    {
        for( i=0;i<n-p;i++)
        {
            dp1[i][i+p]=max(dp1[i+1][i+p]+dp1[i][i+p-1]-dp1[i+1][i+p-1],dp1[i][i+p]);
        }
    }
    cout<<dp1[0][n-1];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
