//I want to see myself at luogu
// my luogu id:993044
// my luogu name:Like_Amao
//91
//78
//13
//169
//100 + 100 + 25 + 40 = 265 pts
#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
const int mod = 998244353;
int n, ans;
int a[N], b[N];
void dfs(int, int, int, int);
int read();
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n = read();
	for (int i = 1 ; i <= n ; i ++) {
		a[i] = read();
	}
	dfs(1, 0, 0, 0);
	cout << ans % mod;
	return 0;
}
void dfs(int number, int sum, int maxn, int cnt) {
	if (cnt >= 3 and sum > maxn * 2) {
		ans ++;
		ans %= mod;
	}
	if (number > n) {
		return;
	}
	for (int i = number ; i <= n ; i ++) {
		b[cnt] = i;
		dfs(i + 1, sum + a[i], max(maxn, a[i]), cnt + 1);
	}
}
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') {
			f = -1;
		}
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 1) + (x << 3) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
