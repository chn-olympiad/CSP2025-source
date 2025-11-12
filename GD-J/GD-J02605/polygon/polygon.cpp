#include<bits/stdc++.h>
#define For(i, x, y) for (int i = x; i <= y; i++)
#define FOr(i, x, y) for (int i = x; i < y; i++)
#define mod 998244353
using namespace std;
long long a[5005], ans, n;
void dfs(int x, int lst, int sum, int cho) {
	if (x > n) {
		if (sum > a[lst] * 2 && cho > 2) ans++;
		ans %= mod;
		return;
	}
	dfs(x + 1, x, sum + a[x], cho + 1);
	dfs(x + 1, lst, sum, cho);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	For(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	if (n <= 23) dfs(1, 0, 0, 0), cout << ans;
	else {
		For(i, 1, n - 2) {
			ans += i * (n - 1 - i);
			ans %= mod;
		}
		cout << ans;
	}
}
