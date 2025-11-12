#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;
int n, m, ans, c[MAXN], id[MAXN];
string s;

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++) cin >> c[i], id[i] = i;
    do {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt >= c[id[i]]) cnt++;
            else if (s[i] == '0') cnt++;
        }
        if (cnt <= n - m) ans++;
    } while (next_permutation(id + 1, id + 1 + n));
    cout << ans << '\n';
}