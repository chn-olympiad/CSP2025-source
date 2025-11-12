#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int mod = 998244353;

int n, m;
string s;
int c[N];
int dp[(1 << 18) + 5][21];

void upd(int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;

    
    s = ' ' + s;

    for (int i = 1; i <= n; i++) cin >> c[i];

    if (n > 18) {
        cout << 0;
        return 0;
    }

    dp[0][0] = 1;
    
    for (int S = 0; S < (1 << n); S++) {
        int t = __builtin_popcount(S);
        for (int i = 1; i <= n; i++) if (!((S >> (i - 1) & 1))) {
            for (int j = 0; j < n; j++) {
                upd(dp[S | (1 << (i - 1))][j + (j >= c[i] || s[t+1] == '0')], dp[S][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n-m; i++) {
        upd(ans, dp[(1 << n) - 1][i]);
    }
    cout << ans << '\n';



    return 0;
}