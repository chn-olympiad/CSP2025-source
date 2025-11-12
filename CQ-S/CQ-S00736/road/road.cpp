#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ai2 = array<int, 2>;
using ai3 = array<int, 3>;
const int N = 1e4 + 10, M = 1e6 + 10, K = 2e1;
int n, m, k, c[K], val[K][N];
ai3 ev[M];
namespace baoli {
    int fa[N];
    ll ans = 0;
    int fd(int x) {return x == fa[x] ? x : fa[x] = fd(fa[x]);}
    void solve() {
        sort(ev + 1, ev + m + 1, [](auto x, auto y) {
            return x[2] < y[2];
        });
        int cnt = 0;
        for(int i = 1; i <= m; i ++) {
            if(fd(ev[i][0]) != fd(ev[i][1])) {
                fa[fd(ev[i][0])] = fd(ev[i][1]);
                cnt ++;
                ans += ev[i][2];
            }
            if(cnt == n - 1) break;
        }
        cout << ans << '\n';
    }
}
namespace A {
    ll ans = 0;
    int fa[N];
    int fd(int x) {return x == fa[x] ? x : fa[x] = fd(fa[x]);}
    void solve() {
        int len = m;
        for(int i = 1; i <= k; i ++) {
            for(int j = 1; j <= n; j ++) {
                for(int t = j + 1; t <= n; t ++) {
                    ev[++ len] = ai3{j, t, val[i][j] + val[i][t]};
                }
            }
        }
        sort(ev + 1, ev + len + 1, [](auto x, auto y) {
            return x[2] < y[2];
        });
        int cnt = 0;
        for(int i = 1; i <= m; i ++) {
            if(fd(ev[i][0]) != fd(ev[i][1])) {
                fa[fd(ev[i][0])] = fd(ev[i][1]);
                cnt ++;
                ans += ev[i][2];
            }
            if(cnt == n - 1) break;
        }
        cout << ans << '\n';
    }
}
int fa[N];
int fd(int x) {return x == fa[x] ? x : fa[x] = fd(fa[x]);}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++) cin >> ev[i][0] >> ev[i][1] >> ev[i][2];
    for(int i = 1; i <= k; i ++) {
        cin >> c[i];
        for(int j = 1; j <= n; j ++) cin >> val[i][j];
    }
    if(!k) {
        baoli::solve();
        return 0;
    }
    int flag = 0;
    for(int i = 1; i <= n; i ++) {
        flag |= c[i];
    }
    if(!flag) {
        A::solve();
    }
    static ai3 tmp[M];
    for(int i = 1; i <= m; i ++) tmp[i] = ev[i];
    ll sum = 1e18;
    for(int s = 0; s < 1 << k; s ++) {
        ll ans = 0;
        int len = m;
        iota(fa + 1, fa + n + 1, 1);
        for(int i = 1; i <= m; i ++) ev[i] = tmp[i];
        for(int i = 0; i < k; i ++) {
            if(s >> i & 1) {
                ans = ans + c[i + 1];
                for(int j = 1; j <= n; j ++) {
                    for(int t = j + 1; t <= n; t ++) {
                        ev[++ len] = ai3{j, t, val[i + 1][j] + val[i + 1][t]};
                    }
                }
            }
        }
        sort(ev + 1, ev + len + 1, [](auto x, auto y) {
            return x[2] < y[2];
        });
        int cnt = 0;
        for(int i = 1; i <= len; i ++) {
            if(fd(ev[i][0]) != fd(ev[i][1])) {
                fa[fd(ev[i][0])] = fd(ev[i][1]);
                cnt ++;
                ans += ev[i][2];
            }
            if(cnt == n - 1) break;
        }
        sum = min(sum, ans);
    }
    cout << sum << '\n';
    return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
