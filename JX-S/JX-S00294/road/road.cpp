#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;
using LL = long long;
const int N = 1e3 + 5, M = 1e6 + 5;
inline void read(int &x){
    x = 0;
    int f = 0; char c = getchar();
    for (; !isdigit(c); c = getchar()) f ^= c == '-';
    for (; isdigit(c); c = getchar())
        x = (x << 1) + (x << 3) + (c ^ '0');
    if (f) x = -x;
}
int n, m, k;
struct Edges{
    bool f;
    int a, b, w;
    bool operator < (const Edges &o) const{
        return w < o.w;
    }
} e[M + N * N + 5];
int c[N], p[N * 2];
bool st[N * 2];
inline int Find(int x){
    return p[x] != x ? p[x] = Find(p[x]) : p[x];
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    read(n), read(m), read(k);
    for (register int i = 1; i <= m; i ++ ){
        int u, v, w;
        read(u), read(v), read(w);
        e[i] = {0, u, v, w};
    }
    for (register int i = 1; i <= k; i ++ ){
        read(c[i]);
        for (register int j = 1, aij; j <= n; j ++ )
            read(aij), e[ ++ m] = {1, i + n, j, aij};
    }
    sort(e + 1, e + m + 1);
    LL ans = 2e18;
    for (register int S = 0; S < (1 << k); S ++ ){
        LL res = 0;
        for (register int i = 1; i <= n * 2; i ++ )
            st[i] = false, p[i] = i;
        for (register int i = 0; i < k; i ++ )
            if (S >> i & 1){
                res += c[i + 1];
                st[i + 1 + n] = true;
            }
        if (res > ans) goto ne;
        for (register int i = 1; i <= m; i ++ ){
            if (!e[i].f || (e[i].f && st[e[i].a])){
                int a = Find(e[i].a), b = Find(e[i].b);
                if (a != b){
                    p[a] = b;
                    res += e[i].w;
                    if (res > ans) goto ne;
                }
            }
        }
        ans = min(ans, res);
        ne:;
    }
    printf("%lld\n", ans);
    return 0;
}
