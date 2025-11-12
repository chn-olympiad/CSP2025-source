#include<bits/stdc++.h>
const int mod=998244353;
using namespace std;
int dp[1<<18][20],c[505],cnt2;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]==0) cnt2++;
    }
    if(n<=18)
    {
        dp[0][0]=1;
        for(int i=1;i<(1<<n);i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
                if(i&(1<<j)) cnt++;
            for(int j=0;j<n;j++)
            {
                if(!(i&(1<<j))) continue;
                int temp=c[j+1];
                for(int k=0;k<cnt;k++)
                {
                    if(cnt-k-1>=temp||s[cnt-1]=='0')
                    {
                        dp[i][k]+=dp[i-(1<<j)][k];
                        if(dp[i][k]>=mod) dp[i][k]-=mod;
                    }
                    else
                    {
                        dp[i][k+1]+=dp[i-(1<<j)][k];
                        if(dp[i][k+1]>=mod) dp[i][k+1]-=mod;
                    }
                }
            }
        }
        int ans=0;
        for(int i=m;i<=n;i++)
        {
            ans+=dp[(1<<n)-1][i];
            ans%=mod;
        }
        cout<<ans;
        return 0;
    }
    if(n-cnt2<m)
    {
        cout<<0;
        return 0;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                cout<<0;
                return 0;
            }
        }
        cout<<1;
    }
    return 0;
}
