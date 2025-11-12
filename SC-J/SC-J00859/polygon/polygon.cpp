#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int n, a[N], s[N];
long long op[N];
long long ans;
void dfs(int x, int k, int rt) {
	if(!x){
		return;
	}
	if (k > rt) {
		for (int i = 1; i < x; i++) {
			ans += op[x-1] / (op[i] * op[x - i-1]) % 998 % 244 % 353;
		}
		ans += 1;
		return;
	}
	for (int i = x - 1; i >= 1; i--) {
		dfs(i, k + a[i], rt);
	}
}
void qm() {
	long long er = 1;
	op[0] = 1;
	for (int i = 1; i <= n; i++) {
		er *= i;
		er = er % 998 % 244 % 353;
		op[i] = er;
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	qm();
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		s[i] += s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		if(s[i] <= a[i]*2) continue;
		dfs(i, a[i], a[i] * 2);
	}
	cout << ans;

	return 0;
}
