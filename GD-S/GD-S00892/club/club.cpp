#include <bits/stdc++.h> 
//#define ONLINE_JUDGE
#define FILENAME "club"

typedef long long ll;
const int N = 1e5 + 5;
int n, cnt1, cnt2;
bool vis[N];
struct Node {
	ll ok[5];
	int id;
} a[N], b[N];

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		a[i].id = i;
		for (int j = 0; j < 3; ++j) {
			std::cin >> a[i].ok[j];
		}
	}
	
	auto work = [&]() {
		cnt1 = 1, cnt2 = 1;
		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			vis[i] = 0;
			ans += a[i].ok[0];
		}
		
		int x = n >> 1;
		for (int i = 1; i <= n; ++i) {
			b[i] = a[i];
		}
		
		std::sort(a + 1, a + 1 + n, [](const auto &a, const auto &b) {
			return a.ok[1] - a.ok[0] > b.ok[1] - b.ok[0];
		});
		std::sort(b + 1, b + 1 + n, [](const auto &a, const auto &b) {
			return a.ok[2] - a.ok[0] > b.ok[2] - b.ok[0];
		});
	
		int i = 1, j = 1, now = n;
		while (cnt1 <= x || cnt2 <= x || now > x) {
			while (i <= n && vis[a[i].id]) ++i;
			while (j <= n && vis[b[j].id]) ++j;
			ll left = a[i].ok[1] - a[i].ok[0], right = b[j].ok[2] - b[j].ok[0];
			bool flag = 0;
			ll cc = -1e18;
			if (cnt1 <= x && i <= n) {
				cc = left;
				flag = 1;
			}
			if (cnt2 <= x && j <= n) {
				cc = std::max(cc, right);
				flag = 1;
			}
			if (!flag) break;
			if (now <= x && cc < 0) break;
			ans += cc;
			if (cc == left || (cc == left && cc == right && cnt1 < cnt2)) ++cnt1, vis[a[i].id] = 1;
			else ++cnt2, vis[b[j].id] = 1;
			--now;
		}
		return ans;
	};
	
	ll ans = -1e18;
	ans = std::max(ans, work());
	for (int i = 1; i <= n; ++i) {
		std::swap(a[i].ok[0], a[i].ok[1]);
	}
	ans = std::max(ans, work());
	for (int i = 1; i <= n; ++i) {
		std::swap(a[i].ok[0], a[i].ok[2]);
	}
	ans = std::max(ans, work());
	std::cout << ans << '\n';
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
#endif
	
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);
	
	int _ = 0;
	std::cin >> _;
	while (_--) solve();
	
	_ ^= _;
	return (0^_^0);
}

