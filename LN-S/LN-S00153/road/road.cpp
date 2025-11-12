#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
const int N = 1e4 + 7;
const int M = 1e6 + 7;
const int N2 = 1e3 + 7;
int a[N2][N2];
int kk[N];
class edge {
    public:
        int v;
        int s;
        int e;
        friend bool operator < (edge x, edge y) {
            return x.v < y.v;
        }
}a1[M];
int fa[N];
int find(int x) {
    if(fa[x] == x) return fa[x];
    else return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    fa[fx] = fy;
}
bool same(int x, int y) {
    return find(x) == find(y);
}
signed main() {
    std::freopen("road.in", "r", stdin);
    std::freopen("road.out", "w", stdout);
    int n, m, k;
    std::cin >> n >> m >> k;
    if(k == 0) {
        for(int i = 1; i <= m; i++) std::cin >> a1[i].s >> a1[i].e >> a1[i].v;
        std::sort(a1 + 1, a1 + 1 + m);
        for(int i = 1; i <= n; i++) fa[i] = i;
        long long ans = 0;
        for(int i = 1; i <= m; i++) {
            if(!same(a1[i].s, a1[i].e)) {
                merge(a1[i].s, a1[i].e);
                ans += a1[i].v;
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}