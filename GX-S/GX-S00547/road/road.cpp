#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+9, M = 1e6+9;
typedef long long ll;

int n, m, K, head[N], fa[N], c[N], a[15][N];
struct edge{
    ll x, y, z;
    bool operator<(const edge B) const {return z < B.z;}
}e[M*2], E[M];
int get(int x) {
    return x == fa[x]? x: fa[x] = get(fa[x]);
}
ll kruskal() {
    for (int i = 1; i <= n; i++) {fa[i] = i;}
    ll ret = 0;
    sort(e+1, e+m+1);
    for (int i = 1; i <= m; i++) {
        int x= e[i].x, y = e[i].y; ll z = e[i].z;
        if (get(x) == get(y)) continue;
        fa[get(x)] = get(y);
        ret += z;
    }
    return ret;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> K;
    for (int i = 1, x, y, w; i <= m; i++) {
        cin >> x >> y >> w;
        e[i] = (edge){x, y, w};
    }
    for (int i = 1; i <= K; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (!c[i]) {e[++m] = (edge){i, j, a[i][j]};}
        }
    }
    cout << kruskal();
    return 0;
}
