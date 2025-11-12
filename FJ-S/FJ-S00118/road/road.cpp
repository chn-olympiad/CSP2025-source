#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 10;
const int M = 2e6 + 10;
const int K = 15;
int n, m, k, ans;
int a[K][N], c[K];
int fa[N], siz[N];
struct node {
    int x, y, z;
    bool operator<(const node &ert) const {
        return z < ert.z;
    }
} e[M], E[M];
inline int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void solve(int S) {
    int res = 0, ecnt = 0, num = n;
    for (int i = 1; i <= k; ++i)
        if (S & (1 << (i - 1))) {
            res += c[i], num++;
            for (int j = 1; j <= n; ++j) E[++ecnt] = {num, j, a[i][j]};
        }
    if (res >= ans) return;
    for (int i = 1; i <= m; ++i) E[++ecnt] = e[i];
    for (int i = 1; i <= num; ++i) fa[i] = i, siz[i] = 1;
    sort(E + 1, E + ecnt + 1);
    int cnt = num;
    for (int i = 1, x, y; i <= ecnt; ++i) {
        x = find(E[i].x), y = find(E[i].y);
        if (x ^ y) {
            res += E[i].z;
            if (res >= ans) return;
            if (siz[x] < siz[y]) swap(x, y);
            fa[y] = x, siz[x] += siz[y], cnt--;
            if (cnt == 1) return ans = min(ans, res), void();
        }
    }
}
inline int rd() {
    int x = 0; char ch = getchar();
    for (; ch < 48 || ch > 57; ch = getchar());
    for (; ch > 47 && ch < 58; ch = getchar())
        x = (x << 1) + (x << 3) + (ch ^ 48);
    return x;
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = rd(), m = rd(), k = rd();
    for (int i = 1; i <= m; ++i)
        e[i].x = rd(), e[i].y = rd(), e[i].z = rd();
    int mx = 0;
    for (int i = 1; i <= k; ++i) {
        c[i] = rd(), mx = max(mx, c[i]);
        for (int j = 1; j <= n; ++j) a[i][j] = rd();
    }
    ans = 1e18;
    if (mx)
        for (int i = 0; i < (1 << k); ++i) solve(i);
    else solve((1 << k) - 1);
    cout << ans << '\n';
}