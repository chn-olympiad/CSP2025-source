#include<bits/stdc++.h>
#define mem(a, v) memset(a, v, sizeof(a))

using namespace std;

inline int read(){
    int x = 0;
    char ch = getchar();
    for (;ch < '0' || ch > '9'; ch = getchar());
    for (;ch >= '0' && ch <= '9'; x = x * 10 + (ch ^ 48), ch = getchar());
    return x;
}

const int maxn = 1e4 + 10, maxm = 1e6 + 10, maxk = 10 + 10;

struct E{
    int u, v, w;
    constexpr E(int u = 0, int v = 0, int w = 0): u(u), v(v), w(w){}
} a[maxm], e[maxk][maxn];

struct Val{
    int r, c;
    constexpr Val(int r = 0, int c = 0): r(r), c(c){}
    inline bool operator < (const Val & other) const {
        return e[r][c].w > e[other.r][other.c].w;
    }
};

int n, m, k, tot = 0;
long long res = 1e18;
int c[maxk];
priority_queue<Val> q;

namespace DSU{
    int fa[maxn + maxk];
    inline int getf(int x){
        return fa[x] == x ? x : fa[x] = getf(fa[x]);
    }
    inline bool merge(int x, int y){
        return (x = getf(x)) != (y = getf(y)) && (fa[y] = x);
    }
}

using namespace DSU;

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read(), iota(fa + 1, fa + n + 1, 1);
    for (int i = 1; i <= m; i++){
        a[i].u = read(), a[i].v = read(), a[i].w = read();
    }
    const auto cmp = [](E x, E y){return x.w < y.w;};
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1, cnt = n; i <= m; i++){
        merge(a[i].u, a[i].v) && (e[0][++tot] = a[i], 1538);
    }
    for (int i = 1; i <= k; i++){
        c[i] = read();
        for (int j = 1; j <= n; j++){
            const int val = read();
            e[i][j] = E(n + i, j, val);
        }
        sort(e[i] + 1, e[i] + n + 1, cmp);
    }
    for (int sta = 0; sta < 1 << k; sta++){
        iota(fa + 1, fa + n + k + 1, 1), q.push(Val(0, 1));
        long long now = 0;
        for (int i = 1; i <= k; i++){
            if (sta >> i - 1 & 1){
                now += c[i], q.push(Val(i, 1));
            }
        }
        while (!q.empty()){
            const int r = q.top().r, c = q.top().c;
            q.pop(), merge(e[r][c].u, e[r][c].v) && (now += e[r][c].w), e[r][c + 1].u && (q.push(Val(r, c + 1)), 1538);
        }
        res = min(res, now);
    }
    printf("%lld", res);

return 0;
}