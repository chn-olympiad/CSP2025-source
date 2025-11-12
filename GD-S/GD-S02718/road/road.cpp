#include <cstdio>
#include <cstdlib>

#include <vector>
#include <tuple>
#include <algorithm>
#include <cinttypes>

constexpr int MAXN = 1e5 + 10, MAXK = 20;

int fa[MAXN + MAXK], C[MAXK];

int64_t cost[MAXK], vis[MAXK];

int find(int x) { return fa[x] = (!fa[x] || fa[x] == x)? x: find(fa[x]); }
void unite(int a, int b) { fa[find(a)] = find(b); }

int main (){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    std::vector<std::tuple<int, int, int>> V;
    V.reserve(M + K*N + 10);
    for(int i = 1, u, v, w; i <= M; ++i)
        scanf("%d %d %d", &u, &v, &w),
        V.emplace_back(w, u, v);
    
    for(int i = 1; i <= K; ++i) {
        scanf("%d", C + i);
        for(int j = 1, w; j <= N; ++j) {
            scanf("%d", &w);
            if(w == 0) unite(N + i, j); // Free ways
            else V.emplace_back(w, N + i, j); // just like other roads
        }
    }

    std::sort(V.begin(), V.end());

    int64_t ans = 0;
    for(auto const &Vi: V) {
        int w, u, v;
        std::tie(w, u, v) = Vi;

        if(find(u) != find(v)) {
            unite(u, v);
            ans += w;
        }
    }

    printf("%" PRIi64, ans);
}