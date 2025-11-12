// Author: lzm0107

// 16:00 expect 100

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;

using ll = long long;
using aii = array<int, 2>;
using ull = unsigned long long;

char getcr() {
    static const int C = 1048576;
    static char in[C], *p1, *p2;
    return p1 == p2 && (p2 = (p1 = in) + fread(in, 1, C, stdin), p1 == p2) ? EOF : *p1++;
}

void read(int &num) {
    num = 0;
    char c = getcr();
    while (c < '0' || c > '9') c = getcr();
    while (c >= '0' && c <= '9') num = num * 10 + (c ^ 48), c = getcr();
}

struct chash {
    size_t operator() (uint64_t x) const {
        x ^= x >> 32;
        x ^= x >> 16;
        return x;
    }
};

const ll INF64 = 0x3f3f3f3f3f3f3f3f;

const int N = 1e4, M = 1e6, K = 1e1, W_TYPE = 1.1e5;

int n, m, k;
array<int, 3> es[M + 10];
int c[K + 2], a[K + 2][N + 10];

vector<array<int, 3>> mst;
array<int, 3> edge0[W_TYPE + 10];

int fa[N + K + 10], siz[N + K + 10];

int get_root(int u) {
    return fa[u] == u ? u : fa[u] = get_root(fa[u]);
}

void unite(int u, int v) {
    u = get_root(u), v = get_root(v);
    if (u != v) {
        if (siz[u] < siz[v]) {
            swap(u, v);
        }
        siz[u] += siz[v], fa[v] = u;
    }
}

int main() {
    ios::sync_with_stdio(false);

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    read(n), read(m), read(k);
    for (int i = 1; i <= m; ++i) {
        read(es[i][0]), read(es[i][1]), read(es[i][2]);
    }
    vector<int> weight;
    for (int i = 1; i <= k; ++i) {
        read(c[i]);
        for (int j = 1; j <= n; ++j) {
            read(a[i][j]);
            weight.push_back(a[i][j]);
        }
    }
    sort(es + 1, es + m + 1, [](auto lhs, auto rhs) -> bool {
        return lhs[2] < rhs[2];
    });
    iota(fa + 1, fa + n + 1, 1);
    fill(siz + 1, siz + n + 1, 1);
    for (int i = 1; i <= m; ++i) {
        auto [u, v, w] = es[i];
        u = get_root(u), v = get_root(v);
        if (u != v) {
            weight.push_back(w);
            mst.push_back(es[i]);
            unite(u, v);
        }
    }
    sort(weight.begin(), weight.end());
    weight.erase(unique(weight.begin(), weight.end()), weight.end());
    __gnu_pbds::gp_hash_table<int, int, chash> gp;
    int ws = weight.size();
    for (int i = 0; i < ws; ++i) {
        gp[weight[i]] = i + 1;
    }
    int top = 0;
    for (auto &i : mst) {
        i[2] = gp[i[2]];
        edge0[++top] = i;
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] = gp[a[i][j]];
        }
    }
    ll ans = INF64;
    for (int state = 0; state < 1 << k; ++state) {
        iota(fa + 1, fa + n + k + 1, 1);
        fill(siz + 1, siz + n + k + 1, 1);
        int top = n - 1;
        ll cost = 0;
        for (int i = 0; i < k; ++i) {
            if (state >> i & 1) {
                cost += c[i + 1];
                for (int j = 1; j <= n; ++j) {
                    edge0[++top] = array<int, 3>{n + i + 1, j, a[i + 1][j]};
                }
            }
        }
        static int cnt[W_TYPE + 10];
        static array<int, 3> edge1[W_TYPE + 10];
        memset(cnt + 1, 0, weight.size() * sizeof(int));
        for (int i = 1; i <= top; ++i) {
            ++cnt[edge0[i][2]];
        }
        for (int i = 1; i < ws; ++i) {
            cnt[i + 1] += cnt[i];
        }
        for (int i = 1; i <= top; ++i) {
            edge1[cnt[edge0[i][2]]--] = edge0[i];
        }
        for (int i = 1; i <= top && cost < ans; ++i) {
            auto [u, v, w] = edge1[i];
            u = get_root(u), v = get_root(v);
            if (u != v) {
                unite(u, v);
                cost += weight[w - 1];
            }
        }
        ans = min(ans, cost);
    }
    cout << ans << '\n';
    return 0;
}