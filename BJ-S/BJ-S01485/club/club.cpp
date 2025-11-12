#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN=20;
long long dp[MAXN+1][MAXN/2+1][MAXN/2+1];
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k=n/2;
        vector<vector<int>>a(n+1,vector<int>(3));
        for (int i=1;i<=n;++i)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        memset(dp,-0x3f,sizeof(dp));
        dp[0][0][0]=0;
        for (int i=0;i<n;++i)
        {
            for (int acnt=0;acnt<=min(i,k);++acnt)
            {
                for (int bcnt=0;bcnt<=min(i-acnt,k);++bcnt)
                {
                    int ccnt=i-acnt-bcnt;
                    if (ccnt > k)continue;
                    if (dp[i][acnt][bcnt]==-0x3f3f3f3f3f3f3f3f)continue;
                    if(acnt+1<=k)
                    {
                        dp[i+1][acnt+1][bcnt]=max(dp[i+1][acnt+1][bcnt],dp[i][acnt][bcnt]+a[i+1][0]);
                    }
                    if(bcnt+1<=k)
                    {
                        dp[i+1][acnt][bcnt+1]=max(dp[i+1][acnt][bcnt+1],dp[i][acnt][bcnt]+a[i+1][1]);
                    }
                    if(ccnt+1<=k)
                    {
                        dp[i+1][acnt][bcnt]=max(dp[i+1][acnt][bcnt],dp[i][acnt][bcnt]+a[i+1][2]);
                    }
                }
            }
        }
        long long ans=0;
        for (int acnt=0;acnt<=k;++acnt)
        {
            for (int bcnt=0;bcnt<=k;++bcnt)
            {
                int ccnt=n-acnt-bcnt;
                if (ccnt<=k)
                {
                    ans=max(ans,dp[n][acnt][bcnt]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}