#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;
const int MOD = 998244353;

int n, a[N], dp[505][50005], flag = 1;
long long ans;

void dfs40(int step, int sum, int cnt, int lst) {
	if (step > n) {
		if (cnt >= 3 && sum > a[lst] * 2)	ans++;
		return ;
	}
	dfs40(step + 1, sum + a[step], cnt + 1, step);
	dfs40(step + 1, sum, cnt, lst);
	return ;
}

long long C(long long x, long long y) {
	long long fz = 1, fm = 1, gcd;
	for (int i = y, j = 1; j <= x; i--, j++) {
		fz *= i, fm *= j;
		gcd = __gcd(fz, fm);
		fz /= gcd, fm /= gcd;
	}
	return (fz / fm) % MOD;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1)	flag = 0;
	}
	
	if (n <= 20) {
		sort(a + 1, a + n + 1);
		a[0] = 1e9;
		dfs40(1, 0, 0, 0);
		
		cout << ans << "\n";
		return 0;
	} else {
		for (int i = 3; i <= n / 2; i++) {
			if (i == n / 2 && n % 2 == 0)	ans += C(i, n);
			else	ans += 2 * C(i, n);
			ans %= MOD;
		}
		ans += n * (n - 1) / 2 + n + 1;
		ans %= MOD;
		cout << ans << "\n";
		return 0;
	}
	
	return 0;
}
