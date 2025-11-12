// Author: lzm0107

// 17:53 expect 24

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using aii = array<int, 2>;
using ull = unsigned long long;

const int P = 998244353;

void inc(int &x, int y) { if (int(unsigned(x += y) - P) >= 0) x -= P; }
int mod(int x) { return x >= P ? x - P : x; }

const int N = 5e2;

int n, m;
string s;
int c[N + 10];

namespace subtask0 {
    bool check() {
        return n == m;
    }

    void solve() {
        int ans = 1;
        for (int i = 1; i <= n; ++i) {
            ans = (ll)ans * i % P;
            if (s[i] == '0' || c[i] == 0) {
                ans = 0;
            }
        }
        cout << ans << '\n';
    }
}

namespace subtask1 {
    const int N = 18, POW2_N = 262144;
    
    int f[POW2_N + 10][N + 2];
    
    bool check() {
        return n <= N;
    }

    void solve() {
        f[0][0] = 1;
        for (int i = 0; i < (1 << n) - 1; ++i) {
            int popc = __builtin_popcount(i);
            for (int j = 0; j <= popc; ++j) {
                for (int k = 1; k <= n; ++k) {
                    if (!(i >> k - 1 & 1)) {
                        int new_st = i | 1 << k - 1;
                        if (s[popc + 1] == '1' && popc - j < c[k]) {
                            inc(f[new_st][j + 1], f[i][j]);
                        } else {
                            inc(f[new_st][j], f[i][j]);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = m; i <= n; ++i) {
            inc(ans, f[(1 << n) - 1][i]);
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin >> n >> m >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    if (subtask0::check()) {
        subtask0::solve();
    } else if (subtask1::check()) {
        subtask1::solve();
    }
    return 0;
}