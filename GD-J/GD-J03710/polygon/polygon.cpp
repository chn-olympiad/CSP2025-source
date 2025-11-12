#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
const int mod = 998244353;
int a[N];
int n;
long long ans;
int b[N];

long long C(int n, int m) {
	if (n == m) return 1;
	if (n > m / 2) n = m - n;
	long long nowans = 1, check = 1;
	for (int i = m; i >= m - n + 1; i--) {
		nowans = (nowans * i) % mod;
	}
	for (int i = 1; i <= n; i++) {
		check = (check * i) % mod;
	}
	return nowans / check;
}

void find_ans() {
	for (int i = 3; i <= n; i++) {
		ans = (ans + C(i, n)) % mod;
	}
}

void dfs(int bpos, int x) {
	if (bpos >= 4) {
		int maxx = 0;
		long long xx = 0;
		for (int i = 1; i <= bpos; i++) maxx = max(maxx, b[i]), xx += b[i];
		if (xx > 2 * maxx) {
			ans = (ans + 1) % mod; 
		}
	}
	for (int i = x + 1; i <= n; i++) {
		b[bpos + 1] = a[i];
		dfs(bpos + 1, i);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] != 1) flag = false;
	}
	if (!flag) dfs(1, 0);
	else {
		find_ans();
	}
	cout << ans;
	return 0;
}
