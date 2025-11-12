#include <bits/stdc++.h>
using namespace std;
long long ans;
int a[5010];
int q;
int n;
int m;
void dfs(int x, int sum) {
	if(sum > q) return ;
	if(x == m + 1) return ;
	ans = (ans + 1) % 998244353;
	for (int i = x + 1; i <= m; i++) {
		dfs(i, sum + a[i]);
	}
	return ;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	frepen("polygon.in", "r", stdin);
	freopen("polygon.out","w", stdout);
	cin >> n;
	int flag = 1;
	for (int i = 1; i <= n; i++) {
		if(a[i] != 1) flag = 0;
		cin >> a[i];
	}
	if(flag == 1) {
		long long qq = 1;
		int ww = n * (n - 1) / 2 + n + 1;
		for (int i = 1; i <= n; i++) {
			qq = (qq * 2) % 998244353;
		}
		if(qq >= ww) qq -= ww;
		else qq = 998244353 + (ww - qq);
		cout << qq;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	int ret = a[1] + a[2];
	for (int i = 3; i <= n; i++) {
		q = ret - a[i] - 1;
		if(q < 0) {
			ret += a[i];
			continue;
		}
		if(q == 0) ans = (ans + 1) % 998244353;
		else {
			m = i - 1;
			dfs(0, 0);
		}
		ret += a[i];
	}
	cout << ans;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
