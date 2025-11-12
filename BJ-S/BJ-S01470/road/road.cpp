#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, k;
int f[10005]; long long ans;
int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}
void merge(int x, int y) {f[find(x)] = find(y);}
struct Edge {int x, y, z;} a[1100005];
bool cmp(Edge x, Edge y) {return x.z < y.z;}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
    if (k == 0) {
        sort(a + 1, a + m + 1, cmp);
        for (int i = 1; i <= n; ++i) f[i] = i;
        for (int i = 1; i <= m; ++i)
            if (find(a[i].x) != find(a[i].y)) merge(a[i].x, a[i].y), ans += a[i].z;
        printf("%lld\n", ans);
    } else { int cnt = m;
        for (int i = 1; i <= k; ++i) {
            int x; scanf("%d", &x);
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &x);
                a[++cnt].x = n+i; a[cnt].y = j; a[cnt].z = x;
            }
        }
        sort(a + 1, a + cnt + 1, cmp);
        for (int i = 1; i <= n+k; ++i) f[i] = i;
        for (int i = 1; i <= cnt; ++i)
            if (find(a[i].x) != find(a[i].y)) merge(a[i].x, a[i].y), ans += a[i].z;
        printf("%lld\n", ans);
    }
    return 0;
}
