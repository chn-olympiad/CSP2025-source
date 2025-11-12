#include<bits/stdc++.h>
using namespace std;
int a[1000],b[100],c[100];
int dp[10][10][10];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        dp[0][0][i]+=c[i];
        dp[0][i][0]+=b[i];
        dp[i][0][0]+=a[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+c[i]);
                dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+b[i]);
                dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i]);
            }
        }
    }
    int sum=0;
    int ma=-10;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                    if(i+j+k==n){
                            sum+=dp[i][j][k];
                    }
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout)
    return 0;
}
