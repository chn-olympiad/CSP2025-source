#include <bits/stdc++.h>
#define N 100001
using namespace std;

int n;
long long a[N], b[N], c[N];
long long ans;

void dfs(int pos, int A, int B, int C, long long sum) {
	if (pos == n + 1) {
		ans = max(ans, sum);
	}
	
	if (A < n / 2) {
		dfs(pos + 1, A + 1, B, C, sum + a[pos]);
	}
	if (B < n / 2) {
		dfs(pos + 1, A, B + 1, C, sum + b[pos]);
	}
	if (C < n / 2) {
		dfs(pos + 1, A, B, C + 1, sum + c[pos]);
	}
}

void solve() {
	scanf("%d", &n);
	
	bool test1 = true, test2 = true;
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
		if (b[i] || c[i]) {
			test1 = false;
		}
		if (c[i]) {
			test2 = false;
		}
	}
	
	ans = 0;
	
	if (test1) {
		sort(a + 1, a + n + 1, greater<long long>());

		for (int i = 1; i <= n / 2; i++) {
			ans += a[i];
		}

		printf("%lld\n", ans);
		return;
	}
	
	if (test2) {
		vector<pair<long long, long long>> V;
		for (int i = 1; i <= n; i++) {
			V.push_back({a[i], b[i]});
		}
		
		int A = 0, B = 0;
		for (auto v : V) {
			if (v.first > v.second) {
				if (A < n / 2) {
					A++;
					ans += v.first;
				} else {
					B++;
					ans += v.second;
				}
			} else {
				if (B < n / 2) {
					B++;
					ans += v.second;
				} else {
					A++;
					ans += v.first;
				}
			}
		}
		long long res1 = ans;
		
		sort(V.begin(), V.end(), greater<pair<long long, long long>>());

		A = 0, B = 0;
		ans = 0;
		for (auto v : V) {
			if (v.first > v.second) {
				if (A < n / 2) {
					A++;
					ans += v.first;
				} else {
					B++;
					ans += v.second;
				}
			} else {
				if (B < n / 2) {
					B++;
					ans += v.second;
				} else {
					A++;
					ans += v.first;
				}
			}
		}
		long long res2 = ans;

		V.clear();
		for (int i = 1; i <= n; i++) {
			V.push_back({b[i], a[i]});
		}
	
		A = 0, B = 0;
		ans = 0;
		for (auto v : V) {
			if (v.second > v.first) {
				if (A < n / 2) {
					A++;
					ans += v.second;
				} else {
					B++;
					ans += v.first;
				}
			} else {
				if (B < n / 2) {
					B++;
					ans += v.first;
				} else {
					A++;
					ans += v.second;
				}
			}
		}
		long long res3 = ans;

		sort(V.begin(), V.end(), greater<pair<long long, long long>>());

		A = 0, B = 0;
		ans = 0;
		for (auto v : V) {
			if (v.second > v.first) {
				if (A < n / 2) {
					A++;
					ans += v.second;
				} else {
					B++;
					ans += v.first;
				}
			} else {
				if (B < n / 2) {
					B++;
					ans += v.first;
				} else {
					A++;
					ans += v.second;
				}
			}
		}

		printf("%lld\n", max({ans, res1, res2, res3}));
		return;
	}

	dfs(1, 0, 0, 0, 0);
	printf("%lld\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int Test = 1;
	scanf("%d", &Test);
	
	for ( ; Test--; ) {
		solve();
	}
	
	return 0;
}