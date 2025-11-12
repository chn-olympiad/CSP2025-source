#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define nmax 5007
#define int long long

int n, ans = 0;
int a[nmax];

void dfs(int ind, int mmax, int ssum) {
	if (ind == n + 1 && ssum > (mmax * 2)) {
		ans++;
		ans %= mod;
		return ;
	} else if (ind == n + 1 && ssum <= (mmax * 2)) {
		return ;
	}

	dfs(ind + 1, max(mmax, a[ind]), ssum + a[ind]);
	dfs(ind + 1, mmax, ssum);
	return ;
}

int qpower(int b) {
	int res = 1;

	for (int i = 1; i <= b; i++) {
		res *= 2;
		res %= mod;
	}

	return res;
}

int f(int x) {
	int res = 1;

	for (int i = 1; i <= x; i++) {
		res *= i;
	}

	return res;
}

int A(int n, int m) {
	int res = 1;

	for (int i = m; i >= n; i--) {
		res *= i;
		res %= mod;
	}

	return res;
}

int C(int n, int m) {
	return A(n, n - m + 1) / f(m);
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	if (n <= 20) {
		dfs(1, 0, 0);
		cout << ans;
		return 0;
	} else {
		cout << qpower(n) - C(1, n) - C(2, n);
	}

	return 0;
}

/*
5
1 2 3 4 5
*/
/*
5
2 2 3 8 10
*/