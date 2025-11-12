#include <bits/stdc++.h>
#define GXOI ioxg
using namespace std;
const int N = 505;
int n, m, a[N], c[N], g[N], ans;
void dfs (int x) {
	if (x == n + 1) {
		//for (int i = 1; i <= n; i ++)
		//	cout << g[i] << " ";
		//cout << endl;
		int sad = 0, happy = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[g[i]] <= sad) {
				sad ++;
				continue;				
			}
			if (c[i] == 0)
				sad ++;
			else
				happy ++;
		}
		if (happy >= m)
			ans ++;
		return;
	}
	for (int i = 1; i <= n; i ++) {
		if (g[i] == 0) {
			g[i] = x;
			dfs (x + 1);
			g[i] = 0;
		}
	}
}
int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		char x;
		cin >> x;
		c[i] = x -'0';
	}
	//for (int i = 1; i <= n; i ++)
	//	cout << c[i] << " ";
	//cout << endl;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	dfs (1);
	cout << ans << endl;
	return 0;
}
