#include<bits/stdc++.h>
using namespace std;

long long t,n;
long long a[100005][5];
long long dp[10005][10005];
bool flat2 = true;
bool flat3 = true;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while (t--){
        scanf("%lld",&n);
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= 3;j++){
                scanf("%lld",&a[i][j]);
            }
            if (a[i][2] != 0) flat2 = false;
            if (a[i][3] != 0) flat3 = false;
        }
        if (n == 2){
            long long cnt = -1e9;
            for (int i = 1;i <= 3;i++){
                for (int j = 1;j <= 3;j++){
                    if (i != j && a[1][i] + a[2][j] > cnt) cnt = a[1][i] + a[2][j];
                }
            }
            printf("%lld",cnt);
        }else{
            dp[0][0] = a[1][1];
            for (int i = 1;i <= n;i++){
                for (int j = 1;j <= n;j++){
                    if (dp[i][j] < a[i][1]) dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - 1] + a[i][1]);
                    if (dp[i][j] < a[i][2]) dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - 2] + a[i][2]);
                    if (dp[i][j] < a[i][3]) dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - 3] + a[i][3]);
                }
            }
            printf("%lld",dp[n][n]);
            for (int i = 1;i <= n;i++){
                for (int j = 1;j <= n;j++){
                    dp[i][j] = 0;
                }
            }
        }
    }
    return 0;
}
