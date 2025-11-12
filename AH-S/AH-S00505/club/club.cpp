#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,at[10],n;
    cin >> t;
    for(int k=1;k<=t;k++){
        int a[100005][5];
        cin >> n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin >> a[i][j];
            }
        }
        int dp[100005][5];
        int v[5];
        for(int i=1;i<=3;i++){
            dp[1][i]=a[1][i];
            v[i]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=3;j++){
                if(v[j]<=n/2){
                    dp[i][j]=max(max(dp[i-1][1],dp[i-1][2]),dp[i-1][3])+a[i][j];
                    v[j]++;
                }
                else{
                    if(j==1){
                        if(dp[i-1][2]>dp[i-1][3]){
                            dp[i][j]=dp[i-1][2]+a[i][j];
                            v[2]++;
                        }
                        else{
                            dp[i][j]=dp[i-1][3]+a[i][j];
                            v[3]++;
                        }
                    }
                    if(j==2){
                        if(dp[i-1][1]>dp[i-1][3]){
                            dp[i][j]=dp[i-1][1]+a[i][j];
                            v[1]++;
                        }
                        else{
                            dp[i][j]=dp[i-1][3]+a[i][j];
                            v[3]++;
                        }
                    }
                    if(j==3){
                        if(dp[i-1][1]>dp[i-1][2]){
                            dp[i][j]=dp[i-1][1]+a[i][j];
                            v[1]++;
                        }
                        else{
                            dp[i][j]=dp[i-1][2]+a[i][j];
                            v[2]++;
                        }
                    }
                }
            }
        }
        at[k]=max(max(dp[n][1],dp[n][2]),dp[n][3]);
    }
    for(int i=1;i<=t;i++){
        cout << at[i] << endl;
    }
    return 0;
}
