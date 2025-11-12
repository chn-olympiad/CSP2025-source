#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e4 + 10, M = 2e6 + 10;
vector<pii> g[N];
struct Edge {
    int a, b, c;
} e[M];
int ww[N];
bool cmp(Edge const& a, Edge const& b) {
    return a.c < b.c;
}
int p[N];
int fd(int x) {
    if (x == p[x]) return x;
    return p[x] = fd(p[x]);
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        e[i] = {a, b, c};
    }
    if (!k) {
        sort(e + 1, e + m + 1, cmp);
        ll ans = 0;
        for (int i = 1; i <= m; i++) {
            int a = fd(e[i].a), b = fd(e[i].b), c = e[i].c;
            if (a != b) {
                p[a] = b;
                ans += c;
            }
        }
        printf("%lld\n", ans);
        return 0;
    }
    int tot = m;
    for (int i = 1; i <= k; i++) {
        int c, x;
        scanf("%d", &c);
        int nd = -1;
        for (int j = 1; j <= n; j++) {
            scanf("%d", &x);
            if (!x and nd == -1) {
                nd = j;
                continue;
            }
            ww[j] = x;
        }
        for (int j = 1; j <= n; j++) {
            if (j == nd) continue;
            e[++tot] = {nd, j, ww[j]};
        }
    }
    sort(e + 1, e + tot + 1, cmp);
    ll ans = 0;
    for (int i = 1; i <= tot; i++) {
        int a = fd(e[i].a), b = fd(e[i].b), c = e[i].c;
        if (a != b) {
            p[a] = b;
            ans += c;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
