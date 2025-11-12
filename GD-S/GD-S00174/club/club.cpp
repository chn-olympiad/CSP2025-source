#include <bits/stdc++.h>

typedef long long ll;
constexpr int N = 1e5 + 10;

using namespace std;

struct node {
    ll val, idx, t, l;
    bool operator< (const node &b) const {
        if (val == b.val) return t < b.t;
        return val > b.val;
    }
};

ll ans;
int n;
ll a[3][N];
bool vis[N];
int cnt[3];
priority_queue<node> q;

void init() {
    memset(vis, 0, sizeof vis);
    memset(cnt, 0, sizeof cnt);
    ans = 0;
}

void solve() {
    init();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) cin >> a[j][i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            ll x = a[0][i] + a[1][i] + a[2][i] - a[j][i];
            q.push({x, i, a[j][i], j});
        }
    }
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (vis[t.idx]) continue;
        if (cnt[t.l] + 1 > (n / 2)) continue;
        cnt[t.l] += 1;
        vis[t.idx] = true;
        ans += t.t;
    }
    cout << ans << '\n';
}

void Debug() {}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}
