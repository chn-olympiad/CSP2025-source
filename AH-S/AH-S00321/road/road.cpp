#include <iostream>
#include <unordered_map>
#include <utility>
#include <climits>
#include <vector>

#define int long long

class PAIRHASH {
public:
	uint64_t operator()(const std::pair<int, int>& a) const {
		return ((long long) a.first) << 31 ^ a.second;
	}
};

int n, m, k;
std::vector<std::pair<int, int>> edges[10005];
std::unordered_map<std::pair<int, int>, int, PAIRHASH> em;
int cost[100];
int costRoads[100][10005];

bool vis[10005];

int mt() {
	std::unordered_map<std::pair<int, int>, int, PAIRHASH> ne;

	int ans = 0;
	for (int i = 2; i <= n; ++i) {
		int mc = INT_MAX;
		std::pair<int, int> nnee;
		for (auto& edge : edges[i]) {
			if (edge.first < i) {
				if (edge.second < mc) {
					mc = edge.second;
					nnee = {i, edge.first};
				}
			}
		}

		int mc_ = INT_MAX;
		std::pair<int, int> del;
		std::pair<int, int> a1, a2;
		for (auto& ce : ne) {
			if (ce.second == 0 || em[{i, ce.first.first}] == 0 || em[{i, ce.first.second}] == 0) {
				continue;
			}
			int cost = -(ce.second - 1) + em[{i, ce.first.first}] + em[{i,ce.first.second}] - 2;
			if (cost < mc_) {
				mc_ = cost;
				del = ce.first;
				a1 = {i, ce.first.first};
				a2 = {i, ce.first.second};
			}
		}

		if (mc < mc_) {
			ne[nnee] = em[nnee];
			ans += mc;
			// std::cout << "add " << nnee.first << " " << nnee.second << std::endl;
			// std::cout << " -- " << mc << std::endl;
		} else {
			ne[del] = 0;
			ne[a1] = em[a1];
			ne[a2] = em[a2];
			ans += mc_;
			// std::cout << "del " << del.first << " " << del.second << std::endl;
			// std::cout << "add " << a1.first << " " << a1.second << std::endl;
			// std::cout << "add " << a2.first << " " << a2.second << std::endl;
			// std::cout << " -- " << mc_ << std::endl;
		}
	}

	return ans;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		edges[u].push_back({v, w});
		edges[v].push_back({u, w});
		em[{u,v}]=w+1;
		em[{v,u}]=w+1;
	}

	for (int i = 1; i <= k; ++i) {
		std::cin >> cost[i];
		for (int j = 1; j <= n; ++j) {
			std::cin >> costRoads[i][j];
		}
	}

	if (k == 0) {
		std::cout << mt() << std::endl;
		return 0;
	}

	return 0;
}
