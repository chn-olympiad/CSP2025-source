#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
pair<int, int> a[N][4];
struct node {
    int i, pos, val;
    friend bool operator < (node x, node y) {
        return x.val > y.val;
    }
};
priority_queue<node> lis[3];
void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= 3; i++) {
        while (lis[i].size()) lis[i].pop();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> a[i][j].first;
            a[i][j].second = j;
        }
        a[i][0].first = -1e9;
        sort(a[i] + 1, a[i] + 1 + 3);
        ans += a[i][3].first;
        lis[a[i][3].second].push({i, 3, a[i][3].first - a[i][2].first});
    }
    while (1) {
        int id = -1;
        for (int i = 1; i <= 3; i++) {
            if (lis[i].size() > n / 2) {
                id = i;
                break;
            }
        }
        if (id == -1) break;
        auto cur = lis[id].top();
        lis[id].pop();
        ans -= cur.val;
        lis[a[cur.i][cur.pos - 1].second].push({cur.i, cur.pos - 1, a[cur.i][cur.pos - 1].first - a[cur.i][cur.pos - 2].first});
    }
    cout << ans << '\n';
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}