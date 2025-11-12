#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5, M = 2e6 + 5, inf = 1e18;
int n, m, k, c[N], cnt, a[15][N], fa[N], sz[N], ans;
bool vis[N];
struct node {
    int u, v, w, id;
    bool operator < (const node b) const {
        return w < b.w;
    }
} e[M], t[M];
int getfa(int x) {
    return (fa[x] == x ? x : fa[x] = getfa(fa[x]));
}
void calc(int x, int y) {
     x = getfa(x), y = getfa(y);
     if (x == y) return;
     if (sz[x] > sz[y]) swap(x, y);
     fa[x] = y, sz[y] += sz[x];
}
int getans1() {
    for (int i = 1; i <= k; i++) {
        int fl = 0, minn = inf;
        for (int j = 1; j <= n; j++) {
            if (a[i][j] < minn) minn = a[i][j], fl = j;
        }
        for (int j = 1; j <= n; j++)
            if (j != fl) t[++cnt] =
            {j, fl, a[i][j] + a[i][fl] + c[i], i};
    }
    sort(e + 1, e + m + 1), sort(t + 1, t + cnt + 1);
    for (int i = 1; i <= n; i++) fa[i] = i;
    int pos1 = 1, pos2 = 1;
    for (int i = 1; i <= m + cnt; i++) {
        if (pos2 > cnt || (pos1 <= m && e[pos1] < t[pos2])) {
            if (getfa(e[pos1].u) ==
            getfa(e[pos1].v)) { pos1++; continue; }
            calc(e[pos1].u, e[pos1].v), ans += e[pos1].w;
            pos1++;
        } else {
            if (getfa(t[pos2].u) ==
            getfa(t[pos2].v)) { pos2++; continue; }
            if (!vis[t[pos2].id]) {
                for (int i = pos2 + 1; i <= cnt; i++)
                    if (t[i].id == t[pos2].id)
                        t[i].w -= c[t[pos2].id];
                if (pos2 < cnt) sort(t +
                pos2 + 1, t + cnt + 1);
                vis[t[pos2].id] = 1;
            }
            calc(t[pos2].u, t[pos2].v), ans += t[pos2].w;
            pos2++;
        }
    }
    return ans;
}
int getans2() {
    ans = inf;
    int pos = m;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            e[++pos] = {n + i, j, a[i][j], i};
    sort(e + 1, e + pos + 1);
    for (int i = 0; i < (1 << k); i++) {
        int sum = 0, cur = 0;
        for (int j = 1; j <= k; j++)
            if ((i >> (j - 1)) & 1) sum += c[j];
        for (int j = 1; j <= pos; j++) {
            int now = e[j].id;
            if ((!now) || ((i >> (now - 1)) & 1))
                t[++cur] = e[j];
        }
        for (int j = 1; j <= n + k; j++)
            fa[j] = j, sz[j] = 1;
        for (int j = 1; j <= pos; j++) {
            if (getfa(t[j].u) == getfa(t[j].v)) continue;
            calc(t[j].u, t[j].v), sum += t[j].w;
        }
        ans = min(ans, sum);
    }
    return ans;
}
int getans3() {
    int pos = m;
    for (int i = 1; i <= k; i++) {
        int cur = 0;
        for (int j = 1; j <= n; j++)
            if (!a[i][j]) cur = j;
        for (int j = 1; j <= n; j++)
            if (j != cur) e[++pos] = {cur, j, a[i][j], 0};
    }
    sort(e + 1, e + pos + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i, sz[i] = 1;
    for (int i = 1; i <= pos; i++) {
        if (getfa(e[i].u) == getfa(e[i].v)) continue;
        calc(e[i].u, e[i].v), ans += e[i].w;
    }
    return ans;
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    bool fl = 1;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        if (c[i]) fl = 0;
        bool now = 0;
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (!a[i][j]) now = 1;
        }
        if (!now) fl = 0;
    }
    if (fl) cout << getans3() << '\n';
    else if (k <= 5) cout << getans2() << '\n';
    else if (n <= 100000) cout << getans2() << '\n';
    else cout << getans1() << '\n';
    return 0;
}
