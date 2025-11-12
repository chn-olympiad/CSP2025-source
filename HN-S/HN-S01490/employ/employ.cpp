#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=110;
const int mod=998244353;
int n,m,c[N],t[N],g[N][N][N][2],dp[N][N][N][2],f[N][N][N][2],qz[N],C[N][N],num0,num1;
string s;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0')
        num0++;
        else
        num1++;
        cin>>c[i];
        t[c[i]]++;
    }
    qz[0]=1;
    for(int i=1;i<=N-5;i++)
    {
        qz[i]=qz[i-1]*i;
        qz[i]%=mod;
    }
    for(int i=0;i<=N-5;i++)
    {
        C[i][0]=1;
    }
    for(int i=1;i<=N-5;i++)
    {
        for(int j=1;j<=N-5;j++)
        {
            C[i][j]=C[i-1][j]+C[i-1][j-1];
            C[i][j]%=mod;
        }
    }
    dp[0][0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=num1;j++)
        {
            for(int k=0;k<=num1;k++)
            {
                for(int l=0;l<=num1;l++)
                {
                    g[j][k][l][0]=dp[j][k][l][0];
                    g[j][k][l][1]=dp[j][k][l][1];
                    dp[j][k][l][0]=dp[j][k][l][1]=0;
                }
            }
        }
        for(int j=0;j<=num1;j++)
        {
            for(int k=0;k<=num1;k++)
            {
                for(int l=0;l<=num1;l++)
                {
                    dp[j][k][l][1]+=g[j][k][l][1];
                    dp[j][k][l][1]%=mod;
                }
            }
        }
        for(int j=0;j<=min(i-1,num1);j++)
        {
            int us=i-1-j;
            for(int k=0;k<=num1;k++)
            {
                for(int f=0;f<=num1;f++)
                {
                    for(int l=0;l<=t[us];l++)
                    {
                        if(k+l>num1)
                        break;
                        for(int l2=0;l2<=min(t[us]-l,f);l2++)
                        {
                            if(f+l2>num1)
                            break;
                            dp[j][k+l][f-l2][1]+=g[j][k][f][0]*C[t[us]][l]%mod*C[t[us]-l][l2]%mod*C[f][l2]%mod*qz[l2]%mod;
                            dp[j][k+l][f-l2][1]%=mod;
                        }
                    }
                }
            }
        }
        if(s[i]=='1')
        {
            for(int j=0;j<=min(num1,i);j++)
            {
                for(int k=0;k<=num1;k++)
                {
                    for(int l=0;l<=num1;l++)
                    {
                        f[j][k][l][0]=f[j][k][l][1]=0;
                    }
                }
            }
            for(int j=0;j<=min(num1,i);j++)
            {
                for(int l=1;l<=num1;l++)
                {
                    for(int k=0;k<=num1;k++)
                    {
                        f[j][l-1][k][0]+=dp[j][l][k][1]*l;
                        f[j][l-1][k][0]%=mod;
                    }
                }
            }//1'
            for(int j=0;j<=min(num1,i);j++)
            {
                for(int l=0;l<=num1;l++)
                {
                    for(int k=0;k<=num1;k++)
                    {
                        f[j+1][l][k+1][1]+=dp[j][l][k][1];
                        f[j+1][l][k+1][1]%=mod;
                    }
                }
            }//1
            for(int j=0;j<=min(num1,i);j++)
            {
                for(int k=0;k<=num1;k++)
                {
                    for(int l=0;l<=num1;l++)
                    {
                        dp[j][k][l][0]=f[j][k][l][0];
                        dp[j][k][l][1]=f[j][k][l][1];
                    }
                }
            }
        }
        else
        {
            for(int j=0;j<=min(num1,i);j++)
            {
                for(int l=0;l<=num1;l++)
                {
                    for(int k=0;k<=num1;k++)
                    {
                        dp[j][l][k][0]+=dp[j][l][k][1];
                        dp[j][l][k][1]=0;
                        dp[j][l][k][0]%=mod;
                    }
                }
            }
        }
    }
    for(int i=n;i>=1;i--)
    {
        t[i]+=t[i+1];
    }
    int ans=0;
    for(int i=m;i<=n;i++)
    {
        for(int k=0;k<=n;k++)
        {
            ans+=dp[i][0][k][0]*C[t[n-i]][k]*qz[k]%mod;
            ans%=mod;
            ans+=dp[i][0][k][1]*C[t[n-i+1]][k]*qz[k]%mod;
            ans%=mod;
        }
    }
    ans*=qz[num0];
    ans%=mod;
    cout<<ans<<'\n';
    return 0;
}