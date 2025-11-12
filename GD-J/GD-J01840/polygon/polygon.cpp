// ¶à±ßÐÎ(polygon) 
#include <cstdio>
#define LL long long
using namespace std;
const int N = 5005;
const int MOD = 998244353;
int n, ans, a[N], b[N];
void dfs(int, int, int);
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
	for (int i = 3; i <= n; i++) dfs(1, 1, i);
	printf ("%d", ans % MOD);
	return 0;
}
void dfs(int x, int y, int z) {
	if (y > z) {
		int max = 0, sum = 0;
		for (int i = 1; i <= z; i++) {
			sum += b[i];
			if (b[i] > max) max = b[i];
		}
		if (sum > max * 2) ans++;
		ans %= MOD;
		return;
	}
	for (int i = x; i <= n; i++) {
		b[y] = a[i];
		dfs(i + 1, y + 1, z);
		b[y] = 0;
	}
	return;
}
