#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans;
int id[510], f[510], a[510];
string s;
void dfs(int dep) {
	if (dep == n + 1) {
		int cnt = 0;
		for (int i = 1; i <= n; i ++) if (a[id[i]] >= i && s[i - 1] == '1') cnt ++;
		if (cnt >= m) ans ++;
	}
	for (int i = 1; i <= n; i ++) {
		if (f[i]) continue;
		else {
			f[i] = 1;
			id[dep] = i;
			dfs(dep + 1);
			f[i] = 0;
			id[dep] = 0;
		}
	}
}
int main() {
	freopen("empoly.in", "r", stdin); 
	freopen("empoly.out", "w", stdout); 
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i ++) cin >> a[i], a[i] ++;
	dfs(1);
	cout << ans;
}
/*
Ren5Jie4Di4Ling5%
*/
