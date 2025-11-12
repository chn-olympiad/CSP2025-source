#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MN = 1e4 + 3, MM = 1e6 + 3;
int n, m, k, ans;

int fa[MN];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
struct jjj {
    int x, y, val;
    bool operator < (const jjj &fj) { return val < fj.val; }
}e[MM << 1];

void krus() {
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        int x = e[i].x, y = e[i].y, v = e[i].val;
        int tx = find(x), ty = find(y);
        if (tx == ty) continue;

        fa[tx] = ty;
        ans += v;
        cnt++;
        if (cnt == n - 1) return ;
    }
}
int c[13][MN];

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        e[i] = (jjj){x, y, z};
    }
    sort(e + 1, e + m + 1);

    if (k == 0) {
        krus();
        return cout << ans, 0;
    }
    cout << 0;
    return 0;
}

// AFO
