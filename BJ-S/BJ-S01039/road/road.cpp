#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
namespace pnl{
    #define reg register
    typedef long long LL;
    constexpr LL N = 10100, M = 1000100;
    LL n, m, k, res = 0;
    int fat[N], siz[N];
    LL a[11][N], c[11];
    pair<LL, int> b[11][N];
    struct edg{
        int x, y;
        LL z;
        edg(const int __x = 0, const int __y = 0, const LL __z = 0) {
            x = __x;
            y = __y;
            z = __z;
        }

        friend bool operator <(const edg __x, const edg __y) {
            return __x.z < __y.z;
        }
    };

    edg lop[M], pol[11][N];
    inline void frd(int &__x) {
        __x = 0;
        char c = getchar();
        while (c < '0' || c > '9') c = getchar();
        while (c >= '0' && c <= '9') {
            __x = (__x << 1) + (__x << 3) + c - '0';
            c = getchar();
        }

        return;
    }

    inline void frd(LL &__x) {
        __x = 0;
        char c = getchar();
        while (c < '0' || c > '9') c = getchar();
        while (c >= '0' && c <= '9') {
            __x = (__x << 1) + (__x << 3) + c - '0';
            c = getchar();
        }

        return;
    }

    inline void dsu() {
        for (reg int i = 1; i <= n + k; ++i) {
            fat[i] = i;
            siz[i] = 1;
        }

        return;
    }

    inline void mrg(const int __x, const int __y) {
        if (siz[__x] > siz[__y]) {
            fat[__y] = __x;
            siz[__x] += siz[__y];
        } else {
            fat[__x] = __y;
            siz[__y] += siz[__x];
        }

        return;
    }

    int fnd(const int __x) {
        if (fat[__x] == __x) return __x;
        return fat[__x] = fnd(fat[__x]);
    }

    void dfs(const int __x, LL __y, const int __z) {
        if (__x == k + 1) return;
        dfs(__x + 1, __y, __z);
        __y += c[__x];
        dsu();
        LL tmp = __y;
        pol[__x][0].z = 0;
        for (reg int i = 1, j = 1; i <= pol[__z][0].z || j <= n; ) {
            edg cur;
            if (i <= pol[__z][0].z && j <= n) {
                if (pol[__z][i].z <= b[__x][j].first) {
                    cur = pol[__z][i];
                    ++i;
                } else {
                    cur = edg(n + __x, b[__x][j].second, b[__x][j].first);
                    ++j;
                }
            } else if (i <= pol[__z][0].z) {
                cur = pol[__z][i];
                ++i;
            } else {
                cur = edg(n + __x, b[__x][j].second, b[__x][j].first);
                ++j;
            }

            int x = fnd(cur.x);
            int y = fnd(cur.y);
            if (x == y) continue;
            mrg(x, y);
            pol[__x][++pol[__x][0].z] = cur;
            tmp += cur.z;            
        }

        res = min(res, tmp);
        dfs(__x + 1, __y, __x);
        __y -= c[__x];
        return;
    }

    int main() {
        freopen("road.in", "r", stdin);
        freopen("road.out", "w", stdout);
        frd(n);
        frd(m);
        frd(k);
        dsu();
        for (reg int i = 1; i <= m; ++i) {
            frd(lop[i].x);
            frd(lop[i].y);
            frd(lop[i].z);
        }

        for (reg int i = 1; i <= k; ++i) {
            frd(c[i]);
            for (reg int j = 1; j <= n; ++j) {
                frd(a[i][j]);
                b[i][j] = pair<LL, int>(a[i][j], j);
            }

            sort(b[i] + 1, b[i] + n + 1);
        }

        sort(lop + 1, lop + m + 1);
        for (reg int i = 1; i <= m; ++i) {
            int x = fnd(lop[i].x);
            int y = fnd(lop[i].y);
            if (x == y) continue;
            mrg(x, y);
            pol[0][++pol[0][0].z] = lop[i];
            res += lop[i].z;
        }

        dfs(1, 0, 0);
        printf("%lld\n", res);
        return 0;
    }
}

int main() {
    // Cogito ergo sum
    pnl::main();
    return 0;
}