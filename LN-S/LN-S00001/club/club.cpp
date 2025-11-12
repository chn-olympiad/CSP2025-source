#include <bits/stdc++.h>
using namespace std;
long long a[100010][5];
long long dp[110][110][110];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        long long ans=0;
        int n;
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=0;
        dp[1][0][0]=a[1][1];
        dp[0][1][0]=a[1][2];
        dp[0][0][1]=a[1][3];
        for(int i=0;i<=n/2;i++){
            for(int j=0;j<=n/2;j++){
                for(int k=0;k<=n/2;k++){
                    if(i!=0){
                        if(j!=0){
                            dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[i+j+k][2]);
                        }
                        if(k!=0){
                            dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[i+j+k][3]);
                        }
                    }
                    if(j!=0){
                        if(i!=0){
                            dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i+j+k][1]);
                        }
                        if(k!=0){
                            dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[i+j+k][3]);
                        }
                    }
                    if(k!=0){
                        if(j!=0){
                            dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[i+j+k][2]);
                        }
                        if(i!=0){
                            dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i+j+k][1]);
                        }
                    }
                    if(i+j+k==n)
                    {
                        ans=max(ans,dp[i][j][k]);
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
