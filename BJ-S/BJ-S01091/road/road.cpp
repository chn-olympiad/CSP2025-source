#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long

int n, m, k, fa[10020], c[20];
ll ans = 0;
int fs(int x) {
    return fa[x] == x ? x : fa[x] = fs(fa[x]);
}
bool un(int x, int y) {
    x = fs(x), y = fs(y);
    if (x == y) {
        return 0;
    }
    fa[x] = y;
    return 1;
}
struct Edge {
    int u, v, w, vil;// village
    bool operator< (const Edge& b) const {
        return w < b.w;
    }
} e[1100010];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].vil = 0;
    }
    sort(e + 1, e + m + 1);
    iota(fa, fa + 10015, 0);
    int sc = n;
    for (int i = 1; i <= n; i++) {
        if (un(e[i].u, e[i].v) == 1) {
            ans += e[i].w, sc--;
        }
        if (sc == 1) {
            break;
        }
    }
    if (k == 0) {
        cout << ans << '\n';
        return 0;
    }
    for (int i = 1, x; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> x;
            m++, e[m].u = j, e[m].v = n + i, e[m].w = x, e[m].vil = i;
        }
    }
    sort(e + 1, e + m + 1);
    for (int open = 0; open < (1 << k); open++) {
        for (int i = 1; i <= n + k; i++) {
            fa[i] = i;
        }
        ll cur = 0;
        sc = n;
        for (int i = 1; i <= k; i++) {
            if ((open >> (i - 1)) == 1) {
                cur += c[i], sc++;
            }
        }
        for (int i = 1; i <= m; i++) {
            if (e[i].vil != 0 && (open >> (e[i].vil - 1)) == 0) {
                continue;
            }
            if (un(e[i].u, e[i].v) == 1) {
                cur += e[i].w, sc--;
            }
            if (sc == 1) {
                break;
            }
        }
        ans = min(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}
// 不是这道题大洋力是错了吗？？？？？？？？？？？？？
// 为啥都是这么大的数却只输出几亿