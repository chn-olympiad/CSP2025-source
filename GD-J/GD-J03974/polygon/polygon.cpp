#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 10, mod = 998244353; 
int n, a[N], stu[N], ans[N];
long long cnt;

void dfs(int u, int step, int len) {
	if (u == len+1) {
		int maxn = 0, sum = 0;
		for (int i = 1; i < u; i++) {
			sum += a[ans[i]];
			maxn = max(a[ans[i]], maxn);
		}
		if (sum > maxn * 2) cnt++;
		cnt %= mod;
		return ;
	}
	for (int i = step; i <= n; i++) {
		if (!stu[i]) {
			stu[i] = 1;
			ans[u] = i;
			dfs(u+1, i+1, len);
			stu[i] = 0;
		}
	}
}
void f() {
	for (int i = 3; i <= n; i++) {
		dfs(1, 1, i);
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	f();
	cout << cnt % mod;
	return 0;
}
