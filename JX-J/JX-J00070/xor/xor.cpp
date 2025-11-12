#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
int a[N], sum[N], dp[N];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i-1] ^ a[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        for (int j = 1; j <= i; j++) {
            int t = sum[i] ^ sum[j-1];
            if (t == k) {
                dp[i] = max(dp[i], dp[j-1] + 1);
            }
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
