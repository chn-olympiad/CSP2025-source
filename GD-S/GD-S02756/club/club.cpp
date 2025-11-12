#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

const int N = 1e5 + 7;
#define rep(i,a,b) for(int i(a);i<=(b);++i)

namespace wyx {

int n, a[N][3], vis[N];
inline void main() {
	std::cin >> n;
	rep(i, 1, n) vis[i] = -1;
	std::vector<std::tuple<int, int, int>> vect;
	rep(i, 1, n) {
		std::cin >> a[i][0] >> a[i][1] >> a[i][2];
		vect.emplace_back(a[i][0], i, 0);
		vect.emplace_back(a[i][1], i, 1);
		vect.emplace_back(a[i][2], i, 2);
	}
	std::sort(vect.begin(), vect.end(), std::greater<std::tuple<int, int, int>>());
	static int cnt[3]; for(int i = 0; i < 3; ++i) cnt[i] = 0;
	int ans = 0;
	for(auto& [val, x, y]: vect) {
		if(vis[x] == -1) {
			ans += val;
			vis[x] = y;
			++cnt[y];
		}
	}
	int tar = -1;
	for(int i = 0; i < 3; ++i) if(cnt[i] > n / 2) tar = i;
	if(tar != -1) {
		rep(i, 1, n) {
			std::swap(a[i][tar], a[i][0]);
			vis[i] = vis[i] == tar ? 0 : vis[i] == 0 ? tar : vis[i];
		}
		std::swap(cnt[tar], cnt[0]);
		int more = cnt[0] - n / 2;
		std::vector<int> delta;
		rep(i, 1, n) {
			if(vis[i] == 0) {
				delta.push_back(std::max(a[i][1], a[i][2]) - a[i][0]);
			}
		}
		std::sort(delta.begin(), delta.end());
		while(more) {
			ans += delta.back();
			delta.pop_back();
			--more;
		}
	}
	std::cout << ans << "\n";
}


};

int main() {
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	int t; std::cin >> t;
	for(; t--; ) wyx::main();
}
