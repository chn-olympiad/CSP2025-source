#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int read() {
	char c = getchar(); int x = 0, f = 1;
	while (!isdigit(c)) {
		if (c == '-')
			f = -1; c = getchar();
	} while (isdigit(c))
		x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int n, m, c[501], s, lst;
long long ans, f[501][501][2];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	string str; cin >> str;
	for (int i = 1; i <= n; i++)
		c[i] = read();
	sort(c + 1, c + n + 1); f[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		int stu = str[i - 1] - '0';
		for (int j = 0; j <= s + stu; j++) {
			int mid = upper_bound(c + 1, c + n + 1, i - 1 - s + j - 1) - c;
			if (stu)
				f[i][j][0] = (f[lst][j][0] + f[lst][j][1]) % MOD; 
			if (stu && j)
				f[i][j][1] = (f[lst][j - 1][0] + f[lst][j - 1][1]) % MOD * (mid - j) % MOD;
		} s += stu; if (stu) lst = i;
	} if (s < m)
		return 0 * printf("0");
	for (int i = m - (n - s); i <= s; i++) {
		int A = 1;
		for (int j = 1; j <= n - i; j++)
			A = A * j % MOD; 
		(ans += (f[lst][i][0] + f[lst][i][1]) % MOD * A % MOD) % MOD;
	} int tot = 1;
	for (int i = 1; i <= n; i++)
		tot = tot * i % MOD;
	printf("%lld", (tot - ans + MOD) % MOD);
	return 0;
} //删掉部分来不及写qwq 
