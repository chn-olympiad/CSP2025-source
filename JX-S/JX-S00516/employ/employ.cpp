#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'

constexpr int MAXN = 15;
int n, m;
string s;
int c[MAXN];
int p[MAXN];

signed main() {
#ifndef INFTER
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> s;
    if (n <= 10) {
    rep (i, 1, n) cin >> c[i], p[i] = i;
    int ans = 0;
    do {
        int cnt = 0, cur = 0;
        rep (i, 1, n) {
            if (s[i - 1] == '1' && cur < c[i]) {
                cnt++;
            } else {
                cur++;
            }
        }
        if (cnt >= m) ans++;
    } while (next_permutation(p + 1, p + n + 1));
    cout << ans << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}