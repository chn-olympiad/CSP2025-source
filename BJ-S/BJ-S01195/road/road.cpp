#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e4 + 1;
const int MAXM = 1e5 + 1;

struct Node { int u, v, w; } e[MAXN];

int n, m, k, ans, fa[MAXN];

bool cmp(Node& a, Node& b) { return a.w < b.w; }

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

bool merge(int x, int y) {
    int u = fa[x], v = fa[y];
    if (u != v) fa[u] = v;
    else return false;
    return true;
}

//bool check() {
//    int cnt = 0;
//    for (int i = 1; i <= n; i++) cnt += fa[i] == i;
//    return cnt == 1;
//}

void kruskal() {
    int tot = 0;
    for (int i = 1; i <= n; i++) fa[i] = i;
    sort(e + 1, e + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (merge(u, v)) {
            ans += w;
            tot++;
        }
        if (tot == n - 1) break;
    }
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1, u, v, w; i <= n; i++) {
        scanf("%d%d%d", &u, &v, &w);
        e[i] = Node {u, v, w};
    }
    for (int i = 1, c; i <= k; i++) {
        scanf("%d", &c);
        for (int j = 1, w; j <= n; j++) {
            scanf("%d", &w);
            //e.emplace_back(i, j, w, 1, c);
        }
    }
    kruskal();
    printf("%d", ans);
    return 0;
}

/*
看得出来是 MST，但是特殊性质真不会写了，只能码一个 Kruskal 板子拿部分分
码了个 1.5KB 的史山
期望得分：48
完成时间：1h
*/
