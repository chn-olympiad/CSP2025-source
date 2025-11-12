#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

struct Node;
struct Edge;

struct Edge {
    int w;
    Node* nxt;
};

struct Node {
    vector<Edge> edge;
};

Node* node[N];
Node* village[N];
int fa[N];

int find(int x) {
    return fa[x] == x ? x : x = find(fa[x]);
}

void prim() {
    int id = -1, mi = 0;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge tmp;
        tmp.nxt = node[v];
        tmp.w = w;
        node[u]->edge.push_back(tmp);
        tmp.nxt = node[u];
        node[v]->edge.push_back(tmp);
    }

    for (int i = 0; i < k; i++) {
        int c, a[10000];
        cin >> c;
        for (int j = 1; j <= n; j++) {
            cin >> a[j];
            Edge tmp;
            tmp.nxt = node[j];
            tmp.w = a[j];
            village[c]->edge.push_back(tmp);
            tmp.nxt = village[c];
            node[j]->edge.push_back(tmp);
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
