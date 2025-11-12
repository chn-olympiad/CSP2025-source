#include<bits/stdc++.h>
using namespace std;

const int maxn = 5010, mod = 998244353;
int n, cnt;
int a[maxn];
bool f = true;

void cjdfs(int now, int yx) {
	if (now > n || (yx < 3 && n - yx + 1 < now)) return;
	if (yx >= 3) cnt = (cnt + 1) % mod;
	cjdfs(now + 1, yx);
	cjdfs(now + 1, yx + 1);
}

void dfs(int now, int yx, int maxx, int len, bool flag) {
	if (now > n || (yx < 3 && n - yx + 1 < now)) return;
	if (yx >= 3 && len > maxx * 2 && flag) {
		cnt = (cnt + 1) % mod;
	}
	now += 1;
	dfs(now, yx, maxx, len, false);
	dfs(now, yx + 1, max(maxx, a[now]), len + a[now], true);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] != 1) f = false;
	}
	if (f && n >= 500) {
		cjdfs(0, 0);
		cout << cnt;
		return 0;
	}
	dfs(0, 0, 0, 0, false);
	cout << cnt;

	return 0;
}