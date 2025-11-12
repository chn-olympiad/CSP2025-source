#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
inline int read(){
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9'){
        x = x*10+ch-'0';
        ch = getchar();
    }
    return x;
}
struct node{
    int a1, a2, a3;
};
node a[100010];
int dp[210][210][210];
bool cmp1(node x, node y){
    return x.a1 > y.a1;
}
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T = read();
    while (T--){
        int n = read();
        int sum2 = 0, sum3 = 0;
        for (int i = 1; i <= n; i++){
            int x = read(), y = read(), z = read();
            a[i] = {x, y, z};
            sum2 += y;
            sum3 += z;
        }
        if (sum2 == 0 && sum3 == 0){
            sort(a+1, a+n+1, cmp1);
            int ans = 0;
            for (int i = 1; i <= n/2; i++) ans += a[i].a1;
            cout << ans << endl;
        }else{
            memset(dp, 0, sizeof dp);
            int t1, t2, t3;
            t1 = t2 = t3 = n/2;
            for (int i = 1; i <= n; i++){
                for (int j = t1; j >= 1; j--){
                    for (int k = t2; k >= 1; k--){
                        for (int l = t3; l >= 1; l--){
                            dp[j][k][l] = max(max(dp[j][k][l], dp[j-1][k][l]+a[i].a1),
                                          max(dp[j][k-1][l]+a[i].a2, dp[j][k][l-1]+a[i].a3));
                        }
                    }
                }
            }
            int ans = 0;
            for (int i = 1; i <= t1; i++){
                for (int j = 1; j <= t2; j++){
                    for (int k = 1; k <= t3; k++){
                        ans = max(ans, dp[i][j][k]);
                    }
                }
            }
            cout << dp[t1][t2][t3] << endl;
        }
    }
    return 0;
}
