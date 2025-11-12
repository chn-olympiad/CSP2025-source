#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5;
const int mod = 998244353;

int c[N], p[N];

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        p[i] = i;
    }
    int ans = 0;
    do {
        int cnt = 0, pos = 0;
        for (int i = 1; i <= n; i++) {
            if (pos >= c[p[i]]) {
                pos++;
                continue;
            }
            if (s[i - 1] == '1') cnt++;
            else pos++;
        }
        if (cnt >= m) ans = (ans + 1) % mod;
    } while (next_permutation(p + 1, p + 1 + n));
    cout << ans << '\n';
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
