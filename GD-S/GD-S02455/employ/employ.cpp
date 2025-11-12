#include <bits/stdc++.h>
#define rep(_x,_y,_z) for(int _x=_y; _x <= _z; _x++)
#define rrep(_x,_y,_z) for(int _x=_y; _x >= _z; _x--)
#define fi first
#define se second
#define mod 998244353
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int w[25], a[25], p[25], n, m, ans = 0;
bool vis[25];

void dfs(int u) {
    if (u == n+1) {
        int cur = 0;
        rep(i, 1, n) {
            if (w[i] == 0 || a[p[i]] <= cur) {
                cur++;
            }
        }
        if (n - cur >= m) ans++;
        return;
    }
    rep(i, 1, n) {
        if (vis[i]) continue;
        vis[i] = 1;
        p[u] = i;
        dfs(u+1);
        vis[i] = 0;
    }
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    rep(i, 1, n) {
        char c;
        cin >> c;
        w[i] = c - '0';
    }
    rep(i, 1, n) cin >> a[i];
    dfs(1);
    cout << ans << endl;
}