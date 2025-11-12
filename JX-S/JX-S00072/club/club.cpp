#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N = 1e5 + 5;
int t;
int n;
int a[N][4];
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> a[i][j];
            }
        }
        priority_queue<pii, vector<pii>, greater<pii> > q[4];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int mx = max({a[i][1], a[i][2], a[i][3]});
            if (mx == a[i][1]) {
                q[1].push(make_pair(a[i][1], i));
            }
            else if (mx == a[i][2]) {
                q[2].push(make_pair(a[i][2], i));
            }
            else {
                q[3].push(make_pair(a[i][3], i));
            }
            ans += mx;
        }
        priority_queue<int> p;
        if (q[1].size() > n / 2) {
            int dx = q[1].size() - n / 2;
            while (!q[1].empty()) {
                pii t = q[1].top();
                q[1].pop();
                p.push(max(a[t.second][2], a[t.second][3]) - t.first);
            }
            while (dx--) {
                ans += p.top();
                p.pop();
            }
        }
        if (q[2].size() > n / 2) {
            int dx = q[2].size() - n / 2;
            while (!q[2].empty()) {
                pii t = q[2].top();
                q[2].pop();
                p.push(max(a[t.second][1], a[t.second][3]) - t.first);
            }
            while (dx--) {
                ans += p.top();
                p.pop();
            }
        }
        if (q[3].size() > n / 2) {
            int dx = q[3].size() - n / 2;
            while (!q[3].empty()) {
                pii t = q[3].top();
                q[3].pop();
                p.push(max(a[t.second][1], a[t.second][2]) - t.first);
            }
            while (dx--) {
                ans += p.top();
                p.pop();
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
