#include <bits/stdc++.h>
#define lep(i, a, b) for (int i = (a), ed##i = (b); i <= ed##i; ++i)
#define rep(i, a, b) for (int i = (a), ed##i = (b); i >= ed##i; --i)
#define pb push_back
#define fi first
#define se second

const int LN = 2e5 + 7;
typedef long long ll;

bool FISPOS;

int n, a[LN][3];
std::priority_queue <int> q[3];

bool ENDPOS;

int main() {
#ifndef DEBUG
	freopen("club.in", "r", stdin);
	freopen("club.out","w",stdout);
#endif
	std::ios::sync_with_stdio(false),
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int c1 = clock(), Test;
	
	std::cin >> Test;
	while (Test--) {
		std::cin >> n; int ans = 0;
		lep(i, 1, n) {
			std::cin >> a[i][0] >> a[i][1] >> a[i][2];
			if (a[i][0] >= a[i][1] and a[i][0] >= a[i][2]) {
				ans += a[i][0], q[0].push(std::max(a[i][1], a[i][2]) - a[i][0]);
			} else if (a[i][1] >= a[i][0] and a[i][1] >= a[i][2]) {
				ans += a[i][1], q[1].push(std::max(a[i][0], a[i][2]) - a[i][1]);
			} else {
				ans += a[i][2], q[2].push(std::max(a[i][0], a[i][1]) - a[i][2]);
			}
		}
		n >>= 1;
		while (q[0].size() > n) ans += q[0].top(), q[0].pop();
		while (q[1].size() > n) ans += q[1].top(), q[1].pop();
		while (q[2].size() > n) ans += q[2].top(), q[2].pop();
		std::cout << ans << '\n';
		while (!q[0].empty()) q[0].pop();
		while (!q[1].empty()) q[1].pop();
		while (!q[2].empty()) q[2].pop();
	}
	
	std::cerr << clock() - c1 << " ms " << std::fabs(&FISPOS - &ENDPOS) / 1024 / 1024 << " MB\n";
	return 0;
}

