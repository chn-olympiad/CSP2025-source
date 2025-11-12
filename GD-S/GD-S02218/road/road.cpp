#include <bits/stdc++.h>
using namespace std;
const int mn = 1e6 + 10;
int cost = 0;
int n, m, k, ui, vi, wi, cj, aj;
struct edge {
    int u, v, w;
    bool operator<(const edge &other) const {
        return w < other.w;
    }
    bool operator>(const edge &other) const {
        return w > other.w;
    }
};
priority_queue<edge, vector<edge>, greater<edge>> edges;
vector<int> fa(mn);
int get(int x) {
    if (fa[x] == x) {
        return x;
    }
    return fa[x] = get(fa[x]);
}
void merge(int x, int y) {
    if (get(x) != get(y)) {
        fa[get(x)] = get(y);
    }
}
void preprocess() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    preprocess();
    for (int i = 1; i <= m; i++) {
        cin >> ui >> vi >> wi;
        edges.push({ui, vi, wi});
    }
    vector<int> cjs(k + 1);
    for (int j = 1; j <= k; j++) {
        cin >> cjs[j];
        for (int ji = 1; ji <= n; ji++) {
            cin >> aj;
            edges.push({j, ji, aj + cjs[j]});
        }
    }
    int edgecnt = 0;
    while (edgecnt < n - 1 && !edges.empty()) {
        edge e = edges.top();
        edges.pop();
        if (get(e.u) != get(e.v)) {
            merge(e.u, e.v);
            ++ edgecnt;
            cost += e.w;
        }
    }
    cout << cost << "\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}