#include <bits/stdc++.h>
#define rep(x, y, z) for (int x = y; x <= z; x++)
using namespace std;
using ll = long long;
using pli = pair<ll, int>;
constexpr int MAXN = 1e4 + 514, MAXM = 1e6 + 514;

namespace Otaku {
    int n, m, k;
    ll a[11][MAXN], c[11], ans = 0x3f3f3f3f3f3f3f3f;
    int fa[MAXN], ze, tot, to[MAXN];
    pair<int, int> ed[MAXM * 2];

    priority_queue<pli, vector<pli>, greater<pli>> q;

    int find(int x) {
        if (fa[x] == x) return x;
        fa[x]=find(fa[x]);
        return fa[x];
    }

    struct node {
        int v;
        ll w;
    };

    vector<node> g[MAXN];

    void solvekz() {
        ll sum = 0;
        while (!q.empty()) {
            ll w = q.top().first;
            int id = q.top().second;
            q.pop();

            int x = ed[id].first;
            int y = ed[id].second;

            if (find(x) == find(y)) continue;
            else {
                sum += w;
                y = find(y);
                fa[y]=x;
            }
        }

        cout << sum;
    }

    void init() {
        cin >> n >> m >> k;
        tot= m;
        rep(i, 1, n + k) fa[i] = i;
        rep(i, 1, m) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            ed[i].first = u;
            ed[i].second = v;
            q.push({w, i});
        }

        rep(i, 1, k) {
            cin >> c[i];
            if (c[i]==0)ze++;
            rep(j, 1, n) {
                cin >> a[i][j];
                if (c[i] == 0 && a[i][j] == 0) {
                    to[i]=j;
                }
            }
            rep(j, 1, n) {
                ++tot;
                ed[tot].first=to[i];
                ed[tot].second = j;
                q.push({a[i][j], tot});
            }
        }

        if (k == 0) {
            solvekz();
            return;
        }

        else if (ze == k) {
            solvekz();
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    Otaku::init();

    return 0;
}