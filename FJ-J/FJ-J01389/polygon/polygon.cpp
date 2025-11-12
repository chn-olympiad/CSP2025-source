#include <bits/stdc++.h>
#define N 5001
#define mod 998244353
using namespace std;

int n;
int a[N];
/*long long dp[1 << 21];
bool vis[1 << 21];*/

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a + 1, a + n + 1);

	/*for (int i = 0; i < (1 << n); i++) {
		vector<int> bit;
		for (int x = i; x; x /= 2) {
			bit.push_back(x % 2);
		}
		int Max = 0, tot;
		for (int j = 0; j < bit.size(); j++) {
			if (bit[j] == 1) {
				Max = max(Max, a[j + 1]);
				tot++;
			}
		}
		
		if (tot >= 3) {
			for (int j = 0; j < i; j++) {
				dp[i] = max(dp[i], dp[i - j] + a[bit.size()]);
			}
			
			if (dp[i] > 2 * Max) {
				vis[i] = true;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		if (vis[i]) {
			ans++;
		}
	}

	printf("%lld\n", ans);*/
	
	if (n <= 20) {
		long long ans = 0;
		vector<bool> vis(n + 1);
		map<vector<bool>, int> mp;
		auto dfs = [&](auto &&self, int pos, int s, int Max) {
			if (pos >= 3 && s > 2 * Max) {
				if (mp.find(vis) == mp.end()) {
					ans++;
					ans %= mod;
					mp[vis]++;
				}
			}

			if (pos == n + 1) {
				return;
			}

			for (int i = pos; i <= n; i++) {
				if (!vis[i]) {
					vis[i] = true;
					self(self, pos + 1, s + a[i], max(Max, a[i]));
					vis[i] = false;
				}
			}
		};
		
		dfs(dfs, 1, 0, 0);
		
		printf("%lld\n", ans);
	}
	
	return 0;
}

/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1

test2:872
*/