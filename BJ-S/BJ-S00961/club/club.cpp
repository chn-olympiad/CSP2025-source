#include <bits/extc++.h>

int main() {
#define int long long
	std::ifstream fin("club.in");
	std::ofstream fout("club.out");
	int t;
	fin >> t;
	while (t--) {
		int n;
		fin >> n;
		struct node {
			int a[3];
			
			int max{0};
			int max2{0};
			int id1, id2, id3;
			
			void update() {
				max = std::max({a[0], a[1], a[2]});
				if (max == a[0]) {
					id1 = 0;
					max2 = std::max(a[1], a[2]);
					if (max2 == a[1]) {
						id2 = 1;
						id3 = 2;
					} else {
						id2 = 2;
						id3 = 1;
					}
				} else if (max == a[1]) {
					id1 = 1;
					max2 = std::max(a[0], a[2]);
					if (max2 == a[0]) {
						id2 = 0;
						id3 = 2;
					} else {
						id2 = 2;
						id3 = 0;
					}
				} else if (max == a[2]) {
					id1 = 2;
					max2 = std::max(a[0], a[1]);
					if (max2 == a[0]) {
						id2 = 0;
						id3 = 1;
					} else {
						id2 = 1;
						id3 = 0;
					}
				}
			}
		};
		std::vector<node> a(n + 1);
		for (int i = 1; i <= n; ++i) {
			fin >> a.at(i).a[0] >> a.at(i).a[1] >> a.at(i).a[2];
			a.at(i).update();
		}
		std::sort(a.begin() + 1, a.end(), [](auto x, auto y) {
			if (x.max - x.max2 == y.max - y.max2) {
				return x.a[x.id2] - x.a[x.id3] > y.a[y.id2] - y.a[y.id3];
			}
			return x.max - x.max2 > y.max - y.max2;
		});
		int cnt[3] = {0, 0, 0};
		int cntmax = n / 2;
		int ans = 0;
		std::vector<int> lazy;
		for (int i = 1; i <= n; ++i) {
			int cur = -1;
			if (a.at(i).max == a.at(i).max2) {
				if (cnt[a.at(i).id1] < cnt[a.at(i).id2]) {
					cur = a.at(i).id1;
				} else if (cnt[a.at(i).id1] > cnt[a.at(i).id2]) {
					cur = a.at(i).id2;
				} else {
					lazy.push_back(i);
				}
			} else {
				if (cnt[a.at(i).id1] < cntmax) {
					cur = a.at(i).id1;
				} else if (cnt[a.at(i).id2] < cntmax) {
					cur = a.at(i).id2;
				} else {
					cur = a.at(i).id3;
				}
			}
			if (cur == -1) {
				continue;
			}
			++cnt[cur];
			ans += a.at(i).a[cur];
		}
		for (auto &&i: lazy) {
			int cur = -1;
			if (a.at(i).max == a.at(i).max2) {
				if (cnt[a.at(i).id1] < cnt[a.at(i).id2]) {
					cur = a.at(i).id1;
				} else  {
					cur = a.at(i).id2;
				}
			} else {
				if (cnt[a.at(i).id1] < cntmax) {
					cur = a.at(i).id1;
				} else if (cnt[a.at(i).id2] < cntmax) {
					cur = a.at(i).id2;
				} else {
					cur = a.at(i).id3;
				}
			}
			++cnt[cur];
			ans += a.at(i).a[cur];
		}
		fout << ans << "\n";
	}
	return 0;
}
