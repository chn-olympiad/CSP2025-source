#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 100;
const int M = 1e6 * 2;
const int inf = 1e9;

int n, m, k;
int h[N], w[M], to[M], ne[M], tot = 0;
int d[N];
bool used[M];

void add(int a, int b, int c) {
    to[++tot] = b, w[tot] = c, ne[tot] = h[a], h[a] = tot;
}
int cnt = 0, ans = 0;

void prim(int s) {
    for (int i = 1; i <= n; i++) d[i] = inf;
    ans = 0;
    d[s] = 0;
    priority_queue<pair<int, int>> q;
    while (!q.empty()) {
        auto ed = q.top(); q.pop();
        int x = ed.second;
        if  (x > n) {
            if (x > 2 * n && !used[x]) continue;
            used[x] = true;
        }
        for (int i = h[x]; i; i = ne[i]) {
            int y = to[i], ww = w[i];
            if (d[y] > ww) {
                d[y] = ww;
                ans += d[y];
                q.push({-d[y], y});
            }
        }

    }
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);    
    cin >> n >> m >> k;
    for (int i = 1, a, b, c; i <= m; i++) {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, c, a); 
    }
    cnt = n;
    for (int i = 1; i <= k; i++) {
        int u, k;
        cin >> u >> k;
        u = ++cnt;
        for (int i = 1, ww; i <= n; i++) {
            cin >> ww;
            add(u, i, ww + k);
            add(i, u, ww + k);
            add(u + n, i, ww);
            add(i + n, u, ww);
        }
    }
    prim(1);
    cout << ans << endl;
    return 0;
}