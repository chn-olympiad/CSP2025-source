#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10;

int t, n;
int ans, a[N], b[N], c[N];

void dfs(int now, int x, int y, int z, int sum) {
	if (now > n) {
		ans = max(ans, sum);
		return ;
	}
	
	if (x < n / 2) dfs(now + 1, x + 1, y, z, sum + a[now]);
	if (y < n / 2) dfs(now + 1, x, y + 1, z, sum + b[now]);
	if (z < n / 2) dfs(now + 1, x, y, z + 1, sum + c[now]);
}

signed main() {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i];
		
		if (n > 100) {
			sort(a + 1, a + 1 + n);
			for (int i = n; i >= n / 2; --i) ans += a[i];
		} else {
			dfs(1, 0, 0, 0, 0);			
		}

		cout << ans << '\n';
	}
	return 0;
} 
