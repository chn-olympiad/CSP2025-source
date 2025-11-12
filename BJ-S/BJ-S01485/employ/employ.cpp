#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN = 505;
int n, m;
string s;
int c[MAXN];
long long dp[MAXN][MAXN][MAXN];
long long fact[MAXN];
int cnt_c_le[MAXN];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=0;i<n;i++)cin>>c[i];
    int cnt1=count(s.begin(),s.end(),'1');
    if(cnt1<m)
    {
        cout<<0<<endl;
        return 0;
    }
    fact[0]=1;
    for (int i=1;i<=n;i++)fact[i]=fact[i-1]*i%MOD;
    for (int j=0;j<=n;j++)
    {
        cnt_c_le[j]=0;
        for (int x=0;x<n;x++)if(c[x]<=j)cnt_c_le[j]++;
    }
    dp[0][0][0]=1;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<=i;j++)
        {
            for (int k=0;k<=i-j;k++)
            {
                if(dp[i][j][k]==0)continue;
                int remaining=n-i;
                if(remaining<=0)continue;
                int rejected=(i-j)-k;
                int used_not_give_up=k+rejected;
                int used_give_up=i-used_not_give_up;
                int give_up=max(0,cnt_c_le[j]-used_give_up);
                if (give_up>0)
                {
                    dp[i+1][j+1][k]=(dp[i+1][j+1][k]+dp[i][j][k]*give_up)%MOD;
                }
                int not_give_up=remaining-give_up;
                if (not_give_up>0)
                {
                    if (s[i]=='1')
                    {
                        dp[i+1][j][k+1]=(dp[i+1][j][k+1]+dp[i][j][k]*not_give_up)%MOD;
                    }
                    else
                    {
                        dp[i+1][j+1][k]=(dp[i+1][j+1][k]+dp[i][j][k]*not_give_up)%MOD;
                    }
                }
            }
        }
    }
    long long bad=0;
    for (int j=0;j<=n;j++)
    {
        for (int k=0;k<m;k++)
        {
            bad=(bad+dp[n][j][k])%MOD;
        }
    }
    long long ans=(fact[n]-bad+MOD)%MOD;
    cout<<ans<<endl;
    return 0;
}