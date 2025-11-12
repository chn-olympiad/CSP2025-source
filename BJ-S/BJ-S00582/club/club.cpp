#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int T, n, v[N][5], ans;
bool vis[N];

void dfs(int cur, int tt, int a, int b, int c) {
	if(a > n/2 || b > n/2 || c > n/2) return;
	if(cur > n) {
		ans = max(ans, tt);
		return;
	}
	dfs(cur+1, tt + v[cur][1], a+1, b, c);
	dfs(cur+1, tt + v[cur][2], a, b+1, c);
	dfs(cur+1, tt + v[cur][3], a, b, c+1);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> v[i][1] >> v[i][2] >> v[i][3];
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
