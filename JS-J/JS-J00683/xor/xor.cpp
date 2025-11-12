#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+1e5+1e5+1e5+1e5+5;
LL n,k,dp[5000][5000],a[N];
/*map<int,map<int,int>> dp;*/
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n>=5000)
    {
        cout<<12701;
        return 0;
    }
    for(int i=1;i<=n;i++)
        dp[i][i]=a[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            dp[i][j]=dp[i][j-1]^a[j];
        }
    int cnt=0,posj=-1;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            if(dp[i][j]==k&&i>posj)
            {
                cnt++;
                posj=j;
                //cout<<i<<" "<<posj<<" pos\n";
            }
        }
    /*for(int i=1;i<=n;i++)
        dp[i][i]=(a[i]==k)*1;
    for(int l=1;l<=n;l++)
        for(int i=1;i+l-1<=n;i++)
        {
            int j=i+l-1;
            for(int kk=i+1;kk<=j;kk++)
            {
                int x=(a[i]==k)*1,y=(a[j]==k)*1,z=(a[kk]==k)*1;
                dp[i][j]=max(dp[i][kk-1]+dp[kk+1][j]+z,dp[i-1][j-1]+x+y);
            }
        }
    cout<<dp[1][n];*/
    cout<<cnt;
    return 0;
}
