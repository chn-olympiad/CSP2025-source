#include <bits/stdc++.h>

using namespace std;

struct edge {
    int x, y;
    long long w;
};

int n, m, k;
vector<edge> edges;
vector<edge> t[15];
vector<edge> tmp[2];
int f[10015];
int a[10005];

int find(int x) {
    return (f[x] == x ? x : f[x] = find(f[x]));
    // if (f[x] == x) return x;
    // return f[x] = find(f[x]);
}

int main() {
    ios::sync_with_stdio(false);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    // scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n + k; i ++) f[i] = i;
    for (int i = 1; i <= m; i ++) {
        int x, y;
        long long z;
        cin >> x >> y >> z;
        // scanf("%d%d%lld", &x, &y, &z);
        edges.push_back({x, y, z});
    }
    for (int i = 1; i <= k; i ++) {
        int x;
        cin >> x;
        // scanf("%d", &x);
        a[i] = x;
        for (int j = 1; j <= n; j ++) {
            long long z;
            cin >> z;
            // scanf("%lld", &z);
            t[i].push_back({n + i, j, z});
        }
        sort(t[i].begin(), t[i].end(), [&](edge x, edge y) {
            return x.w < y.w;
        });
    }
    sort(edges.begin(), edges.end(), [&](edge x, edge y) {
        return x.w < y.w;
    });
    // cout << "Init" << endl;
    for (int i = 0; i < m; i ++) {
        if (find(edges[i].x) == find(edges[i].y)) continue;
        f[find(edges[i].x)] = find(edges[i].y);
        t[0].push_back(edges[i]);
    }
    long long ans = 0x3f3f3f3f3f3f3f3fll;
    for (int s = 1; s < (1 << (k + 1)); s += 2) {
        for (int i = 1; i <= n + k; i ++) f[i] = i;
        tmp[0].clear();
        tmp[1].clear();
        // vector<edge> tmp;
        bool flag = 0;
        long long sum = 0;
        for (int i = 0; i <= k; i ++) {
            if (s & (1 << i)) {
                sum += a[i];
                // for (edge j : t[i]) tmp.push_back(j);
                tmp[!flag].resize(tmp[flag].size() + t[i].size());
                merge(tmp[flag].begin(), tmp[flag].end(), t[i].begin(), t[i].end(), tmp[!flag].begin(), [&](const edge x, const edge y) {
                    return x.w < y.w;
                });
                flag = !flag;
            }
        }
        // sort(tmp.begin(), tmp.end(), [&](edge x, edge y) {
        //     return x.w < y.w;
        // });
        for (edge e : tmp[flag]) {
            if (find(e.x) == find(e.y)) continue;
            f[find(e.x)] = find(e.y);
            sum += e.w;
        }
        // cout << s << ": " << sum << endl;
        ans = min(ans, sum);
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}