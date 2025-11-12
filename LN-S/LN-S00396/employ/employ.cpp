#include <bits/stdc++.h>
using namespace std;
#define FILEIO "employ"
const int mod = 998'244'353;

signed main() {
    #ifdef FILEIO
        freopen(FILEIO ".in", "r", stdin);
        freopen(FILEIO ".out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    if (n == m) {
        for (int i = 1; i <= n; ++i) {
            char x; cin >> x;
            if (x == '0') {
                cout << "0\n";
                return 0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x;
            if (x == 0) {
                cout << "0\n";
                return 0;
            }
        }
        long long ans = 1;
        for (int i = 1; i <= n; ++i) {
            (ans *= 1ll * i) %= mod;
        }
        cout << ans << "\n";
    }
    if (n <= 10) {
        vector<int> can(n + 5);
        for (int i = 1; i <= n; ++i) {
            char x; cin >> x;
            can[i] = x - '0';
        }
        vector<int> op(n + 5), c(n + 5);
        for (int i = 1; i <= n; ++i) cin >> c[i];
        for (int i = 1; i <= n; ++i) op[i] = i;
        int fans = 0;
        do {
            int tmp = 0, ans = 0;
            for (int p = 1; p <= n; ++p) {
                int i = op[p];
                if (tmp >= c[i] || can[p] == 0) { tmp++; continue; }
                ans++;
                ans %= mod;
            }
            if (ans >= m) fans++;
            fans %= mod;
        } while (next_permutation(op.begin() + 1, op.begin() + n + 1));
        cout << fans << "\n";
    }
}