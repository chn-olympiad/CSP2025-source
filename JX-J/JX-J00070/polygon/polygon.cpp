#include<bits/stdc++.h>

using namespace std;

const int N = 5005, Mod = 998224353;
long long a[N], dp[N*N], n, cnt = 0, sum = 0;

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a+1, a+n+1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= a[i]; j--) {
            if (dp[j-a[i]]) {
                dp[j] += dp[j-a[i]];
                if (j > a[i] * 2) cnt = (cnt + dp[j]) % Mod;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
