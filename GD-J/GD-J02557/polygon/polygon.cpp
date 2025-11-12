#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
const int N = 5e3 + 10;
int c[N];
int ans = 0;
int n;

void dfs(int x, int v, int j) {
	if (j >= 2) 
		if (v > c[x])
			ans++;
	for (int i = x + 1; i <= n; i++)
		dfs(i, v + c[x], j + 1);
	return ;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> c[i];
	sort(c + 1, c + n + 1);
	for (int i = 1; i <= n - 2; i++)
		dfs(i, 0, 0);
	cout << ans << endl;
	return 0;
}
