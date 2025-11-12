#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const bool DB = 0;
int n, m, k;
long long int ans;
struct edg{
    int u, v, w;
} e[1100005];
bool cmp(edg x, edg y) {
    return x.w <= y.w;
}

int pre[10005];
int rt(int u) {
    if (u == pre[u]) {
        return u;
    }
    pre[u] = rt(pre[u]);
    return pre[u];
}

void kruskal() {
    int u, v, w;
    for (int i = 1; i <= m; ++i) {
        u = e[i].u; v = e[i].v; w = e[i].w;
        u = rt(u); v = rt(v);
        if (u != v) {
            ans += w;
            pre[u] = v;
        }
    }
}

int main() {
    if (!DB) {
        freopen("road.in", "r", stdin);
        freopen("road.out", "w", stdout);
    }
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        pre[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    }
    int c;
    for (int u = 1; u <= k; ++u) {
        cin >> c;
        if (c == 0) {
            for (int v = 1; v <= n; ++v) {
                ++m;
                cin >> e[m].w;
                e[m].u = u; e[m].v = v;
            }
        }
    }
    sort(e + 1, e + m + 1, cmp);
    kruskal();
    cout << ans;
}
