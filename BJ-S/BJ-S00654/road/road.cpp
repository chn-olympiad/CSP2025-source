// Partial solution - 40 pts
#include <bits/stdc++.h>
using namespace std;

const int K = 12, N = 10005, M = 4000005;
int n, m, k, sd;

int c[K], a[K][N];
struct node {
    int u, v, w;
} e[M];

bool cmp(node x, node y) {
    return x.w < y.w;
}

int fa[N];
void init() {
    for(int i = 1; i <= n; i++) fa[i] = i;
}

int root(int x) {
    return fa[x] == x ? x : (fa[x] = root(fa[x]));
}

void con(int x, int y) {
    fa[root(x)] = root(y);
}

int kruscal() {
    int cnt = 0, w = 0;
    sort(e + 1, e + m + 1, cmp);
    for(int i = 1; i <= m; i++) {
        int u = e[i].u, v = e[i].v;
        if(root(u) != root(v)) {
            con(u, v);
            cnt++; w += e[i].w;
            if(cnt == n - 1) break;
        }
    }
    return w;
}
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    init();
    for(int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    if(!k) {
        cout << kruscal() << endl;
        return 0;
    }
    vector<int> vec;
    for(int i = 1; i <= k; i++) {
        vec.clear();
        cin >> c[i];
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
        for(int j = 1; j <= n; j++) {
            if(a[i][j] == 0) {
                vec.push_back(j);
            }
        }
        for(int i = 0; i < vec.size() - 1; i++) {
            e[++m] = {vec[i], vec[i + 1], 0};
        }
        if(vec.size()) {
            for(int k = 1; k <= n; k++) {
                if(k != vec[0]) e[++m] = {vec[0], k, a[i][k]};
            }
        }
    }
    cout << kruscal() << endl;
    return 0;
}
