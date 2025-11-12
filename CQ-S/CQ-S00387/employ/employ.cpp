#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;
int n, m, a[501], f[1048580][21];
string s;

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    s = " " + s;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (s[i] == '0')
            flag = false;
    }
    if (n <= 20) {
        f[0][0] = 1;
        for (int i = 0; i < (1 << n) - 1; i++) {
            int t = 0;
            for (int j = 1; j <= n; j++)
                if (i & (1 << (j - 1)))
                    t++;
            for (int j = 0; j <= t; j++) {
                for (int k = 1; k <= n; k++)
                    if (!(i & (1 << (k - 1)))) {
                        f[i + (1 << (k - 1))][j + (t - j < a[k] && s[t + 1] == '1')] += f[i][j];
                        f[i + (1 << (k - 1))][j + (t - j < a[k] && s[t + 1] == '1')] %= P;
                    }
            }
        }
        int ans = 0;
        for (int i = m; i <= n; i++) {
            ans += f[(1 << n) - 1][i];
            ans %= P;
        }
        printf("%d", ans);
    } else if (flag) {
        int t = 0;
        for (int i = 1; i <= n; i++)
            t += (a[i] != 0);
        if (t + 1 < m) {
            printf("0");
            return 0;
        }
        long long ans = 1;
        for (int i = 1; i <= n - 1; i++) {
            ans *= i;
            ans %= P;
        }
        ans *= (t >= m ? n : n - t);
        ans %= P;
        printf("%lld", ans);
    } else
        printf("0");
}