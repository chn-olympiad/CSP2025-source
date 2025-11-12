#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5, MOD = 998244353;
int n, a[N];
int ans;
void dfs(int s, int x, int ed) {
	if (x == ed) {
		if (s > a[ed])
			ans++;
		return;
	}
	dfs(s + a[x], x + 1, ed);
	dfs(s, x + 1, ed);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int pfqd = -1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pfqd = max(pfqd, a[i]);
	}
	if (pfqd <= 1 && n > 500) {
		for (int i = 3; i <= n; i++) {
			int k = 1;
			for (int j = i - 2; j >= 1; j--) {
				ans += k*j;
				ans %= MOD;
				k++;
			}
		}
		cout << ans;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 3; i <= n; i++) {
		dfs(0, 1, i);
		ans %= MOD;
	}
	cout << ans;
	return 0;
}