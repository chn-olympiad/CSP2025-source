#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e9; 
int a[N][3];
vector <int> p[3];
inline void solve() {
    for (int i = 0; i < 3; i++) p[i].clear();
    int n, ans = 0; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) cin >> a[i][j];
        int mx = max({a[i][0], a[i][1], a[i][2]});
        if (a[i][0] == mx) p[0].push_back(i);
        else if (a[i][1] == mx) p[1].push_back(i);
        else p[2].push_back(i); ans += mx; 
    }
    int mx = max({p[0].size(), p[1].size(), p[2].size()}), id = 0;
    if (p[0].size() == mx) id = 0;
    else if (p[1].size() == mx) id = 1;
    else id = 2;
    if (mx > n / 2) {
        priority_queue <int, vector <int>, greater <int>> q;
        for (auto i : p[id]) {
            int mx = -INF; 
            for (int j = 0; j < 3; j++)
                if (j ^ id) mx = max(mx, a[i][j] - a[i][id]);
            q.push(-mx); 
        }
        int s = mx;
        while (s > n / 2) ans -= q.top(), q.pop(), s--;
    } cout << ans << '\n';
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0; 
}