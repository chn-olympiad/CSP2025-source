#include <bits/stdc++.h>

using namespace std;

int read() {
	int s = 0, f = 1;
	char c = getchar();
	while (! isdigit(c)) {
		if (c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while (isdigit(c)) {
		s = (s << 1) + (s << 3) + c - 48;
		c = getchar(); 
	}
	return s * f;
}
void write(long long x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x < 10) {
		putchar(x + 48);
	} else {
		write(x / 10);
		putchar(x % 10 + 48);
	}
}

int t;
int n;
int a[100007][4];
long long dp[100007];
bool fg1 = true, fg2 = true, fg3 = true;

void dfs(int p, int cnt1, int cnt2, int cnt3, long long sum) {
	if (p > n) {
		return ;
	}
	if (cnt1 < (n >> 1)) {
		dp[p] = max(dp[p], sum + a[p][1]); 
		dfs(p + 1, cnt1 + 1, cnt2, cnt3, sum + a[p][1]);
	}
	if (cnt2 < (n >> 1)) {
		dp[p] = max(dp[p], sum + a[p][2]); 
		dfs(p + 1, cnt1, cnt2 + 1, cnt3, sum + a[p][2]);
	}
	if (cnt3 < (n >> 1)) {
		dp[p] = max(dp[p], sum + a[p][3]); 
		dfs(p + 1, cnt1, cnt2, cnt3 + 1, sum + a[p][3]);
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = read();
	while (t --) {
		n = read();
		memset(dp, 0ll, sizeof dp);
		for (int i = 1; i <= n; ++ i) {
			a[i][1] = read(), a[i][2] = read(), a[i][3] = read();
			if (a[i][1]) {
				fg1 = false;
			}
			if (a[i][2]) {
				fg2 = false;
			}
			if (a[i][3]) {
				fg3 = false;
			}
		}
		if (fg1 && fg2) {
			priority_queue < int > pq;
			for (int i = 1; i <= n; ++ i) {
				pq.emplace(a[i][3]);
			}
			int t = n >> 1;
			long long ans = 0;
			while (t --) {
				ans += pq.top();
				pq.pop();
			}
			printf("%lld\n", ans);
			continue ;
		}
		if (fg2 && fg3) {
			priority_queue < int > pq;
			for (int i = 1; i <= n; ++ i) {
				pq.emplace(a[i][1]);
			}
			int t = n >> 1;
			long long ans = 0;
			while (t --) {
				ans += pq.top();
				pq.pop();
			}
			printf("%lld\n", ans);
			continue ;
		}
		if (fg1 && fg3) {
			priority_queue < int > pq;
			for (int i = 1; i <= n; ++ i) {
				pq.emplace(a[i][2]);
			}
			int t = n >> 1;
			long long ans = 0;
			while (t --) {
				ans += pq.top();
				pq.pop();
			}
			printf("%lld\n", ans);
			continue ;
		}
		dfs(1, 0, 0, 0, 0);
		write(dp[n]);
		puts("");
	}
	return 0;
}
