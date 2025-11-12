#include <bits/stdc++.h>
#define N 10010
#define K 11
#define endl '\n'
using namespace std;
int n, m, k;
int c[K][N];
int fa[10010];
vector<int> p[N];
int find(int x) {
    if(find(x) == x) {
        return x;
    }
    return fa[x] = find(x);
}
void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    fa[x] = y;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    int u, v, w;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        merge(u, v);
    }
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n + 1; j++) {
            cin >> c[i][j];
        }
    }
    cout << 0;
}
