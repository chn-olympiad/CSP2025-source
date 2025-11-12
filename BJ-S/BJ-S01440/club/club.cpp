#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n==1e5){
            int ans=-1;
            int a[n+1][4];
            int dp[n/2+2][n/2+2];
            for(int i=0;i<=n/2+1;i++){
                for(int j=0;j<=n/2+1;j++){
                        dp[i][j]=0;
                }
            }
            for(int i=1;i<=n;i++){
                cin>>a[i][1]>>a[i][2]>>a[i][3];
            }
            for(int i=0;i<=n/2;i++){
                for(int j=0;j<=n/2;j++){
                    if(i+j==0) continue;
                    if(i>0 and j>0) dp[i][j]=max(dp[i][j],max(dp[i-1][j]+a[i+j][1],dp[i][j-1]+a[i+j][2]));
                    else if(i>0) dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i+j][1]);
                    else if(j>0) dp[i][j]=max(dp[i][j],dp[i][j-1]+a[i+j][2]);
                    if(i+j==n) ans=max(ans,dp[i][j]);
                }
            }
            cout<<ans<<endl;
            continue;
        }
        int a[n+1][4];
        int dp[n/2+2][n/2+2][n/2+2];
        for(int i=0;i<=n/2+1;i++){
            for(int j=0;j<=n/2+1;j++){
                for(int k=0;k<=n/2+1;k++){
                    dp[i][j][k]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        dp[0][0][0]=0;
        int ans=-1;
        for(int i=0;i<=n/2;i++){
            for(int j=0;j<=n/2;j++){
                for(int k=0;k<=n/2;k++){
                    if(i+j+k>n) break;
                    if(i+j+k==0) continue;
                    if(i>0 and j>0 and k>0) dp[i][j][k]=max(dp[i][j][k],max(dp[i-1][j][k]+a[i+j+k][1],max(dp[i][j-1][k]+a[i+j+k][2],dp[i][j][k-1]+a[i+j+k][3])));
                    else if(i>0 and j>0) dp[i][j][k]=max(dp[i][j][k],max(dp[i-1][j][k]+a[i+j+k][1],dp[i][j-1][k]+a[i+j+k][2]));
                    else if(i>0 and k>0) dp[i][j][k]=max(dp[i][j][k],max(dp[i-1][j][k]+a[i+j+k][1],dp[i][j][k-1]+a[i+j+k][3]));
                    else if(j>0 and k>0) dp[i][j][k]=max(dp[i][j][k],max(dp[i][j-1][k]+a[i+j+k][2],dp[i][j][k-1]+a[i+j+k][3]));
                    else if(i>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i+j+k][1]);
                    else if(j>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[i+j+k][2]);
                    else if(k>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[i+j+k][3]);
                    if(i+j+k==n)ans=max(ans,dp[i][j][k]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
