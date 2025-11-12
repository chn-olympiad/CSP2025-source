# include <bits/stdc++.h>
# define endl "\n"
# define y1 fccmath
# define rei for (int i = 1; i <= n; ++i)
using namespace std;
const int maxn = 11451;
int n, m, k, ans; //, a[maxn];
vector<pair<int,int>> g[maxn];
int vis[maxn];
void krusual(int x) {
    for (auto [v,w] : g[x]) {
        if (!vis[v]) {
            vis[v]++;
            ans += w;
            krusual(v);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> u >>v >>w;
        g[u].push_back({v, w});
        g[v].push_back({u,w});
        //ans+=w;
    }
    krusual(1);
    cout << ans;
    return 0;
}
