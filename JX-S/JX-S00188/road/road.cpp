#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+30, M = 1e6+30;

struct Node {
    int t, w;
};

int kw[15][N];
int cw[15];

vector<Node> g[N];
int n, m, k;

bool vst[N];
long long dist[N];

void dj(int x) {
    memset(dist, 0x3f, sizeof dist);
    memset(vst, 0, sizeof vst);

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, x});
    dist[x] = 0;
    vst[x] = true;

    while (!q.empty()) {
        pair<int, int> u = q.top(); q.pop();

        for (Node v: g[u.second]) {
            if (vst[v.t]) continue;
            vst[v.t] = true;

            if (dist[v.t] > dist[u.second] + v.w) {
                dist[v.t] = dist[u.second] + v.w;
                q.push({dist[v.t], v.t});
            }
        }
    }
}
long long ans = 0x3f3f3f3f3f3f3f3f;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    #ifndef LOCAL
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    #endif // LOCAL

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int ut, vt, w;
        cin >> ut >> vt >> w;
        Node u = {ut, w};
        Node v = {vt, w};
        g[u.t].push_back(v);
        g[v.t].push_back(u);
    }

    for (int i = 1; i <= k; i++) {
        cin >> cw[i];
        for (int j = 1; j <= n; j++) {
            cin >> kw[i][j];
        }
    }

    for (int i = 0; i <= (2 << k) - 1; i++) {
        int ttt = 0;
        for (int j = 0; j < k; j++) {
            bool t = (i >> j) & 1;
            if (t) {
                ttt += cw[j+1];
                for (int ZhXi = 1; ZhXi <= n; ZhXi++) {
                    Node u = {j + n + 1, kw[j + 1][ZhXi]};
                    Node v = {ZhXi, kw[j + 1][ZhXi]};
                    g[u.t].push_back(v);
                    g[v.t].push_back(u);
                }
            }
        }
        dj(1);
        ans = min(ans, dist[n] + ttt);
    }

    cout << ans << '\n';

    return 0;
}
