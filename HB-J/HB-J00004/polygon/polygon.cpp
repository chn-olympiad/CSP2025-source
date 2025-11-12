# include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 5e3 + 10;
int a[N], dp[N], n;
int s[N];
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    // 1~3
    if (n < 3) {
        printf("0");
        return 0;
    }
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] != 1) {
            flag = 0;
        }
        s[a[i]]++;
    }
    // 15~20
    if (flag) {
        long long ret = 0;
        for (int i = 3; i <= n; i++) {
            long long sum = 1;
            for (int j = i + 1; j <= n; j++) {
                sum = ((sum % MOD) * (j % MOD)) % MOD;
            }
            ret = (ret + sum) % MOD;
        }
        printf("%lld", ret % MOD);
        return 0;
    }
    sort(a + 1, a + n + 1);
    // 1~3
    if (n == 3) {
        if (a[1] + a[2] <= a[3]) {
            printf("0");
        } else {
            printf("1");
        }
        return 0;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i - s[a[i]] > 0) {
            dp[i] = (dp[i - s[a[i]]] * s[a[i]] + 1) % MOD;
        } else {
            dp[i] = dp[i - 1];
        }
    }
    printf("%d", dp[n]);
    return 0;
}
