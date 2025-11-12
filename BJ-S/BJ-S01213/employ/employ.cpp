#include<bits/stdc++.h>
using namespace std;
int n, m, c[505], s[505], x = 1, mod = 998244353, dp[20][1000005][20], p[50];
bool f[505];
int popcnt(int x){
    int ans = 0;
    for(int i = n; i >= 1; i--) if(x >= p[i]) x -= p[i], ans++;
    return ans;
}long long solve1(){
    p[1] = 1; int ans = 0;
    for(int i = 2; i <= n; i++) p[i] = 2 * p[i-1] % mod;
    for(int i = 1; i <= n; i++) dp[1][p[i]][(bool)c[i] - 1 + s[1]] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2 * p[n]; j++){
            if(popcnt(j) != i) continue;
            bool f[20]; int num = j;
            for(int i = n; i >= 1; i--){
                if(num >= p[i]) num -= p[i], f[i] = 1;
                else f[i] = 0;
            }
            for(int k = 0; k <= i; k++){
                for(int ne = 1; ne <= n; ne++){
                    if(f[ne]) continue;
                    if(i - k >= c[ne] || s[i+1] == 0) dp[i + 1][j + p[ne]][k] += dp[i][j][k], dp[i + 1][j + p[ne]][k] %= mod;
                    else dp[i + 1][j + p[ne]][k + 1] += dp[i][j][k], dp[i + 1][j + p[ne]][k + 1] %= mod;
                } //printf("%d ", dp[i][j][k]);
            }//printf("\n");
        }//printf("\n");
    }for(int i = 1; i < 2 * p[n]; i++)
        for(int j = m; j <= n; j++) ans = (ans + dp[n][i][j]) % mod;
    return ans;
} int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        char c; scanf(" %c", &c);
        s[i] = c - '0'; x = min(x, s[i]);
    }for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
    if(x == 1){
        printf("%d\n", 0);
    }else if(n <= 18) printf("%lld\n", solve1());
    return 0;
}
