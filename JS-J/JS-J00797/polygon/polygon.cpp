#include<bits/stdc++.h>
#define ll long long
const int N = 5e3 + 10;
const int M = 5000;
const ll MOD = 998244353;
using namespace std;

int n, a[N], cnt[M + 1];
ll cc[N][N], fc[N], dp[M + 10][3];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	for(int i = 0; i <= M; i++) cc[i][0] = 1;
	for(int i = 1; i <= M; i++) {
		for(int j = 1; j <= i; j++) {
			cc[i][j] = (cc[i - 1][j] + cc[i - 1][j - 1]) % MOD;
			//cout << cc[i][j] << ' ';
		}
		//cout << endl;
	}

	fc[0] = 1;
	for(int i = 1; i <= M; i++) fc[i] = (fc[i - 1] * 2) % MOD;
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	bool flag = true;
	for(int i = 2; i <= n; i++) if(a[i] != a[i - 1]) flag = false;
	
	if(flag) {
		ll ans = 0;
		for(int i = 3; i <= n; i++) ans = (ans + cc[n][i]) % MOD;
		cout << ans;
		return 0;
	}	

	if(n <= 18) {
		int ans = 0;
		for(int i = 1; i < (1 << n); i++) {
			int cnt = 0, maxn = 0, sum = 0;
			
			for(int j = 1; j <= n; j++) {
				if((i >> (j - 1)) & 1 == 1) {
					//cout << (1 << (j - 1)) << ' ';
					cnt++;
					maxn = max(maxn, a[j]);
					sum += a[j];
				}
			}
			//cout << endl;
			if(cnt <= 2) continue;
			if(sum > maxn * 2) {
				//cout << i << ' ' << cnt << ' ' << sum << ' ' << maxn << endl;
				ans++;
			}
		}

		cout << ans;
		return 0;
	}

	for(int i = 1; i <= n; i++) cnt[a[i]]++;
	vector <int> g;
	for(int i = 1; i <= M; i++) if(cnt[i]) g.push_back(i);

	dp[0][0] = 1;
	ll sum = 0, num = 0, ans = 0;
	for(int i = 0; i < g.size(); i++) {
		ll s = fc[cnt[g[i]]] - 1 - cnt[g[i]], s1 = s - cc[cnt[g[i]]][2];
		if(cnt[g[i]] >= 1) ans = (ans + (sum * cnt[g[i]]) % MOD) % MOD;
		if(cnt[g[i]] >= 2) ans = (ans + (fc[num] - 1) * cc[cnt[g[i]]][2] ) % MOD;
		if(cnt[g[i]] >= 3) ans = (ans + s1 * fc[num]) % MOD;
		//ans = (ans + sum * n % MOD + s1 * fc[num] + (fc[num] - 1) * cc[cnt[g[i]]][2]) % MOD;
		//cout << i << ' ' << ans << endl;
		for(int j = 1; j <= cnt[g[i]]; j++) {
			for(int k = 5000 - g[i] + 1; k <= 5000; k++) {
				dp[5001][3] = (dp[5001][3] + dp[k][2] + dp[k][3]) % MOD;
				dp[5001][2] = (dp[5001][2] + dp[k][1]) % MOD;
				dp[5001][1] = (dp[5001][1] + dp[k][0]) % MOD;
			}

			for(int k = 5000; k >= g[i]; k--) {
				dp[k][3] = (dp[k][3] + dp[k - g[i]][3] + dp[k - g[i]][2]) % MOD;
				dp[k][2] = (dp[k][2] + dp[k - g[i]][1]) % MOD;
				dp[k][1] = (dp[k][1] + dp[k - g[i]][0]) % MOD;
			}
		}

		if(i < g.size() - 1) {
			sum = 0;
			for(int j = g[i + 1] + 1; j <= 5001; j++) {
				sum = (sum + dp[j][2] + dp[j][3]) % MOD;
			}
		}
		num += cnt[g[i]];
	}

	cout << ans;

	return 0;
}
