#include <iostream>
using namespace std;

int n, m, s[505], t[505], bj[505], p[505], ans = 0;

void dfs(int step) {
	if(step > n) {
		int cnt = 0, succ = 0;
		for(int i = 1; i <= n; i++) {
			if(s[i] == 0) cnt++;
			else if(cnt >= t[p[i]]) cnt++;
			else succ++;
		}
		if(succ >= m) ans++;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(bj[i]) continue;
		bj[i] = 1;
		p[step] = i;
		dfs(step + 1);
		p[step] = 0;
		bj[i] = 0;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		char T;
		cin >> T;
		s[i] = T - '0';
	}
	for(int i = 1; i <= n; i++) cin >> t[i];
	dfs(1);
	cout << ans;
}
