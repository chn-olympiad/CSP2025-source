#include <bits/stdc++.h>
#define int long long
#define Pii pair<int, int>
#define Sc second
#define Fr first
#define ls(x) x << 1
#define rs(x) x << | 1

using namespace std;

const int kMaxN = 1e6 + 5, Mod = 998244353;

int a[kMaxN][3], f[kMaxN], n, ans;
priority_queue<int> q[3];

void solve() {
    for (; q[0].size(); q[0].pop());
    for (; q[1].size(); q[1].pop());
    for (; q[2].size(); q[2].pop());
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n;i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        int Mx = max({a[i][0], a[i][1], a[i][2]});
        ans += Mx;
        if (Mx == a[i][0]) {
            f[i] = max(a[i][1], a[i][2]) - a[i][0];
            q[0].push(f[i]);
        } else if (Mx == a[i][1]) {
            f[i] = max(a[i][0], a[i][2]) - a[i][1];
            q[1].push(f[i]);
        } else {
            f[i] = max(a[i][0], a[i][1]) - a[i][2];
            q[2].push(f[i]);
        }
    }
    for (int i = 0; i <= 2; i++) {
        for (; q[i].size() > n / 2; ) {
            ans += q[i].top();
            q[i].pop();
        }
    }
    cout << ans << '\n';
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios:: sync_with_stdio(0), cin.tie(0);
    int T; 
    for (cin >> T; T; T--) {
        solve();
    }
    return 0;
}