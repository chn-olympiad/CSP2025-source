#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct ed {
    ll u, v, w;
    bool operator < (ed o) const {
        return w < o.w;
    }
}g[10000005];
int n, m, fa[10005], k;
int find(int x) {
    return (fa[x] == x ? x : find(fa[x]));
}
ll krus() {
    fa[1] = 1;
    ll cnt = 0, ans = 0;
    for (int i = 1; i <= m && cnt < n; i++) {
        int x = find(g[i].u), y =find(g[i].v) ;
        if (x != y) {
            //cout << g[i].u << " " << g[i].v << endl;
            ans += g[i].w;
            fa[y] = g[i].u;
            cnt++;
        }
    }
    return ans;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= 10000; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[i] = {u, v, w};
    }
    sort(g+1, g+1+m);
    cout << krus();
    return 0;
}
