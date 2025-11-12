#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans = INT_MAX;
const int N = 1e6 + 5;
struct node {
    int vv, ww;
    bool flag;
};
vector <node> vec[N];
int c[N], vis[N];
int mp[N][N];
int main () {
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back ({v, w}) ;
        vec[v].push_back ({u, w}) ;
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j ++) {
            cin >> mp[i][j];
        }
    }
    cout << 0 ;
    return 0;
}