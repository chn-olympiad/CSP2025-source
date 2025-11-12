#include <bits/stdc++.h>
#define int long long
#define rep(x, y, z) for (int x = (y); x <= (z); ++x)
#define per(x, y, z) for (int x = (y); x >= (z); --x)
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
constexpr int maxn = 1e5 + 5;
int a[maxn][3], p[maxn], c[3], n;
bool mark[maxn];
void solve() {
    cin >> n; int ans = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    memset(c, 0, sizeof c);
    rep(i, 1, n) {
        mark[i] = false;
        int mx = 0;
        rep(x, 0, 2) {cin >> a[i][x]; mx = max(mx, a[i][x]);}
        ans += mx;
        rep(x, 0, 2) if (a[i][x] == mx) {
            ++c[x], p[i] = x;
            break;
        }   
    }
    int id = 0;
    rep(x, 0, 2) if (c[x] > c[id]) id = x;
    rep(i, 1, n) if (p[i] == id) {
        rep(y, 0, 2) if (y != id) pq.push({a[i][id] - a[i][y], i});
    }
    while (c[id] > (n / 2)) {
        auto [d, x] = pq.top(); pq.pop();
        if (mark[x]) continue;
        ans -= d, --c[id];
        mark[x] = true;
    }
    cout << ans << endl;
}
signed main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
/*
g++ club.cpp -o club
*/