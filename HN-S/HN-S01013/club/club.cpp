#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct Node {
    int i, j, x;
    bool operator < (const Node &i) const {
        return x > i.x;
    }
};

int T, n, cnt[5], a[N][5], id[N][5];
pair<int, int> b[5];
priority_queue<Node> pq;

void Solve() {
    cin >> n; int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> a[i][j], b[j] = {a[i][j], j};
        }
        sort(b + 1, b + 4);
        for (int j = 1; j <= 3; j++) id[i][j] = b[4 - j].second;
        cnt[id[i][1]]++, ans += a[i][id[i][1]];
        pq.push({i, 2, a[i][id[i][1]] - a[i][id[i][2]]});
    }
    while (!pq.empty()) {
        Node now = pq.top(); pq.pop();
        if (cnt[id[now.i][now.j - 1]] > n / 2) {
            cnt[id[now.i][now.j - 1]]--;
            cnt[id[now.i][now.j]]++;
            ans -= now.x;
            pq.push({now.i, now.j + 1, a[now.i][id[now.i][now.j]] - a[now.i][id[now.i][now.j + 1]]});
        }
    }
    cout << ans << '\n';
    cnt[1] = cnt[2] = cnt[3] = 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T--) Solve();
    return 0;
}
