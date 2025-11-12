#include<bits/stdc++.h>
using namespace std;
int dp[10005];
int qw[1005][1005];
int a,b,c,n,m;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>dp[i];
    }
    a=dp[1];
    sort(dp+1,dp+n*m+1);
    int k=n*m+1;
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                qw[j][i]=dp[--k];
            }
        }
        else if(i%2==0)
        {
            for(int j=n;j>=1;j--)
                qw[j][i]=dp[--k];
        }
    }
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=m;j++)
        {
            if(a==qw[i][j])
            {
                cout<<j<<' '<<i<<endl;
                return 0;
            }
        }
    }
    return 0;
}
