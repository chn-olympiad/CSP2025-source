#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    long long k;
    cin>>n>>k;
    vector<long long> a(n+1);
    bool isA=true;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) isA=false;
    }
    if(isA&&k==0) cout<<n/2;
    else
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        dp[0][0]=0;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int chose=0;
            int notChose=0;
            for(int j=1;j<=i;j++)
            {
                bool ok=true;
                int tmp=a[j];
                for(int p=j+1;p<=i;p++)
                {
                    tmp^=a[p];
                }
                if(tmp!=k) ok=false;
                if(ok)
                {
                    dp[i][j]=1;
                    for(int k=1;k<=j-1;k++)
                    {
                        chose=max(chose,dp[j-1][k]);
                        notChose=max(notChose,dp[j][k]);
                    }
                    dp[i][j]=max(notChose,chose+1);
                }
                ans=max(ans,dp[i][j]);
            }
        }
        cout<<ans;
    }
    return 0;
}
