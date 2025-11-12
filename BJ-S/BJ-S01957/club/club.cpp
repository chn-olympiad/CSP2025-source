#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5 + 10;
int t, n, a[maxn][3];
vector<int> g, e[3];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 3; i++) e[i].clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) cin >> a[i][j];
            e[max_element(a[i], a[i] + 3) - a[i]].push_back(i);
        } int p = -1, ans = 0;
        for (int i = 0; i < 3; i++) if (e[i].size() > (n >> 1)) p = i;
        for (int j = 0; j < 3; j++)
            for (int i : e[j]) ans += a[i][j];
        if (p == -1) {cout << ans << '\n'; continue;} g.clear();
        for (int i : e[p]) {
            int mx = 0;
            for (int j = 0; j < 3; j++) if (j != p)
                mx = max(mx, a[i][j]);
            g.push_back(a[i][p] - mx);
        } sort(g.begin(), g.end(), greater<int>{});
        for (int i = n >> 1; i < g.size(); i++) ans -= g[i];
        cout << ans << '\n';
    }
    return 0;
}