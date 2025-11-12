#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int N = 5e3 + 5, mod = 998244353;

int cnt, n, len[N], C[N][N], s[N];

void dfs(int x, int sum, int maxn) {
	if(x == n + 1) {
		if(sum > maxn * 2) cnt++;
		return;
	}
	dfs(x + 1, sum + len[x], max(maxn, len[x]));
	dfs(x + 1, sum, maxn);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	C[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
		for(int j = 0; j <= i; j++) s[i] = (s[i] + C[i][j]) % mod;
	}
	int maxn = 0;
	for(int i = 1; i <= n; i++) {
		cin >> len[i];
		maxn = max(maxn, len[i]);
	}
	if(maxn == 1) {
		int sum = 0;
		for(int i = 3; i <= n; i++) sum = (sum + C[n][i]) % mod;
		cout << sum << endl;
		return 0;
	}
	if(n <= 20) {
		dfs(1, 0, 0);
		cout << cnt << endl;
		return 0;
	}
	sort(len + 1, len + n + 1);//Î±½â 
	int sum = 0;
	for(int i = 3; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			for(int k = 1; k < j; k++) {
				if(len[j] + len[k] <= len[i]) continue;
				sum = (sum + s[i - 3]) % mod;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
