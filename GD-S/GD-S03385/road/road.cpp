#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#define MAXN 10100
#define MAXK 15
using namespace std;

struct Edge {
    int u, v, w;
    Edge() {};
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {};
    bool operator>(const Edge& edge) const { return w > edge.w; }
    bool operator<(const Edge& edge) const { return w < edge.w; }
};

int n, m, k;
vector<Edge> edges;
long long ans = 0;

int c[MAXK];
int a[MAXK][MAXN];

priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
int fa[MAXN];
int find(int x) {
    if (fa[x] == x)
        return x;
    return (fa[x] = find(fa[x]));
}
void merge(int x, int y) {
    int f1 = find(x), f2 = find(y);
    if (f1 != f2)
        fa[f1] = f2;
}
long long kruskal() {
    long long cost = 0;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    while (!pq.empty()) {
        int u = pq.top().u, v = pq.top().v, w = pq.top().w;
        pq.pop();

        if (find(u) != find(v)) {
			merge(u, v);
			cost += w;
        }
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
    
    for (Edge e : edges)
        pq.push(e);
    ans = kruskal();

    // 依次把每个乡村都加入图的副本中，构建最小生成树
    // 如果联通该乡村的代价比原来的代价要低，就把图更新
    // 乡村的编号为 n + i
    for (int i = 1; i <= k; i++) {
        for (Edge e : edges)
            pq.push(e);
        for (int j = 1; j <= n; j++)
            pq.push(Edge(n + i, j, a[i][j]));
        long long new_cost = kruskal() + c[i];
        if (ans >= new_cost) {
            for (int j = 1; j <= n; j++)
                edges.push_back(Edge(n + i, j, a[i][j]));
            ans = new_cost;
        }
    }

	cout << ans << '\n';

    return 0;
}