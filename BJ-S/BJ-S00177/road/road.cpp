#include <bits/stdc++.h>
#define int long long
using namespace std;
template <typename T>
inline void read(T &x) {
    bool f = 0;
    char c = getchar();
    x = 0;
    while (c < '0' || c > '9') f |= (c == '-'), c = getchar();
    while ('0' <= c && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    if (f) x = -x;
}
const int N = 1e4 + 10 + 5, M = 1e6 + 5;
int n, m, k, fa[N], sz[N];
int Find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = Find(fa[x]);
}
inline bool Merge(int x, int y) {
    x = Find(x), y = Find(y);
    if (x == y) return 0;
    if (sz[x] > sz[y]) swap(x, y);
    fa[x] = y, sz[y] += sz[x];
    return 1;
}
struct road {
    int x, y, z;
    inline void input() {
        read(x), read(y), read(z);
    }
    inline bool operator < (const road &cmp) const {
        return z > cmp.z;
    }
} r[M];
struct cmp {
    inline bool operator () (const road &l, const road &r) const {
        return l.z < r.z;
    }
};
vector<int> v;
int c[15], a[15][N];
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    read(n), read(m), read(k);
    for (int i = 1; i <= m; i++)
        r[i].input();
    for (int j = 0; j < k; j++) {
        read(c[j]);
        for (int i = 1; i <= n; i++)
            read(a[j][i]);
    }
    for (int i = 1; i <= n; i++)
        fa[i] = i, sz[i] = 1;
    sort(r + 1, r + m + 1, cmp());
    for (int i = 1; i <= m; i++)
        if (Merge(r[i].x, r[i].y))
            v.push_back(i);
    int ans = 9e18;
    for (int s = 0; s < (1 << k); s++) {
        int res = 0;
        priority_queue<road> q;
        for (int i : v) q.push(r[i]);
        int num = 0;
        for (int i = 0; i < k; i++)
            if (s >> i & 1) {
                res += c[i], num++;
                for (int j = 1; j <= n; j++)
                    q.push({n+1+i, j, a[i][j]});
            }
        int cnt = 0;
        for (int i = 1; i <= n + k; i++) fa[i] = i, sz[i] = 1;
        while (!q.empty() && cnt < n+num-1) {
            road r = q.top(); q.pop();
            if (Merge(r.x, r.y)) {
                cnt++;
                res += r.z;
            }
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}
