#include<bits/stdc++.h>
using namespace std;

const int L = (5 * 1e5) + 5;
int n, k, a[L], dp[1005][1005];
int xor_sum[L];

int main() {
    (void)freopen("xor.in", "r", stdin);
    (void)freopen("xor.out", "w", stdout);
    (void)scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        (void)scanf("%d", &a[i]);
    }
    int value = 0;
    for(int i = 1; i <= n; i++) {
        value ^= a[i];
        xor_sum[i] = value;
    }
    for(int i = n - 1; i >= 1; i--) {
        for(int j = i; j <= n; j++) {
            int biggest = (((xor_sum[j] ^ xor_sum[i - 1]) == k) ? 1 : 0);
            for(int k = i; k < j; k++) {
                biggest = max(biggest, dp[i][k] + dp[k + 1][j]);
            }
            dp[i][j] = biggest;
        }
    }
    (void)printf("%d", dp[1][n]);
    return 0;
}

