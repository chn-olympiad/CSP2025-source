#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(register int i = a; i <= b; ++i)
#define rep_(i, a, b) for(register int i = a; i >= b;  --i)
typedef long long ll;
namespace Kx {
    constexpr int M = 2000005, N = 10005, K = 12;
    ll n, m, k, ans, c[K], a[K][N], fa[N];
    inline int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    struct edge {
        ll u, v, w;
    }e[M];
    inline bool cmp(edge x, edge y) {
        return x.w < y.w;
    }
    void kk() {
        sort(e + 1 , e + m + 1, cmp);
        rep(i, 1, m) {
            int fx = find(e[i].u), fy = find(e[i].v);
            if(fx == fy) {
                continue;
            }
            ans += e[i].w;
            fa[fx] = fy;
        }
    }
    void main() {
        freopen("road.in", "r", stdin);
        freopen("road.out", "w", stdout);
        ios :: sync_with_stdio(0), cin.tie(0);
        cin >> n >> m >> k;
        rep(i, 1, n) {
            fa[i] = i;
        }
        if(k == 0) {
            rep(i, 1, m) {
                cin >> e[i].u >> e[i].v >> e[i].w;
            }
            kk();
            cout << ans;
        }
        else {
            bool A = true;
            ll dis[1005][1005];
            memset(dis, 0x3f, sizeof dis);
            rep(i, 1, m) {
                cin >> e[i].u >> e[i].v >> e[i].w;
                int x = e[i].u, y = e[i].v;
                dis[x][y] = min(dis[x][y], e[i].w);
                dis[y][x] = min(dis[y][x], e[i].w);
            }
            rep(i, 1, k) {
                cin >> c[k];
                if(c[k]) {
                    A = false;
                }
                rep(j, 1, n) {
                    cin >> a[i][j];
                }
            }
            if(A) {
                rep(i, 1, k) {
                    rep(j, 1, n) {
                        rep(l, j + 1, n) {
                            dis[j][l] = min(dis[j][l], a[i][j] + a[i][l]);
                        }
                    }
                }
                rep(i, 1, n) {
                    rep(j, i + 1, n) {
                        e[++m].u = i;
                        e[m].v = j;
                        e[m].w = dis[i][j];
                    }
                }
                kk();
                cout << ans;
            }
            else {
                cout << 0;
            }
        }
    }
}
int main() {
    Kx :: main();
    return 0;
}