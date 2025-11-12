#include <cstdio>
#include <algorithm>

const int N = 5009, mod = 998244353;

int n, mx;

int a[N], d[N];

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), mx = std::max(mx, a[i]);

    if (n < 3) 
        printf("0");
    else if (n == 3) {
        int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += a[i];
        printf(sum > 2 * mx ? "1" : "0");
    }
    else if (mx == 1) {
        long long ans = 0;
        for (int j = 2; j < n; j++) {
            for (int i = 1; i <= n - j; i++) {
                int sum = (1 + i) * i / 2;
                ans += 1ll * (n - i - j + 1) * sum;
                ans %= mod;
            }
        }
        printf("%lld", ans);
    }
    else {
        int ans = 0, end = 1 << n;
        for (int i = 0; i < end; i++) if (__builtin_popcount(i) >= 3) {
            int x = i, cnt = 0, sum = 0, m = 0;
            while (x) {
                cnt ++;
                if (x % 2 == 1) {
                    sum += a[cnt], m = std::max(m, a[cnt]);
                    printf("%d ", cnt);
                }
                x /= 2;
            }
            printf("\n");
            if (sum > 2 * m)
                ans ++;
        }
        printf("%d", ans);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}