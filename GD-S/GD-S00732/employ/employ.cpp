#include <bits/stdc++.h>
using namespace std;

const int N = 505, mod = 998244353;

int A = 1, B = 1, cnt_1;
int n, m;
string str;
bool s[N];
int c[N];

int A_(int n) {
	int res = 1;
	for (int i = 2; i <= n; i++) {
		res *= i;
		res %= mod;
	}
	return res % mod;
}

int ans;
bool vis[N];

void dfs(int t, int cnt) {
	if (cnt >= m) {
		ans += A_(n - t);
		ans %= mod;
		return ;
	}
	if (t > n) {
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		if (t - cnt>= c[i] || !s[i]) dfs(t + 1, cnt);
		else dfs(t + 1, cnt + 1);
		vis[i] = 0;
	}
	return ;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> str;
	for (int i = 1; i <= n; i++) {
		s[i] = str[i] - '0';
		cnt_1 += s[i];
		if (!s[i]) A = 0;
		if (cnt_1 >= 18) B = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	int n_ = n;
	for (int i = 1; i <= n; i++) {
		if (!c[i]) n_--;
	}
	if (cnt_1 < m || n_ < m) {
		cout << 0;
	} else if (A) {
		cout << A_(n) % mod;
	} else if (B) {
		dfs(1, 0);
		cout << ans % mod;
	} else {
		dfs(1, 0);
		cout << ans % mod;
	}
	return 0;
}

/*
3 2
101
1 2 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
