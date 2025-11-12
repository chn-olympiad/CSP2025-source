#include <bits/extc++.h>

int main() {
#define int long long
	std::ifstream fin("road.in");
	std::ofstream fout("road.out");
//#define fin std::cin
//#define fout std::cout
	static int n, m, k;
	fin >> n >> m >> k;
	struct Edge {
		int to, next, len;
	};
	std::vector<Edge> edge;
	std::vector<int> h(n + k + 1, -1);
	auto addEdge = [&](int x, int y, int len) {
		edge.push_back({y, h.at(x), len});
		//std::cout << "AddEdge " << x << " " << y << " " << len << " " << tag << std::endl;
		h.at(x) = static_cast<int>(edge.size()) - 1;
	};
	std::vector<int> c(k + 1);
	auto prim = [&](int xxx) {
		std::vector<int> fa(n + k + 1);
		for (int i = 1; i <= n + k; ++i) {
			fa.at(i) = i;
		}
		auto find = [&](int x) {
			auto _find = [&](auto &&self, int x) -> int {
				int res = fa.at(x);
				if (res != x) {
					res = self(self, res);
					fa.at(x) = res;
				}
				return res;
			};
			return _find(_find, x);
		};
		auto merge = [&](int x, int y) {
			x = find(x);
			y = find(y);
			if (x != y) {
				fa.at(y) = x;
			}
		};
		//std::cout << "With " << xxx << std::endl;
		int ans = 0;
		std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<>> que;
		que.emplace(0, std::make_pair(1, 0));
		std::vector<int> flag(k + 1);
		std::vector<int> dis(k + 1);
		while (!que.empty()) {
			int d = que.top().first;
			int u = que.top().second.first;
			int lst = que.top().second.second;
			que.pop();
			if (u != 1 && find(u) == find(1)) {
				continue;
			}
			if (u > n) {
				dis.at(u - n) = d;
			}
			if (lst > n) {
				flag.at(lst - n) = 1;
			}
			merge(1, u);
			ans += d;
			//std::cout << "To " << u << " With " << d << std::endl;
			for (int i = h.at(u); i != -1; i = edge.at(i).next) {
				int to = edge.at(i).to;
				int len = edge.at(i).len;
				if (find(1) == find(to) || to == n + xxx) {
					continue;
				}
				if (to > n) {
					que.emplace(len + c.at(to - n), std::make_pair(to, u));
				} else {
					que.emplace(len, std::make_pair(to, u));
				}
			}
		}
		//std::cout << ans << " ";
		for (int i = 1; i <= k; ++i) {
			if (i == xxx) {
				continue;
			}
			if (flag.at(i) == 0) {
				ans -= dis.at(i);
				//std::cout << " - " << dis.at(i);
			}
		}
		//std::cout << " = " << ans << std::endl;
		return ans;
	};
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		fin >> u >> v >> w;
		addEdge(u, v, w);
		addEdge(v, u, w);
	}
	//std::cout << "ans1: " << std::endl;
	for (int u = 1; u <= k; ++u) {
		fin >> c.at(u);
		//std::cout << u << ": " << c.at(u) << std::endl;
		for (int v = 1; v <= n; ++v) {
			int w;
			fin >> w;
			addEdge(n + u, v, w);
			addEdge(v, n + u, w);
		}
	}
	//std::cout << "ans2: " << std::endl;
	int ans = prim(k + 1);
	int sum = 0;
	for (int i = 1; i <= k; ++i) {
		int cur = ans - prim(i);
		sum += std::max(0ll, cur);
		//std::cout << cur << std::endl;
	}
	fout << ans - sum << std::endl;
	return 0;
}
