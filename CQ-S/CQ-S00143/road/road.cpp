#include <cstdio>
#include <vector>
#include <tuple>
#include <numeric>
#include <algorithm>
using i32 = int;
using i64 = long long;
constexpr i32 N = 1E4, K = 10;
i32 n, m, k;
i32 c[K], a[K][N + 1];
std::vector<std::tuple<i32, i32, i32>> edges, archer;
i32 pre[N + K + 1];
void init(i32 n) noexcept { std::iota(pre + 1, pre + n + 1, 1); }
i32 get(i32 x) noexcept { return x == pre[x] ? x : pre[x] = get(pre[x]); }
void merge(i32 x, i32 y) noexcept { pre[get(x)] = get(y); }
signed main() noexcept {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (i32 u, v, w; m; --m) scanf("%d%d%d", &u, &v, &w), edges.emplace_back(w, u, v);
	for (i32 i = 0; i < k; ++i) {
		scanf("%d", &c[i]);
		for (i32 j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
	}
	init(n), std::sort(edges.begin(), edges.end());
	i64 ans = 0;
	for (auto [w, u, v] : edges) {
		if (get(u) == get(v)) continue;
		merge(u, v), ans += w, archer.emplace_back(w, u, v);
	}
	for (i32 s = 1, as = 1 << k; s != as; ++s) {
		i64 now = 0;
		auto lancer = archer;
		for (i32 i = 0; i < k; ++i)
			if (s >> i & 1) {
				now += c[i];
				for (i32 j = 1; j <= n; ++j) lancer.emplace_back(a[i][j], n + i + 1, j);
			}
		init(n + k), std::sort(lancer.begin(), lancer.end());
		for (auto [w, u, v] : lancer) {
			if (get(u) == get(v)) continue;
			merge(u, v), now += w;
		}
		ans = std::min(ans, now);
	}
	printf("%lld\n", ans);
	return 0;
}
/*
即使无人呼唤，你也会捧起星辰吧

——环抱着你的希望之星
*/