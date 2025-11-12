#include <cstdio>
#include <iostream>
#include <array>
#include <algorithm>

using ll = long long;

constexpr int MAXN = 510;
constexpr int P = 998244353;

int n, m;
std::array<bool, MAXN> s;
std::array<int, MAXN> c;

void input() {
	scanf("%d%d", &n, &m);
	int x;
	for(int i = 1; i <= n; i++) {
		scanf("%1d", &x);
		s[i] = (x == 1);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
}

namespace SPA {

bool check() {
	for(int i = 1; i <= n; i++) {
		if(s[i] == false) return false;
	}
	return true;
}

void work() {
	ll ans = 1;
	for(int i = 1; i <= n; i++) {
		ans = ans * i % P;
	}
	printf("%lld\n", ans);
}

};

namespace BAOLI {

int ans;
std::array<int, MAXN> a;
std::array<bool, MAXN> vis;

bool check() {
	int cnt = 0, tmp = 0;
	for(int i = 1; i <= n; i++) {
		if(cnt < c[a[i]]) {
			tmp += s[i];
			cnt += !s[i];
		}
		else cnt++;
	}
	return tmp >= m;
}

void Dfs(int now) {
	if(now == n+1) {
		if(check()) {
			ans++;
		}
		return ;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i] == 0) {
			vis[i] = 1;
			a[now] = i;
			Dfs(now + 1);
			vis[i] = 0;
		}
	}
}

void work() {
	ans = 0;
	Dfs(1);
	printf("%d\n", ans);
}

};


namespace AC {

std::array<std::array<ll, MAXN>, MAXN> dp; 

void work() {
	std::sort(c.begin()+1, c.begin()+n+1);
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= i; j++) {
			if(s[i]) {
				int pos = std::lower_bound(c.begin()+1, c.begin()+n+1, j) - c.begin();
				(dp[i][j] += dp[i-1][j] * (n - pos + 1) % P) %= P;
				(dp[i][j] += dp[i-1][j-1] * (pos - 1) % P) %= P;
			}
			else {
				if(j > 0) {
					dp[i][j] += dp[i-1][j-1] * (n-i+j) % P;
					dp[i][j] %= P;
				}
			}
		}
	}
	ll ans = 0;
	for(int i = m; i <= n; i++) {
		ans += dp[n][i];
	}
	printf("%lld\n", ans);
}

};

void work() {
	if(SPA::check()) {
		SPA::work();
	}
	else if(n <= 10) {
		BAOLI::work();
	}
	else {
		AC::work();
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out","w",stdout);
	input();
	work();
	return 0;
}
