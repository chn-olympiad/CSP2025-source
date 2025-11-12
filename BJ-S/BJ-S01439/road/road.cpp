#include <bits/stdc++.h>

using i64 = long long;
using PLL = std::pair<i64, i64>;
auto& IG = std::ignore;
const i64 MAXN = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3f;
struct edge_t {
    i64 u, v, w;
    edge_t(): u(0), v(0), w(0) {}
    edge_t(i64 u_, i64 v_, i64 w_): u(u_), v(v_), w(w_) {}
    bool operator < (const edge_t& o) const {
        return w < o.w;
    }
    bool operator > (const edge_t & o) const {
        return w > o.w;
    }
};
struct node_t {
    edge_t e;
    i64 id, idx;
    node_t(): e(), id(0), idx(0) {}
    node_t(edge_t e_, i64 id_, i64 idx_): e(e_), id(id_), idx(idx_) {}
    bool operator > (const node_t& o) const {
        return e > o.e;
    }
};
i64 n, m, k, cr[MAXN], fa[MAXN], siz[MAXN];
std::vector<edge_t> edges, pr[MAXN];

i64 find(i64 x) {
    return (fa[x] == x) ? (x) : (fa[x] = find(fa[x]));
}

void kruskal(void) {
    for (i64 i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    std::sort(edges.begin(), edges.end());
    for (const edge_t e : edges) {
        i64 x = e.u, y = e.v;
        x = find(x), y = find(y);
        if (x != y) {
            fa[x] = y;
            pr[0].emplace_back(e);
        }
    }
}

i64 calc(i64 mask) {
    i64 ct = n;
    std::priority_queue<node_t, std::vector<node_t>, std::greater<node_t>> que;
    que.emplace(pr[0][0], 0, 1);
    for (i64 i = 1; i <= k; ++i) if (mask >> (i - 1) & 1) {
        que.emplace(pr[i][0], i, 1);
        ++ct;
    }
    for (i64 i = 1; i <= n + k; ++i) {
        fa[i] = i;
        siz[i] = 1;
    }
    i64 res = 0, cnt = 0;
    while (que.size()) {
        auto& e = que.top().e;
        i64 x = e.u, y = e.v, w = e.w;
        x = find(x), y = find(y);
        if (x != y) {
            res += w;
            if (siz[x] > siz[y]) std::swap(x, y);
            fa[x] = y;
            siz[y] += siz[x];
            if (++cnt == ct - 1) return res;
        }
        i64 id = que.top().id, idx = que.top().idx;
        que.pop();
        if (idx < (i64) pr[id].size()) {
            que.emplace(pr[id][idx], id, idx + 1);
        }
    }
    // 59216215944
    return res;
}

const i64 BUF_SIZ = (1ll << 20) + 10;
char ibuf[BUF_SIZ], *sip = ibuf, *eip = ibuf, obuf[BUF_SIZ], *eop = obuf, *meop = obuf + BUF_SIZ;
#define get_char() (sip == eip && (eip = (sip = ibuf) + fread(ibuf, 1, BUF_SIZ, stdin), sip == eip) ? EOF : (*sip++))
#define put_char(ch) (eop == meop ? (fwrite(obuf, 1, BUF_SIZ, stdout), eop = obuf, *eop++ = ch) : (*eop++ = ch))

void read(i64& x) {
    x = 0;
    i64 f = 1;
    char ch = get_char();
    while (!isdigit(ch)) {
        if (ch == '-') {
            f = -1;
        }
        ch = get_char();
    }
    while (isdigit(ch)) {
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = get_char();
    }
    x *= f;
}

void print_dfs(i64 x) {
    if (x > 9) print_dfs(x / 10);
    put_char((char) (x % 10 + '0'));
}

void print(i64 x, char end_ch = '\n') {
    if (x < 0) {
        put_char('-');
        x = -x;
    }
    print_dfs(x);
    put_char(end_ch);
}

void solve(void) {
    read(n), read(m), read(k);
    for (i64 i = 1; i <= m; ++i) {
        i64 x = 0, y = 0, z = 0;
        read(x), read(y), read(z);
        edges.emplace_back(x, y, z);
    }
    kruskal();
    for (i64 i = 1; i <= k; ++i) {
        read(cr[i]);
        for (i64 j = 1; j <= n; ++j) {
            i64 x = 0;
            read(x);
            pr[i].emplace_back(i + n, j, x);
        }
        std::sort(pr[i].begin(), pr[i].end());
    }
    i64 ans = INF;
    for (i64 mask = 0; mask < (1ll << k); ++mask) {
        i64 res = 0;
        for (i64 i = 1; i <= k; ++i) if (mask >> (i -  1) & 1) {
            res += cr[i];
        }
        ans = std::min(ans, res + calc(mask));
    }
    print(ans);
}

int main() {
    IG = freopen("road.in", "r", stdin);
    IG = freopen("road.out", "w", stdout);

//    std::ios::sync_with_stdio(0);
//    std::cin.tie(0);
//    std::cout.tie(0);

    solve();

    fwrite(obuf, 1, eop - obuf, stdout);

    return 0;
}
