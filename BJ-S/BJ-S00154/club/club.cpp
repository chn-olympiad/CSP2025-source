#include <bits/stdc++.h>
using namespace std;
inline void file() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
}
const int N = 1e5 + 5;
int n, ans, a[4][N], box[N];
priority_queue<int> q;
void dfs(int x, int c1, int c2, int c3) {
	if(x > n) {
		int sum = 0;
		for(int i = 1; i <= n; i++) sum += a[box[i]][i];
		ans = max(ans, sum);
		return;
	}
	for(int i = 1; i <= 3; i++) {
		box[x] = i;
		if(i == 1 && c1 + 1 > n / 2) continue;
		if(i == 2 && c2 + 1 > n / 2) continue;
		if(i == 3 && c3 + 1 > n / 2) continue;
		if(i == 1) dfs(x + 1, c1 + 1, c2, c3);
		if(i == 2) dfs(x + 1, c1, c2 + 1, c3);
		if(i == 3) dfs(x + 1, c1, c2, c3 + 1);
	}
}
int main() {
	file();
	int T;
	cin >> T;
	while(T--) {
		int flag2 = 1, flag3 = 1;
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[1][i] >> a[2][i] >> a[3][i];
			if(a[2][i] != 0) flag2 = 0;
			if(a[3][i] != 0) flag3 = 0;
		}
		if(n <= 10) {
			dfs(1, 0, 0, 0);
			cout << ans << endl;
		}
		else if(flag2) {
			for(int i = 1; i <= n; i++) q.push(a[1][i]);
			n /= 2;
			while(n--) {
				ans += q.top();
				q.pop();
			}
			cout << ans << endl;
		}
		else cout << 0 << endl;
	}
	return 0;
}