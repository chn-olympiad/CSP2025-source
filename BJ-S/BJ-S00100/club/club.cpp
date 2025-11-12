#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=105;
int n,ans,a[N][4],b[N],dp[M][M];
bool ssA;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        ssA=1;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
            if(a[i][2]||a[i][3])
            {
                ssA=0;
            }
        }
        ans=0;
        if(n<=200)
        {
            for(int i=1;i<=n;i++)
            {
                int w[M][M]={};
                for(int j=0;j<=i&&j<=n/2;j++)
                {
                    for(int k=0;j+k<=i&&k<=n/2;k++)
                    {
                        if(i-j-k>n/2)
                        {
                            continue;
                        }
                        if(j!=0)
                        {
                            w[j][k]=max(w[j][k],dp[j-1][k]+a[i][1]);
                        }
                        if(k!=0)
                        {
                            w[j][k]=max(w[j][k],dp[j][k-1]+a[i][2]);
                        }
                        if(j+k!=i)
                        {
                            w[j][k]=max(w[j][k],dp[j][k]+a[i][3]);
                        }
                    }
                }
                for(int j=0;j<=n/2;j++)
                {
                    for(int k=0;k<=n/2;k++)
                    {
                        dp[j][k]=w[j][k];
                    }
                }
            }
            for(int i=0;i<=n/2;i++)
            {
                for(int j=0;j<=n/2;j++)
                {
                    if(n-i-j>n/2)
                    {
                        continue;
                    }
                    ans=max(ans,dp[i][j]);
                }
            }
            memset(dp,0,sizeof(dp));
        }
        else if(ssA)
        {
            for(int i=1;i<=n;i++)
            {
                b[i]=a[i][1];
            }
            sort(b+1,b+n+1);
            for(int i=n/2+1;i<=n;i++)
            {
                ans+=b[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}