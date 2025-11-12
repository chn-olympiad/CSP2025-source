#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 100010;
int a[N][4];
int best[N];
int cnt[4];

void chmax(const int x, int &y)
{
	if (x > y)
		y = x;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= 3; ++j)
				std::cin >> a[i][j];
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			best[i] = 1;
			for (int j = 2; j <= 3; ++j)
				if (a[i][j] > a[i][best[i]])
					best[i] = j;
			ans += a[i][best[i]];
			++cnt[best[i]];
		}
	//	for (int i = 1; i <= n; ++i)
	//		std::cerr << best[i] << '\n';
		int id = 0;
		for (int j = 1; j <= 3; ++j)
			if (cnt[j] > n/2)
				id = j;
		if (id) {
	//		std::cerr << 'a';
			std::vector<int> val;
			val.reserve(n);
			for (int i = 1; i <= n; ++i) {
				if (best[i] != id)
					continue;
				int x = -INF;
				for (int j = 1; j <= 3; ++j)
					if (j != id)
						chmax(a[i][j] - a[i][id], x);
				val.push_back(x);
			}
			std::sort(val.begin(), val.end(), std::greater<int>());
			for (int i = 0; i < cnt[id] - n/2; ++i)
				ans += val[i];
		}
		std::cout << ans << '\n';
		for (int j = 1; j <= 3; ++j)
			cnt[j] = 0;
	}
	return 0;
}

