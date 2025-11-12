#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 5, MAXM = 2e6 + 5;
const long long inf = 2e18 + 5;
int n, m, k;
long long ans;
long long dis[MAXN];
long long knode[20][MAXN];
struct Edge { int to, next; long long va; } edge[MAXM * 2];
bool vis[MAXN];
int fir_edge[MAXN];
int edge_cnt;
void make_edge(int u, int v, long long va) {
    edge[++edge_cnt] = {v, fir_edge[u], va};
    fir_edge[u] = edge_cnt;
}

struct tr_node {
    int ls, rs, id;
} tr[MAXN * 200];
int tr_cnt;
void update(int type, int p) {
    int ls = tr[p].ls, rs = tr[p].rs;
    if (knode[type][tr[ls].id] < knode[type][tr[rs].id]) {
        tr[p].id = tr[ls].id;
    } else {
        tr[p].id = tr[rs].id;
    }
}
int make_tree(int type, int p, int l = 1, int r = n) {
    if (p == 0) p = ++tr_cnt;
    if (l == r) {
        tr[p].id = l;
    } else {
        int mid = (l + r) >> 1;
        int ls = tr[p].ls, rs = tr[p].rs;
        tr[p].ls = make_tree(type, ls, l, mid);
        tr[p].rs = make_tree(type, rs, mid + 1, r);
        update(type, p);
    }
    return p;
}
void change(int type, int pos, int p, int l = 1, int r = n) {
    if (l == r) {
        tr[p].id = n + 2;
    } else {
        int mid = (l + r) >> 1;
        int ls = tr[p].ls, rs = tr[p].rs;
        if (pos <= mid) change(type, pos, ls, l, mid);
        else change(type, pos, rs, mid + 1, r);
        update(type, p);
    }
}
int root[20];

void del_node(int pos) {
    for (int i = 1; i <= k; i++) {
        change(i, pos, root[i]);
    }
}
long long out_va[20];
void add_node(int pos) {
    for (int i = 1; i <= k; i++) {
        out_va[i] = min(out_va[i], knode[i][pos]);
    }
}

void init() {
    for (int i = 1; i <= k; i++) {
        root[i] = make_tree(i, 0);
        out_va[i] = inf;
    }
    del_node(1);
    add_node(1);
    for (int i = 1; i <= n; i++) {
        dis[i] = inf;
    }
}


void get_ans() {
    priority_queue<pair<long long, int>, vector<pair<long long ,int> > , greater<pair<long long, int> > > pq; // dis, id;
    vis[1] = true; dis[1] = 0;
    for (int i = fir_edge[1]; i != 0; i = edge[i].next) {
        int v = edge[i].to;
        if (edge[i].va < dis[v]) {
            dis[v] = edge[i].va;
            pq.push(make_pair(dis[v], v));
        }
    }
    while (!pq.empty()) {
        int id = pq.top().second; pq.pop();
        if (vis[id]) continue;
        long long add_va = inf;
        int add_id;
        // printf("check \n");
        for (int i = 1; i <= k; i++) {
            long long temp = knode[i][0] + out_va[i] + knode[i][tr[root[i]].id];
            // printf("%lld  %lld  %lld\n", knode[i][0], out_va[i], knode[i][tr[root[i]].id]);
            if (temp < add_va) {
                add_va = temp;
                add_id = i;
            }
        }
        // printf("add_id %d add_va %lld\n", add_id, add_va);
        if (add_va <= dis[id]) {
            pq.push(make_pair(dis[id], id));
            knode[add_id][0] = 0;
            out_va[add_id] = 0;
            int v = tr[root[add_id]].id;
            // printf("type1 add_id %d v %d\n", add_id, v);
            vis[v] = true;
            del_node(v);
            add_node(v);
            ans += add_va;
            for (int i = fir_edge[v]; i != 0; i = edge[i].next) {
                int to = edge[i].to;
                if (vis[to]) continue;
                if (dis[to] > edge[i].va) {
                    dis[to] = edge[i].va;
                    pq.push(make_pair(dis[to], to));
                }
            }
        } else {
            // printf("type2 id %d\n", id);
            vis[id] = true;
            del_node(id);
            add_node(id);
            ans += dis[id];
            for (int i = fir_edge[id]; i != 0; i = edge[i].next) {
                int to = edge[i].to;
                if (vis[to]) continue;
                if (dis[to] > edge[i].va) {
                    dis[to] = edge[i].va;
                    pq.push(make_pair(dis[to], to));
                }
            }
        }
    }
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int u, v; long long w; scanf("%d %d %lld", &u, &v, &w);
        make_edge(u, v, w);
        make_edge(v, u, w);
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%lld", &knode[i][j]);
        }
        knode[i][n + 2] = inf;
    }
    init();
    get_ans();
    printf("%lld", ans);
    return 0;
}