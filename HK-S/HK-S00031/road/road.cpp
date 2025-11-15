#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll p[100010];

ll find(int u) {
    if (p[u] == u) return u;
    p[u] = find(p[u]);
    return p[u];
}

vector <pair<ll, pair<ll, ll>>> pq;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    for (ll i = 0; i < 100000; i++) p[i] = i;
    ll n, m, c; cin >> n >> m >> c;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        pq.push_back({w, {u, v}});
    }
    vector <vector <int>> cc(c, vector<int> (n));
    for (int i = 0; i < c; i++) {
        int tmp; cin >> tmp;
        for (int j = 0; j < n; j++) cin >> cc[i][j];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            ll aa = 1e9, xx = 0, yy = 0;
            for (ll k = 0; k < c; i++) {
                if (aa < cc[k][i] + cc[k][j]) {
                    aa = cc[k][i] + cc[k][j];
                    xx = i, yy = j;
                }
                /*
                aa = min(cc[k][i] + cc[k][j], aa);
                xx = i, yy = j;
                */
            }
            pq.push_back({aa, {xx, yy}});
        }
    }
    sort(pq.begin(), pq.end());
    ll ans = 0;
    for (int i = 0; i < pq.size(); i++) {
        int x = find(pq[i].second.first), y = find(pq[i].second.second);
        if (x == y) continue;
        ans += pq[i].first;
        p[max(x, y)] = min(x, y); 
    }
    cout << ans << "\n";
}