#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
const int mod = 998244353;
int a[N], c[N][N];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, maxx = -1e9;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(a[i], maxx);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= i; j++) {
			if(j == 0 || i == j) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j])%mod;
		}
	}
	if(maxx == 1) {
		int ans = 0;
		for(int i = 3; i <= n; i++) {
			ans = (ans + c[n][i])%mod;
		}
		cout << ans;
	} else {
		if(n <= 3) {
			int res = 0;
			for(int i = 1; i <= n; i++) {
				res += a[i];
			}
			if(res - maxx * 2 > 0) cout << 1;
			else cout << 0;
		}
	}
	return 0;
}