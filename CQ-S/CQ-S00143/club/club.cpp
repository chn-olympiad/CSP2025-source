#include <cstdio>
#include <vector>
#include <algorithm>
#include <initializer_list>
using i32 = int;
using i64 = long long;
constexpr i32 N = 1E5;
i32 n, a[N + 1][3];
i32 mx[N + 1];
signed main() noexcept {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	i32 Test;
	for (scanf("%d", &Test); Test; --Test) {
		scanf("%d", &n);
		for (i32 i = 1; i <= n; ++i) {
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
			mx[i] = 0;
			if (a[i][1] > a[i][mx[i]]) mx[i] = 1;
			if (a[i][2] > a[i][mx[i]]) mx[i] = 2;
		}
		i32 lim = n / 2;
		i32 cnt[3] = {};
		for (i32 i = 1; i <= n; ++i) ++cnt[mx[i]];
		for (i32 o : {0, 1, 2})
			if (cnt[o] > lim) {
				std::vector<i32> saber;
				for (i32 i = 1; i <= n; ++i)
					if (mx[i] == o) saber.emplace_back(i);
				std::sort(saber.begin(), saber.end(), [&](i32 x, i32 y) noexcept {
					i32 vx = 0, vy = 0;
					for (i32 t : {0, 1, 2})
						if (t != o) vx = std::max(vx, a[x][t]);
					for (i32 t : {0, 1, 2})
						if (t != o) vy = std::max(vy, a[y][t]);
					return vx - a[x][mx[x]] < vy - a[y][mx[y]];
				});
				for (i32 i = lim; i < i32(saber.size()); ++i) {
					i32 cg = o == 0 ? 1 : 0;
					for (i32 t : {0, 1, 2})
						if (t != o && a[saber[i]][t] > a[saber[i]][cg]) cg = std::max(cg, t);
					mx[saber[i]] = cg;
				}
				break;
			}
		i64 ans = 0;
		for (i32 i = 1; i <= n; ++i) ans += a[i][mx[i]];
		printf("%lld\n", ans);
	}
	return 0;
}
/*
luogu: GameFreak
zhi chi dong ri hui ban cai zhou da di xie xie miao.
*/