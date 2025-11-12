#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 10;
const ll M = 998244353;
int n;
ll a[N];
ll b[N], ans;

void dfs(int i, ll m, ll s) {
	i++;
	if (i > n) {
		if (m * 2 < s) {
			ans++;
		}
		return;
	}
	dfs(i, max(m, a[i]) % M, (s + a[i]) % M);
	dfs(i, m % M, s % M);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = b[i - 1] + a[i];
	}
	dfs(0, a[1], 0);
	printf("%d\n", ans);
	return 0;
}
