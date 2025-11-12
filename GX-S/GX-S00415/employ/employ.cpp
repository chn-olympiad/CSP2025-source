#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

const int N = 1e6 + 6;

int n, m, ans;
bool vis[N];
std::string s;
int a[N], c[N];

bool check() {
	int cnt = 0, got = 0;
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << a[i] << " \n"[i == n];
	// }
	for (int i = 1; i <= n; i++) {
		// std::cout << cnt << ' ' << got << '\n';
		if (s[i] == '0' || cnt >= c[a[i]]) {
			cnt++;
		} else {
			got++;
		}
	}
	return got >= m;
}

void dfs(int s) {
	if (s == n + 1) {
		if (check()) {
			ans++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			a[s] = i;
			vis[i] = 1;
			dfs(s + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	std::cin.tie(nullptr) -> sync_with_stdio(false);

	std::cin >> n >> m;
	std::cin >> s;
	s = '$' + s;
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
	}

	// for (int i = 1; i <= n; i++) {
	// 	std::cout << c[i] << " \n"[i == n];
	// }

	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}

	dfs(1);

	std::cout << ans << '\n';

	return 0;
}