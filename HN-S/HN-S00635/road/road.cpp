#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge {
    int u,v,w;

    Edge(int u, int v, int w): u(u), v(v), w(w) {}

    bool operator < (const Edge &other) const {
        return this->w < other.w;
    }

    bool operator > (const Edge &other) const {
        return this->w > other.w;
    }
};

struct Node {
    int id;
    vector<Edge> edge;

    Node(): id(0) {}

    Node(int id): id(id) {}

    void insert(Edge edge) {
        this->edge.push_back(edge);
    }
};

struct Dis {
    int to;
    int w;

    Dis(int to, int w): to(to), w(w) {}
};

#define MAXK 11
#define MAXN 10005

int n,m,k;
int c[MAXK];
int a[MAXK][MAXN];
vector<Node> g;
priority_queue<Edge> tree;
priority_queue<Edge, vector<Edge>, greater<Edge>> edges;

int root[MAXN];

auto get_root(int i) -> int {
    if (root[i] == i) {
        return i;
    }
    int r = get_root(root[i]);
    root[i] = r;
    return r;
}

auto set_root(int i, int j) -> void {
    int i_root = get_root(i);
    int j_root = get_root(j);
    root[i_root] = j_root;
}

auto gen_tree() -> void {
    while (!edges.empty()) {
        Edge current = edges.top();
        edges.pop();

        int u_root = get_root(current.u);
        int v_root = get_root(current.v);
        if (u_root == v_root) continue;
        set_root(u_root, v_root);

        tree.push(current);
    }
}

auto optimize() -> void {

}

auto main() -> int {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d %d %d", &n,&m,&k);

    for (int i=0;i<n;i++) {
        root[i] = i;
        g.emplace_back(i);
    }

    for (int i=0;i<m;i++) {
        int u,v,w;
        scanf("%d %d %d", &u,&v,&w);

        u--;
        v--;

        edges.emplace(u,v,w);
        g[u].insert(Edge(u,v,w));
        g[v].insert(Edge(v,u,w));
    }

    for (int i=0;i<k;i++) {
        scanf("%d", &c[i]);
        for (int j=0;j<n;j++) {
            scanf("%d", &a[i][j]);
        }
    }

    gen_tree();
    optimize();

    int ans = 0;

    while (!tree.empty()) {
        auto edge = tree.top();
        tree.pop();
        ans += edge.w;
    }

    printf("%d\n", ans);

    return 0;
}
