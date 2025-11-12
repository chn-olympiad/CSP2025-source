#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

const int N = 1e5 + 6;

struct happy {
	i64 a, ty;
};

i64 n;
happy a[N][6];
i64 b[N][6];
i64 d[N][6];
i64 cnt[N];
std::vector<i64> g[6];

void init() {
	memset(a, 0, sizeof a);
	memset(d, 0, sizeof d);
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i <= 5; i++) {
		g[i].clear();
	}
}

void solve() {
	init();

	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			std::cin >> a[i][j].a;
			a[i][j].ty = j;
			b[i][j] = a[i][j].a;
		}
		std::sort(a[i] + 1, a[i] + 4, [&](happy x, happy y) {
			return x.a > y.a;
		});
	}

	// for (int i = 1; i <= n; i++) {
	// 	std::cout << '(' << a[i][1].ty << ',' << a[i][2].ty << ',' << a[i][3].ty << ')' << '\n';
	// }

	for (int i = 1; i <= n; i++) {// d[i][j] = a[i][j].a - a[i][j + 1].a
		for (int j = 1; j <= 2; j++) {// ye jiu shi xia jiang le duo shao
			d[i][j] = a[i][j].a - a[i][j + 1].a;
		}
	}

	for (int i = 1; i <= n; i++) {
		cnt[a[i][1].ty]++;
		g[a[i][1].ty].push_back(i);// g[i] save the id that peopel choose the best club
	}

	// for (int i = 1; i <= 3; i++) {
	// 	std::cout << '(' << i << ',' << cnt[i] << ')' << '\n';
	// }

	// std::cout << '\n';

	i64 ans = 0;

	for (int i = 1; i <= 3; i++) {
		if (cnt[i] > n / 2) {
			std::sort(g[i].begin(), g[i].end(), [&](int x, int y) {// zui duo tiao zheng yi ci, bing qie zhe li mian de ren yi ding dou shi zui xi huan zhe ge club
				return d[x][1] > d[y][1];
			});

			// for (int j = 0; j < cnt[i]; j++) {
			// 	std::cout << '(' << i << ',' << a[g[i][j]][1].a << '-' << a[g[i][j]][2].a << '=' << d[g[i][j]][1] << ')' << '\n';
			// }

			// for (int j = 0; j < cnt[i]; j++) {
			// 	std::cout << g[i][j] << " \n"[j == cnt[i] - 1];
			// }

			for (int j = (n / 2); j < cnt[i]; j++) {
				int k = g[i][j];// yao wei qu de shi k
				// std::cout << k << " \n"[i == cnt[i] - 1];
				cnt[a[k][2].ty]++;
				g[a[k][2].ty].push_back(k);
			}
			cnt[i] = n / 2;
		}
	}

	for (int i = 1; i <= 3; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			ans += b[g[i][j]][i];
			// std::cout << g[i][j] << " \n"[j == cnt[i] - 1];
		}
	}

	std::cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	std::cin.tie(nullptr) -> sync_with_stdio(false);

	int t;
	for (std::cin >> t; t--; ) {
		solve();
	}

	return 0;
}