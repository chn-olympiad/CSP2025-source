#include <bits/stdc++.h>
using namespace std;

const int N = 18;
const int mod = 998244353;

int n, m; string s;
int a[N + 10];
int popc[(1 << N) + 10], dp[(1 << N) + 10][N + 1];

void add(int &u, int v) {
	u = (u + v) % mod;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s; s = " " + s;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	popc[0] = 0;
	for(int i = 1; i < (1 << n); ++i) {
		int ne = (i & -i);
		popc[i] = popc[i ^ ne] + 1;
	}
	dp[0][0] = 1;
	for(int i = 1; i < (1 << n); ++i) {
		for(int j = 0; j < n; ++j) {
			if((!(i >> j) & 1)) continue;
			int ne = i ^ (1 << j);
			for(int k = 0; k < popc[i]; ++k) {
				if(s[popc[i]] == '0') add(dp[i][k], dp[ne][k]);
				else if(popc[i] - k - 1 >= a[j]) add(dp[i][k], dp[ne][k]);
				else add(dp[i][k + 1], dp[ne][k]);
			}
		}
	}
	int ans = 0;
	for(int i = m; i <= n; ++i) add(ans, dp[(1 << n) - 1][i]);
	cout << ans;
	return 0;
}
