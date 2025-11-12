#include <bits/stdc++.h>
using namespace std;
int a[100010][3];
long long ans;
int n;
int cmp(int x, int y) {
	return x > y;
}
void dfs(int x, int v1, int v2, int v3, long long sum) {
	if(x == n) {
		ans = max(ans, sum);
		return ;
	}
	if(v1 > n / 2) return ;
	if(v2 > n / 2) return ;
	if(v3 > n / 2) return ;
	for (int i = x + 1; i <= n; i++) {
		if(v1 < n / 2)
			dfs(i, v1 + 1, v2, v3, sum + a[i][1]);
		if(v2 < n / 2)
			dfs(i, v1, v2 + 1, v3, sum + a[i][2]);
		if(v3 < n / 2)
			dfs(i, v1, v2, v3 + 1, sum + a[i][3]);
	}
	return ;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		ans = -1;
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				a[i][j] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				cin >> a[i][j];
		int flag = 1, ok = 1;
		for (int i = 1; i <= n; i++) {
			if(!(a[i][2] == 0 && a[i][3] == 0)) flag = 0;
			if(a[i][3] != 0) ok = 0;
		}
		if(flag == 1) {
			int b[100010];
			memset(b, 0, sizeof(b));
			for (int i = 1; i <= n; i++) b[i] = a[i][1];
			sort(b + 1, b + 1 + n, cmp);
			long long ret = 0;
			for (int i = 1; i <= n / 2; i++) ret += b[i];
			cout << ret;
		} 
		else {
			dfs(0, 0, 0, 0, 0);
			cout << ans << "\n";
		}
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
