#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], b[N], c[N], dp[N][3], vis[N];

struct Node {
    int a, b, c, cnt, id;
};

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    memset(dp, 0, sizeof dp);
    memset(vis, 0, sizeof vis);
    int ans = 0;

    queue<Node> que;
    que.push({1, 0, 0, a[1], 2});
    que.push({0, 1, 0, b[1], 2});
    que.push({0, 0, 1, c[1], 2});

    while (!que.empty()) {
        Node q = que.front();
        que.pop();
        if (q.id == n + 1) {
            ans = max(ans, q.cnt);
            continue;
        }
        if (q.a + 1 <= n / 2) que.push({q.a + 1, q.b, q.c, q.cnt + a[q.id], q.id + 1});
        if (q.b + 1 <= n / 2) que.push({q.a, q.b + 1, q.c, q.cnt + b[q.id], q.id + 1});
        if (q.c + 1 <= n / 2) que.push({q.a, q.b, q.c + 1, q.cnt + c[q.id], q.id + 1});
    }
    
    cout << ans << '\n';
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}