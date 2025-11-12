#include <bits/stdc++.h>
using namespace std;

int n, m, k, m2, a[11][10011], b[10011], fa[10011], siz[10011];
vector <pair <int, int>> e2[10011], edges[10011];
vector <int> v[10011];

struct edge {
    int u, v, w;
} e[2000001], e3[2000001];

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

int findset(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = findset(fa[x]);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &a[i][0]);
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    }
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        int fx = findset(e[i].u), fy = findset(e[i].v);
        if (fx == fy)
            continue;
        fa[fx] = fy;
        e2[e[i].u].push_back({e[i].v, e[i].w});
        e2[e[i].v].push_back({e[i].u, e[i].w});
    }
    long long sum = 0;
    for (int i = 1; i <= k; i++) {
        sum += a[i][0];
        for (int j = 1; j <= n; j++)
            e[++m] = {n + i, j, a[i][j]};
    }
    for (int i = 1; i <= n + k; i++)
        fa[i] = i;
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        int fx = findset(e[i].u), fy = findset(e[i].v);
        if (fx == fy)
            continue;
        fa[fx] = fy;
        edges[e[i].u].push_back({e[i].v, e[i].w});
        edges[e[i].v].push_back({e[i].u, e[i].w});
        sum += e[i].w;
    }
    long long ans = sum;
    for (int i = 0; i < (1 << k); i++) {
        long long sum2 = sum;
        for (int j = 1; j <= k; j++)
            if (!(i & (1 << (j - 1)))) {
                sum2 -= a[j][0];
                for (auto k : edges[n + j])
                    sum2 -= k.second;
            }
        memset(b, 0, sizeof(b));
        queue <int> q;
        int t = 0;
        for (int j = 1; j <= n + k; j++) {
            if ((j > n && !(i & (1 << (j - n - 1)))) || b[j])
                continue;
            b[j] = ++t;
            v[t] = vector <int>(1, j);
            q.push(j);
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (auto y : edges[x]) {
                    if ((y.first > n && !(i & (1 << (y.first - n - 1)))) || b[y.first])
                        continue;
                    b[y.first] = t;
                    v[t].push_back(y.first);
                    q.push(y.first);
                }
            }
        }
        m2 = 0;
        for (int j = 1; j <= t; j++)
            for (auto k : v[j])
                for (auto l : e2[k])
                    if (j != b[l.first])
                        e3[++m2] = {j, b[l.first], l.second};
        for (int j = 1; j <= k; j++)
            if (i & (1 << (j - 1)))
                for (int k = 1; k <= n; k++)
                    if (b[k] != b[j + n])
                        e3[++m2] = {b[j + n], b[k], a[j][k]};
        sort(e3 + 1, e3 + m2 + 1, cmp);
        for (int j = 1; j <= t; j++) {
            fa[j] = j;
            siz[j] = 1;
        }
        for (int j = 1; j <= m2; j++) {
            int fx = findset(e3[j].u), fy = findset(e3[j].v);
            if (fx == fy)
                continue;
            if (siz[fx] < siz[fy])
                swap(fx, fy);
            fa[fx] = fy;
            siz[fy] += fx;
            sum2 += e3[j].w;
        }
        ans = min(ans, sum2);
    }
    printf("%lld", ans);
}