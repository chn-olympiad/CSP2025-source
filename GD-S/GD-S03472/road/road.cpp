#include <stdio.h>
#include <iostream>
#include <algorithm>

struct Edge {
	int type;
	int u;
	int v;
	int w;
};

bool operator < (const Edge a, const Edge b)
{
	return a.w < b.w;

}
constexpr int N = 10010;
constexpr int M = 1000010;
constexpr int S = (1 << 10) + 5;
Edge e[M];
Edge city[110010];
int fa[N*2];
long long sumc[S];

int find(const int i)
{
	if (fa[i] == i)
		return i;
	return fa[i] = find(fa[i]);
}

void chmin(const long long x, long long &y)
{
	if (x < y)
		y = x;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	int m;
	std::cin >> m;
	int k;
	std::cin >> k;
	for (int i = 1; i <= m; ++i) {
		e[i].type = 0;
		std::cin >> e[i].u;
		std::cin >> e[i].v;
		std::cin >> e[i].w;
	}
	for (int i = 1; i <= k; ++i) {
		std::cin >> sumc[1 << (i - 1)];
		for (int j = 1; j <= n; ++j) {
			const int id = (i - 1) * n + j;
			city[id].type = 1;
			city[id].u = n + i;
			city[id].v = j;
			std::cin >> city[id].w;
		}
	}
	std::sort(e + 1, e + m + 1);
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	long long ans = 0;
	for (int i = 1, cnt = 0; cnt < n - 1 && i <= m; ++i) {
		const int x = find(e[i].u);
		const int y = find(e[i].v);
		if (x != y) {
			ans += e[i].w;
			fa[x] = y;
			++cnt;
			city[k * n + cnt] = e[i];
		}
	}
//	for (int i = 1; i <= n - 1; ++i)
//		std::cerr << good[i].u << ' ' << good[i].v << ' ' <<  good[i].w << '\n';
//	std::merge(good + 1, good + (n - 1) + 1, city + 1, city + k * n + 1, all + 1);
	int mm = (n - 1) + k * n;
	std::sort(city + 1, city + mm + 1);
	for (int s = 1; s < (1 << k); ++s) {
		sumc[s] = sumc[s ^ (s&-s)] + sumc[s&-s];
		long long cur = sumc[s];
		for (int i = 1; i <= n*2; ++i)
			fa[i] = i;
		for (int i = 1; i <= mm; ++i) {
			if (city[i].type == 1 && !(s & (1 << (city[i].u - n - 1))))
				continue;
			const int x = find(city[i].u);
			const int y = find(city[i].v);
			if (x != y) {
//				if (s == 1)
//					std::cerr << city[i].type << ' ' << city[i].u << ' ' << city[i].v << ' ' << city[i].w << '\n';
				cur += city[i].w;
				fa[x] = y;
			}
		}
//		std::cerr << s << ' ' << cur << '\n';
		chmin(cur, ans);
	}
	std::cout << ans;
	return 0;
}

