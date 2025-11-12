#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
int n, m, s[505], S, a[505], cnt[300000];
long long dp[20][300000], ans, dpdp[2][505];

void add(long long& x, long long y) {
    x += y;
    if (x >= mod) x -= mod;
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char ch;
        cin >> ch;
        s[i] = ch - '0';
        S += s[i];
    }
    if (m == n) {
        if (S != n) {
            for (int i = 1; i <= n; i++) cin >> a[i];
            cout << 0;
            return 0;
        }
        S = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 0) S++;
        }
        if (S) {
            cout << 0;
            return 0;
        }
        long long mul = 1;
        for (long long i = 1; i <= n; i++) mul = mul * i % mod;
        cout << mul;
        return 0;
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < (1 << n); i++) cnt[i] = cnt[i >> 1] + (i & 1);
    dp[0][0] = 1;
    for (int i = 0; i <= (1 << n) - 2; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[j][i] == 0) continue;
            for (int k = 0; k < n; k++) {
                if (i & (1 << k)) continue;
                if (s[cnt[i] + 1]) {
                    if (j >= a[k + 1]) add(dp[j + 1][i | (1 << k)], dp[j][i]);
                    else add(dp[j][i | (1 << k)], dp[j][i]);
                }
                else add(dp[j + 1][i | (1 << k)], dp[j][i]);
            }
        }
    }
    for (int i = 0; i <= n - m; i++) add(ans, dp[i][(1 << n) - 1]);
    cout << ans;
    return 0;
}
