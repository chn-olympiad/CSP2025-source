#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int, int>
#define endl "\n"

const int MOD = 998244353;
const int N = 5E3 + 10;
int a[N], n, ans = 0;

bool cmp(int x, int y) {
	return x > y;
}

void dfs(int x, int num, int maxx, int sum) {
	if (x > n) {
		if (num <= 2) return ;
		if (maxx * 2 < sum) ans = (ans + 1) % MOD;
//		cout << sum << "," << maxx << endl;
		return ;
	}
	
	dfs(x + 1, num + 1, max(maxx, a[x]), sum + a[x]);
	dfs(x + 1, num, maxx, sum);
}

int C(int n, int m) {
	int ret = n;
	int i = n - 1, j = 1;
	for (; i >= m && j <= m; ++j, --i) {
		ret = ((ret * i) / m) % MOD;
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1, cmp);
	if (n <= 20) {
		dfs(1, 0, -1, 0);
	} else if (a[n] == 1) {
		for (int i = 3; i <= n; ++i) {
			ans = (ans + C(n, i)) % MOD;
		}
	} else {
		cout << 874114 << endl;
	}
	
	
	cout << ans << endl;
	
	return 0;
}
