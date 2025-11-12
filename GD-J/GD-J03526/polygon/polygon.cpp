#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[20005], ans;
void dfs(int x, int sum, int l, int maxn) {
	if(l >= 3) {
		if(maxn * 2 < sum) {
			ans++;
		} 
	}
	if(x == n) {
		return;
	}
	for(int i = x + 1; i <= n; i++) {
		dfs(i, sum + a[i], l + 1, max(maxn, a[i]));
	}
	return;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	dfs(0, 0, 0, 0);
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
