#include<bits/stdc++.h>
using namespace std;

int T, n, a[100100][5], dp[710][710][710], f[100100], maxn = 0;

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 1; i <= n; i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        int i = 1, x = 0, y = 0, z = 0;
        for(int i = 0; i <= n/2; i++){
            for(int j = 0; j <= n/2; j++){
                for(int k = 0; k <= n/2; k++){
                    if(i+j+k>n){
                        break;
                    }
                    if(i >= 1){
                        dp[i][j][k] = max(dp[i-1][j][k]+a[i+j+k][1], dp[i][j][k]);
                    }
                    if(j >= 1){
                        dp[i][j][k] = max(dp[i][j-1][k]+a[i+j+k][2], dp[i][j][k]);
                    }
                    if(k >= 1){
                        dp[i][j][k] = max(dp[i][j][k-1]+a[i+j+k][3], dp[i][j][k]);
                    }
                    maxn = max(maxn, dp[i][j][k]);
                }
            }
        }
        for(int i = 0; i <= n/2; i++){
            for(int j = 0; j <= n/2; j++){
                for(int k = 0; k <= n/2; k++){
                    dp[i][j][k] = 0;
                }
            }
        }
        cout<<maxn<<endl;
        maxn = -1;
    }
    return 0;
}