#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int a[5010];
int n;
long long ans = 0;

void dfs(int floor, int num, int beg, long long sum, int maxnum) {
	if (num == floor) {
		if (sum > maxnum * 2) {
			++ans;
			ans %= MOD;
		}
		return ;
	}
	for (int i = beg; i <= n - floor + num + 1; i++)
		dfs(floor, num + 1, i + 1, sum + a[i], max(maxnum, a[i]));
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 3; i <= n; i++)
		dfs(i, 0, 1, 0, 0);
	printf("%lld\n", ans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
