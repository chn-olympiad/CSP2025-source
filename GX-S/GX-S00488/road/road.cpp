#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 15;

int n, m, k, idx, fa[N];
struct node {
    int u, v, w;
};
node e[N<<1];

bool cmp(node a, node b) {
    return a.w < b.w;
}

int mf(int x) {
    int ax = x;
    while (x != fa[x]) {
        x = fa[x];
    }
    while (ax != x) {
        int now = ax;
        ax = fa[ax];
        fa[now] = x;
    }
    return x;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        fa[i] = i;
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    }
    idx = n;
    for (int u = 1; u <= k; u++) {
        fa[u+n] = u + n;
        int c;
        scanf("%d", &c);
        for (int v = 1; v <= n; v++) {
            int w;
            scanf("%d", &w);
            node t;
            t.u = u + n;
            t.v = v;
            t.w = w;
            idx++;
            e[idx] = t;
        }
    }
    sort(e + 1, e + idx + 1, cmp);
    long long ans = 0;
    for (int i = 1; i <= idx; i++) {
        int fu = mf(e[i].u), fv = mf(e[i].v);
        if (fu != fv) {
            fa[fu] = fv;
            ans += e[i].w;
        }
    }
    cout << ans;

    return 0;
}
