#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector<array<int, 3>> a(n + 1);
		bool A = 1, B = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 2; j++)
				cin >> a[i][j];
			A &= a[i][1] == 0 && a[i][2] == 0;
			B &= a[i][2] == 0;
		}
		
		if (A) {
			sort(a.begin() + 1, a.end(), [&](const array<int, 3> &s, const array<int, 3> &t) {return s[0] > t[0];});
			int ans = 0;
			for (int i = 1; i <= n / 2; i++)
				ans += a[i][0];
			cout << ans << "\n";
			continue;
		}
				
		vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(n / 2 + 1, vector<int>(n / 2 + 1, -2e9)));

		f[0][0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n / 2; j++)
				for (int k = 0; k <= n / 2; k++)
					if (i - j - k >= 0 && i - j - k <= n / 2)
						f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[i][0]);
	
			for (int k = 1; k <= n / 2; k++)
				for (int j = 0; j <= n / 2; j++)
					if (i - j - k >= 0 && i - j - k <= n / 2)
						f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[i][1]);
			for (int j = 0; j <= n / 2; j++)
				for (int k = 0; k <= n / 2; k++)
					if (i - j - k >= 1 && i - j - k <= n / 2)
						f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i][2]);
//			for (int j = 0; j <= n / 2; j++)
//				for (int k = 0; k <= n / 2; k++) if (i - j - k >= 0 && i - j - k <= n / 2)
//					printf("f[%d][%d][%d] = %d\n", i, j, k, f[i][j][k]);
//			puts("");
		}
		
		int ans = 0; 
		for (int j = 0; j <= n / 2; j++)
			for (int k = 0; k <= n / 2; k++) if (n - j - k >= 0 && n - j - k <= n / 2)
				ans = max(ans, f[n][j][k]);
				
		cout << ans << "\n";
	}
	return 0;
}
/*
input:
1
4
4 2 1
3 2 4
5 3 4
3 5 1
output:
18
*/
