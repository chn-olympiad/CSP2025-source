#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 998244353;
int n, m, res, c0, a[N], c[N], f[N] = {1};
string s;
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s, s = ' ' + s;
    for (int i = 1; i <= n; i++) c0 += s[i] == '0';
    for (int i = 1; i <= n; i++) f[i] = 1LL * f[i - 1] * i % M;
    for (int i = 1; i <= n; i++) cin >> c[i], a[i] = i;
    if (!c0) {
        cout << f[n];
        return 0;
    }
    do {
        int cnt = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') cnt++;
            else if (cnt >= c[a[i]]) cnt++;
            else ans++;
        }
        if (ans >= m) res++;
    } while (next_permutation(a + 1, a + n + 1));
    cout << res;
    return 0;
}
