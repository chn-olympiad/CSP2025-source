#include<iostream>
using namespace std;

const int M = 5010; 
int n, ans, a[M];

void dfs(int k, int maxn, int num) {
	if (num - maxn > maxn) ans++;
	if (k == n) return;
	for (int i = k + 1; i <= n; i++)
		dfs(i, max(maxn, a[i]), num + a[i]);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 0, 0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
