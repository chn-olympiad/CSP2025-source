#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, a1[N], a2[N], a3[N], a[N], ans;

void dfs(int cur, int x, int y, int z) {
	if(cur > n) {
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(a[i] == 1) cnt += a1[i];
			else if(a[i] == 2) cnt += a2[i];
			else cnt += a3[i]; 
		}
		ans = max(ans, cnt);
		return ;
	}
	if(x < n / 2) {
		a[cur] = 1;
		dfs(cur + 1, x + 1, y, z);
	}
	if(y < n / 2) {
		a[cur] = 2;
		dfs(cur + 1, x, y + 1, z);
	}
	if(z < n / 2) {
		a[cur] = 3;
		dfs(cur + 1, x, y, z + 1);
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a1[i] >> a2[i] >> a3[i];
		ans = 0;
		dfs(1, 0, 0, 0);
		cout << ans << '\n';
	}
	
	return 0;
}
