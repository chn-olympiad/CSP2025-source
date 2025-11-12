//GZ-S00393 蒋晨阳 遵义市第四中学
#include <bits/stdc++.h>
using d32 = int;
using u32 = unsigned;
using d64 = long long;
using u64 = unsigned long long;
#define a2pow32(x)	(31 - __builtin_clz(x))
struct E {
	u32 v, w;
	bool operator<(const E&o) const {
		return w < o.w;
	}
};
int main() {
#ifndef _0x3C17_
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::cin.tie(0)->sync_with_stdio(0);
#endif
	u32 n, m, k;
	std::cin >> n >> m >> k;
	std::vector<std::vector<E> > g(n + k);
	bool mask[10020];
	std::fill(mask, mask + n, 1);
	for (u32 i = 0; i < m; ++i) {
		u32 u, v, w;
		std::cin >> u >> v >> w, --u, --v;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	u32 c[10];
	for (u32 i = 0; i < k; ++i) {
		std::cin >> c[i];
		g[n + i].reserve(n);
		for (u32 j = 0; j < n; ++j) {
			u32 u = n + i, w;
			std::cin >> w;
			g[u].push_back({j, w});
			g[j].push_back({u, w});
		}
	}
	if (n * (1ull << k) <= 1000000) {
		u64 ans = 0x7FFFFFFFFFFFFFFFull;
		for (u32 t = 0; t != 1; ++t) {
			u64 cur = 0;
			for (u32 i = 0; i < k; ++i) {
				mask[n + i] = t >> i & 1;
				if (mask[n + i])	cur += c[i];
			}
			std::priority_queue<E> que;
			bool vis[10020];
			que.push({0, 0});
			while (que.size()) {
				u32 u = que.top().v, w = que.top().w;
				que.pop();
				if (vis[u])	continue;
				vis[u] = 1, cur += w;
				for (auto p : g[u]) {
					if (!vis[p.v] && mask[p.v])
						que.push({p.v, p.w});
				}
			}
			if (ans > cur)	ans = cur;
			//for (u32 i = 0; i < n; ++i)	std::cerr << vis[i] << '\t';
			//std::cerr << cur << '\n';
		}
		std::cout << ans << '\n';
		return 0;
	}
	return 0;
}
