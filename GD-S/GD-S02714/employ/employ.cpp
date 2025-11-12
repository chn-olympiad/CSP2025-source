#include <bits/stdc++.h>
using namespace std;

namespace brute {
    int n, m;
    int use[501], c[501];
    int res = 0;
    string s;
    void dfs(int u, int x) {
        if ((n+1-u)+x < m) return;
        if (u == n + 1) {
            if (x >= m) ++res;
            if (res >= 998244353) res -= 998244353;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (use[i]) continue;
            use[i] = 1;
            dfs(u + 1, x + ((c[i] > (u - x - 1)) && s[u] == '1'));
            use[i] = 0;
        }
    }
    void main() {
        cin >> s;
        s = ' ' + s;
        for (int i = 1; i <= n; ++i) cin >> c[i];
        dfs(1, 0);
        cout << res << '\n';
    }
}

namespace IMC {
    int n, m;
    typedef long long ll;
    constexpr int N = 505, MOD = 998244353;
    // ll dp[N];
    int c[N], prc[N], mxc;
    string s;
    void main() {
        cin >> n >> m;
        if (n <= 10) {
            brute::n = n, brute::m = m;
            brute::main();
            return;
        }
        cin >> s; s = ' ' + s;
        int one = 0;
        for (int i = 1; i <= n; ++i)
            one += (s[i] == '1');
        if (one < m) {
            cout << 0 << '\n';
            return;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
            mxc = max(mxc, c[i]);
            prc[c[i]]++;
        }
        if (n == m) {
            if (prc[0] == 0) {
                ll res = 1;
                for (int i = 2; i <= n; ++i)
                    res = res * i % MOD;
                cout << res << '\n';
                return;
            } else {
                cout << 0 << '\n';
                return;
            }
        }
        brute::n = n, brute::m = m;
        brute::main();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    IMC::main();
    return 0;
}