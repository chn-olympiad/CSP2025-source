#include <bits/stdc++.h>
using namespace std;
const int NN = 1e5 + 10;
int ans, a[NN][4];
void dfs(int x, int y, int z, int res, int id, int n) {
	if(id == n + 1) { ans = max(ans, res); return ; }
	if(x + 1 <= n / 2) dfs(x + 1, y, z, res + a[id][1], id + 1, n);
	if(y + 1 <= n / 2) dfs(x, y + 1, z, res + a[id][2], id + 1, n);
	if(z + 1 <= n / 2) dfs(x, y, z + 1, res + a[id][3], id + 1, n);
}
int pts20(int n) {
	dfs(0, 0, 0, 0, 1, n);
	return ans;
}
int A[NN];
int Apts(int n) {
	for(int i = 1; i <= n; i ++) A[i] = a[i][1];
	sort(A + 1, A + 1 + n);
	for(int i = n; i > n / 2; i --) ans += A[i];
	return ans;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T --) {
		bool FA = true;
		int n; cin >> n; ans = 0;
		for(int i = 1; i <= n and cin >> a[i][1] >> a[i][2] >> a[i][3]; i ++)
		  if(a[i][2] != 0 || a[i][3] != 0) FA = false;
		if(n <= 30) { cout << pts20(n) << '\n'; continue; }
		if(FA) { cout << Apts(n) << '\n'; continue; }
		for(int i = 1; i <= n; i ++) ans += max(a[i][1], max(a[i][2], a[i][3]));
		cout << ans << '\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
