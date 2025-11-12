#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define int long long
#define fi first
#define se second
#define mp make_pair
const int N = 1000010;

int n, m, k, x, y, z;

struct edge {
    int nxt, to, val, from;
} e[N];

int head[N], now;

struct BSU {
    struct node {int fa, size;} f[N];
    void init (int n) {
        for (int i = 1; i <= n; i ++) {
            f[i].fa = i;
            f[i].size = 1;
        }
    } int find (int x) {
        if (f[x].fa == x) return x;
        return f[x].fa = find (f[x].fa);
    } bool merge (int x, int y) {
        int xx = find (x), yy = find (y);
        if (xx == yy) return false;
        if (f[xx].size > f[yy].size) swap (xx, yy);
        f[xx].fa = yy;
        f[yy].size += f[xx].size;
        return true;
    } bool check (int x, int y) {
        return find (x) == find (y);
    }
} bsu;

bool cmp (edge a, edge b) {
    return a.val < b.val;
}

void add (int x, int y, int z) {
    e[++ now].val = z;
    e[now].to = y;
    e[now].from = x;
    e[now].nxt = head[x];
    head[x] = now;
}

signed main () {
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);
    scanf ("%lld%lld%lld", &n, &m, &k);
    bsu.init (n);
    for (int i = 1; i <= m; i ++) {
        scanf("%lld%lld%lld", &x, &y, &z);
        add (x, y, z);
    }
    sort (e + 1, e + 1 + m, cmp);
    int ans = 0;
    for (int i = 1; i <= m; i ++) {
        int x = e[i].from, y = e[i].to;
        if (bsu.check (x, y)) {
            continue;
        }
        ans += e[i].val;
        bsu.merge (x, y);
    }
    printf("%lld", ans);
    return 0;
}

/*

进食后入：
十年oi一场空，不开longlong见祖宗！
关于spfa，他死了

*/