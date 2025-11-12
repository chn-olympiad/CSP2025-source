#include <bits/stdc++.h>
using namespace std;

const int N = 5009, Mod = 998244353;
int f[N][N], a[N], n, ans;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 0; i < a[1]; i++)
		f[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < N; j++) {
			f[i][j] = f[i - 1][j] + (a[i] > j);
			f[i][j] = (f[i][j] + f[i - 1][max(j - a[i], 0)]) % Mod;
		}
		if (i > 2)
			ans = (ans + f[i - 1][a[i]]) % Mod;
	} 
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}