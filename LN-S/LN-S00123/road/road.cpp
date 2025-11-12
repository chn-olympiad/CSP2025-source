#include <bits/stdc++.h>
using ll = long long;
#define int ll
constexpr int N = 2e4 + 5;
struct Node
{
    ll u, v, w;
    bool operator < (Node y) { return w < y.w; }
}e[10000005];
ll s[N], c[N];
int find(int x){
    if (x != s[x])
        s[x] = find(s[x]);
    return s[x];
}
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k; std::cin >> n >> m >> k;
    std::iota(s + 1, s + n + k + 1, 1);
    for (int i = 1; i <= m; i++){
        std::cin >> e[i].u >> e[i].v >> e[i].w;
    }
    for (int i = 1; i <= k; i++){
        std::cin >> c[i];
        for (int j = 1, w; j <= n; j++){
            std::cin >> w;
            e[++m] = {i + n, j, w + c[i]};
        }
    }
    std::set < int > set;
    std::sort(e + 1, e + m + 1);
    int cnt = 0;
    int res = 0;
    for (int i = 1; i <= m; i++){
        if (cnt == n + set.size() - 1)
            break;
        int x = e[i].u;
        int y = e[i].v;
        int w = e[i].w;
        int u = find(x);
        int v = find(y);
        if (u != v){
            if (x > n){
                set.insert(x - n);
                w -= c[x - n];
            }
            s[u] = v;
            res += w;
            cnt++;
        }
    }
    for (int i : set)
        res += c[i];
    std::cout << res << std::endl;
}