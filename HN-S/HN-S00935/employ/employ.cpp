#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m, ans, p[N], c[N], vis[N];
string a;
bool check() {
	int x = 0;
	for (int i = 1; i <= n; i ++) {
		if (x >= c[p[i]]) { 
			x ++;
			continue; 
		} 
		if (a[i] == '0')
			x ++;
	}
	return n - x >= m;
}
void dfs(int u) {
	if (u == n + 1) {
		if (check())
			ans ++;
		return;
	}
	for (int i = 1; i <= n; i ++) {
		if (vis[i])
			continue;
		p[u] = i;
		vis[i] = 1;
		dfs(u + 1);
		vis[i] = 0;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> a;
	a = " " + a;
	for (int i = 1; i <= n; i ++)
		cin >> c[i];
	dfs(1);
	cout << ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
