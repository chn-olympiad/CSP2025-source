#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 501;
int fac[501], ifac[501];

const int mod = 998244353;

int bm(int b, int p) {
    if (!p) return 1;
    int res = bm(b, p / 2);
    res = res * res % mod;
    if (p % 2 == 1) res = res * b % mod;
    return res;
}

int dp[1 << 18][19];

int32_t main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % mod;
        ifac[i] = bm(fac[i], mod - 2);
    }
    int n, m;
    cin >> n >> m;
    vector<int> s(n+1);
    vector<int> freq(n+1, 0);
    vector<int> C;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        s[i] = c - '0';
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        C.push_back(x);
        freq[x]++;
    }
    if (m == 1) {
        int fre = 0;
        for (int i = 1; i <= n; i++) {
            freq[i] += freq[i - 1];
            if (s[i] == 0) fre++;
        }
        int non = fac[fre];
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 1) {
                non *= ((freq[i - 1] - cur + mod) % mod);
                non %= mod;
                cur++;
            }
        }
        non = fac[n] - non + mod;
        if (non >= mod) non -= mod;
        cout << non << '\n';
    } else if (m == n) {
        bool ok = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 0) ok = 0;
        }
        if (freq[0] > 0) ok = 0;
        if (ok) cout << fac[n] << '\n';
        else cout << 0 << '\n';
    } else if (n <= 18) {
        dp[0][0] = 1;
        for (int i = 1; i < (1 << n); i++) {
            int sb = 0;
            for (int j = 0; j < n; j++) if (i & (1 << j)) sb++;
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i & (1 << k)) {
                        if (j >= 1 && (s[sb] == 0 || j - 1 >= C[k])) dp[i][j] += dp[i ^ (1 << k)][j - 1];
                        if (s[sb] == 1 && j < C[k]) dp[i][j] += dp[i ^ (1 << k)][j];
                        dp[i][j] %= mod;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= n - m; i++) res += dp[(1<<n)-1][i], res %= mod;
        cout << res << '\n';
    }
}