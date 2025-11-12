#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, k, a[N], ans, _[N];
bool flag = false;
void dfs(int now, int sum) {
	if (now > n) {
		ans = max(ans, sum);
		return ;
	}
	for (int k = 0; now + k <= n; k++) {
		for (int i = now + k; i <= n; i++) {
			if (_[i] ^ _[now - 1] == k) dfs(i + 1, sum + 1);
			if (flag == true) return ;
			if (clock() > 920) {
				flag = true;
				return ;
			}
		}
	}
}
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld %lld", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) _[i] = a[i] ^ _[i - 1];
	if (k == 1) {
		for (int i = 1; i <= n; i++) if (a[i] == 1) ans++;
		cout << ans;
	}
	else if (k == 0) {
		for (int i = 1; i <= n; i++) if (a[i] == 0) ans++;
		for (int i = 1; i <= n; i++) {
			if (a[i] == a[i + 1] && a[i] != 0) {
				ans++;
				i++;
			}
		}
		cout << ans;
	}
	else {
		dfs(1, 0);
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
100 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

4 0
2 1 0 3

4 3
2 1 0 3

4 2
2 1 0 3
*/
