#include <bits/stdc++.h>
using namespace std;

long long n, m, k, ans, idx = 0;
int f[100005];

int find (int x) {
    if (f[x] == x) {
        return x;
    }
    return f[x] = find(f[x]);
}

struct road {
    int u, v, w;
    bool operator > (const road other) const {
        return w > other.w;
    }
};

road a[1000005];

bool cmp (road a, road b) {
    return a.w < b.w;
}

void kru () {
    int cnt = 0, i = 1;
    for (int x = 1; x <= n; ++x) {
        f[x] = x;
    }
    while (cnt < (n - 1)) {
        road nr = a[i];
        int fx = find(nr.u), fy = find(nr.v);
        if (fx != fy) {
            ans += nr.w;
            f[fx] = fy;
            cnt++;
        }
        i++;
    }
}

vector <pair <int, int>> g[100005];

void kru2 () {
    int cnt = k - 1, i = 1;
    for (int x = 1; x <= n; ++x) {
        f[x] = x;
    }
    for (int i = 1; i <= k; ++i) {
        f[i + n] = i + n;
    }
    while (cnt < (n + k - 1)) {
        road nr = a[i];
        int fx = find(nr.u), fy = find(nr.v);
        if (fx != fy) {
            ans += nr.w;
            f[fx] = fy;
            cnt++;
        }
        i++;
    }
}

int main () {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].u >> a[i].v >> a[i].w;
        g[a[i].u].push_back({a[i].v, a[i].w});
        g[a[i].v].push_back({a[i].u, a[i].w});
    }
    idx = m;
    if (k == 0) {
        sort(a + 1, a + n + 1, cmp);
        kru();
        cout << ans;
        return 0;
    }
    int idx = n;
    for (int i = 1; i <= k; ++i) {
        int c;
        cin >> c;
        for (int j = 1; j <= n; ++j) {
            g[j].push_back({n + i, 0});
            int p;
            cin >> p;
            g[n + i].push_back({j, p});
            a[++idx].u = n + i;
            a[idx].v = j;
            a[idx].w = p;
        }
    }
    sort(a + 1, a + idx + 1, cmp);
    kru2();
    cout << ans;
    return 0;
}
