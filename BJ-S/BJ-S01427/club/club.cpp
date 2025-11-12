#include<bits/stdc++.h>
using namespace std;
int n,t;
int dp[32][16][16][16];
int a[4][100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int sum1=0,sum2=0,sum3=0,ans=0;

        for(int i=1;i<=n;i++){
            cin>>a[1][i]>>a[2][i]>>a[3][i];
            sum1+=a[1][i],sum2+=a[2][i],sum3+=a[3][i];
        }
        if(sum2==0 and sum3==0){
            sort(a[1]+1,a[1]+n+1);
            for(int i=1;i<=n/2;i++)ans+=a[1][i];
            cout<<ans;
        }
        if(n<=30){
            memset(dp,0,sizeof dp);
            for(int i=1;i<=n;i++)
                for(int j=n/2;j>=1;j--)
                    for(int k=n/2;k>=1;k--)
                        for(int h=n/2;h>=1;h--){
                            dp[i][j][k][h]=max(max(dp[i-1][j-1][k][h]+a[1][i],dp[i-1][j][k-1][h]+a[2][i]),max(dp[i-1][j][k][h-1]+a[3][i],dp[i][j][k][h]));
                        }
            for(int j=1;j<=n/2;j++)
                for(int k=1;k<=n/2;k++)
                        for(int h=1;h<=n/2;h++)ans=max(dp[n][j/2][k/2][h/2],ans);
            cout<<dp[n][n/2][n/2][n/2]<<endl;
        }

    }
    return 0;
}