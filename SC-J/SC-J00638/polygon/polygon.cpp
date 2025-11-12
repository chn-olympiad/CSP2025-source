#include<bits/stdc++.h>
using namespace std;

const int N = 5010;
const int Mod = 998244353;

int n, a[N], tmp[N], cnt;
long long ans;

bool check() {
	int maxx = 0, sum = 0;
	for(int i = 1; i <= cnt; i++) {
		maxx = max(maxx, tmp[i]);
		sum = sum + tmp[i];
	}
	return sum > maxx * 2;
}
void dfs(int x) {
	if(x == n + 1) {
		if(check()) ans = (ans + 1) % Mod;
		return ;
	}
	dfs(x + 1);
	tmp[++cnt] = a[x];
	dfs(x + 1);
	--cnt;
}
long long C(int x, int y) {
	if(y == 0) return 1;
	double xx = x, yy = y;
	return (long long)(C(x, y - 1) * 1.0 * ((xx - yy + 1) * 1.0 / yy)) % Mod;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool flag = true;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] != 1) flag = false;
	}
	if(flag) {
		for(int i = 3; i <= n; i++) {
			int y = min(i, n - i);
			ans = ans + C(n, y);
		}
		cout << ans;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}