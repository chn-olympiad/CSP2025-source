#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005;
int a[N];
int n;
int b[N];
int cnt;
void dfs(int maxn, int res, int sum) {
	if (res == n + 1) {
		if (sum > maxn * 2) {
			cnt++;
			cnt %= 998244353;
		}
		return ;
	}
	dfs(max(maxn, a[res]), res + 1, sum + a[res]);
	dfs(maxn, res + 1, sum);
} 
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n < 3) {
		puts("0");
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			cnt++;
		}
	}
	if (cnt == n) {
		int sum = 0;
		if (n >= 3) {
			for (int i = 1; i <= n - 2; i++) {
				sum += i;
			}
		}
		cout << sum << endl;
		return 0;
	}
	dfs(LONG_LONG_MIN, 1, 0);
	cout << cnt << endl;
	return 0;
}