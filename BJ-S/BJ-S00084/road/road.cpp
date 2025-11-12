#include<iostream>
#include<vector>
#include<algorithm>
// #warning here===============================================
// #include "../testlib.h"
#define int long long
using namespace std;
const int N = 1e4 + 10;
const int M = 1e6 + 10;
const int K = 15;

inline void read(int &x) {
    char ch;
    while(!isdigit(ch = getchar_unlocked()));
    x = ch - '0';
    while(isdigit(ch = getchar_unlocked())) x = x * 10 + ch - '0';
}

inline void write(int x) {
    char buf[60] = {}, top = 0;
    do buf[++top] = x % 10, x /= 10; while(x);
    while(top) putchar_unlocked(buf[top--] + '0');
}

struct Edge {
    int u, v, w, col;
    inline bool operator<(const Edge &b) const {
        return w < b.w;
    }
};

int n, m, k, ans, res;
int c[K], a[K][N], ban[K];
vector<Edge> edg, mst;

int fa[N + K];
void clear() { for(int i = 1; i <= n + k; i++) fa[i] = i; }
int find(int x) { if(fa[x] == x) return x; return fa[x] = find(fa[x]); }

signed main() {

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    read(n), read(m), read(k);
    for(int i = 1; i <= m; i++) {
        int u, v, w; read(u), read(v), read(w);
        // int u = gen(1, n), v = gen(1, n), w = gen(0, 1000000000);
        edg.push_back({u, v, w, 0});
    }
    for(int i = 1; i <= k; i++) {
        read(c[i]);
        for(int j = 1; j <= n; j++) read(a[i][j]);
        // c[i] = gen(0, 1000000000);
        // for(int j = 1; j <= n; j++) a[i][j] = gen(0, 1000000000);
    }

    clear(); res = 0;
    sort(edg.begin(), edg.end());
    for(Edge &e : edg) {
        int u = e.u, v = e.v, w = e.w;
        if(find(u) == find(v)) continue;
        mst.push_back(e);
        fa[find(u)] = find(v);
        res += w;
    }
    ans = res;

    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            mst.push_back({n + i, j, a[i][j], i});
        }
    }

    sort(mst.begin(), mst.end());
    for(int s = 1; s < (1 << k); s++) {
        clear(); res = 0;
        for(int i = 1; i <= k; i++) {
            ban[i] = !((s >> i - 1) & 1);
            res += !ban[i] * c[i];
        }
        for(Edge &e : mst) {
            if(ban[e.col]) continue;
            int u = e.u, v = e.v, w = e.w;
            if(find(u) == find(v)) continue;
            fa[find(u)] = find(v);
            res += w;
        }
        ans = min(ans, res);
    }

    write(ans);
    putchar_unlocked('\n');

    return 0;
}