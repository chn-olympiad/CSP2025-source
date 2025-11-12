#include <iostream>
#include <cstdio>
using namespace std;

long long MOD = 998244353;
const int MAXN = 5005;
int n, cnt, a[MAXN];
bool can_make(long long edge_sum, int max_edge) {
	return edge_sum > 2 * max_edge;
}
void dfs(int id, int edge_num, int max_edge, long long edge_sum) {
	if (edge_num >= 3 && can_make(edge_sum, max_edge)) {
		++cnt;
		cnt %= MOD;
	}
	for (int i = id + 1; i <= n; ++i) {
		dfs(i, edge_num + 1, max(max_edge, a[i]), edge_sum + a[i]);
	}
}

unsigned long long quick_power(int a, unsigned long long b) {
	if (b == 0)return 1;
	if (b == 1)return a;
	unsigned long long res = quick_power(a, b / 2);
	res = res * res % MOD;
	if (b & 1)res *= a;
	return res;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	int max_ai = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		max_ai = max(max_ai, a[i]);
	}
	if (max_ai == 1) {
		unsigned long long res = quick_power(2, n);
		res -= 1;
		res -= n % MOD;
		res -= n*(n-1)/2 % MOD;
		res -= n*(n-1)*(n-2)/6 % MOD;
		cout << res % MOD;
		return 0;
	}
	dfs(0, 0, 0, 0);
	cout << cnt;
	return 0;
}
