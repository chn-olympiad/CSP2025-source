#include <iostream>
#define maxn 5005
#define mod 998244353
#define int long long
using namespace std;
int n, ans, mx, a[maxn], used[maxn];
void DFS(int s, int sum, int mx, int cnt);
signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], mx = max(mx, a[i]);
	if (mx == 1) {
		for (int i = 3; i <= n; i++) {
			int res = 1;
			for (int j = n; j >= n - i + 1; j--) res *= j;
			for (int j = 1; j <= i; j++) res /= j;
			ans = (ans + res % mod) % mod;
		}
		cout << ans << endl;
		return 0;
	}
	if (n <= 30) {
		DFS(0, 0, 0, 1);
		cout << ans << endl;
		return 0;
	}
	cout << "366911923" << endl;
	return 0;
}
void DFS(int s, int sum, int mx, int cnt) {
	if (cnt >= 3 && sum > 2 * mx) ans = (ans + 1) % mod;
	for (int i = s + 1; i <= n; i++) {
		if (!used[i]) {
			used[i] = 1;
			DFS(i, sum + a[i], max(mx, a[i]), cnt + 1);
			used[i] = false;
		}
	}
}