#include <bits/stdc++.h>
#define int long long
#define Pii pair<int, int>
#define Sc second
#define Fr first
#define ls(x) x << 1
#define rs(x) x << | 1

using namespace std;

const int kMaxN = 2e6 + 5, Mod = 998244353, INF = 1e18;

struct E {
    int x, y, w, id;
    friend bool operator<(const E A, const E B) {
        return A.w < B.w;
    }
} q[kMaxN];

int Fa[kMaxN], sz[kMaxN], f[kMaxN], n, m, k, S, tot, ans;
vector<int> G[kMaxN];
bool b[kMaxN];

int F(int x) {
    return Fa[x] == x ? x : Fa[x] = F(Fa[x]);
}

void M(int x, int y) {
    x = F(x), y = F(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    Fa[x] = y;
}

int K() {
    for (int i = 1; i <= n + S; i++) Fa[i] = i, sz[i] = 1;
    int ret = 0;
    for (int i = 1; i <= tot; i++) {
        int x = q[i].x, y = q[i].y, w = q[i].w;
        if (F(x) != F(y) && (b[q[i].id] || q[i].id == 0)) {
            ret += w;
            M(x, y);
        }
    }
    return ret;
}

void Solve2(int op = 0) {
    ans = INF;
    sort(q + 1, q + tot + 1);
    int Mn = op;
    for (int p = Mn; p < (1 << k); p++) {
        int ret = 0;
        for (int i = 0; i < k; i++) {
            b[i + 1] = (p >> i) & 1;
            if ((p >> i) & 1) ret += f[i + 1];
        }
        int op = K();
        ans = min(ans, ret + op);
    }
    cout << ans << '\n';
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios:: sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k, S = n + k + 1;
    for (int i = 1; i <= m; i++) {
        cin >> q[i].x >> q[i].y >> q[i].w, q[i].id = 0;
    }
    tot = m;
    bool flag1 = 1;
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        f[i] = x;
        bool flag2 = 0;
        for (int j = 1; j <= n; j++) {
            int w; cin >> w;
            flag2 |= (w == 0);
            q[++tot] = {i + n, j, w, i};
        }
        flag1 &= (x == 0) & flag2;
    }
    if (flag1) Solve2((1 << k) - 1);
    else Solve2();
    return 0;
}