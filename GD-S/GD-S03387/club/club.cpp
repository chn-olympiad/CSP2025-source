#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N][4];
int b[N];
int c[4];
long long ans;
int n;

void dfs(int x, int bpos) {
	if (bpos > n) {
		long long nowans = 0;
		for (int i = 1; i <= bpos; i++) nowans += b[i];
		//cout << "\n";
		ans = max(ans, nowans);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (c[i] < n / 2) {
			b[bpos + 1] = a[x][i];
			c[i]++;
			dfs(x + 1, bpos + 1);
			c[i]--;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		ans = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		}
		dfs(1, 0);
		cout << ans << "\n";
	}
	return 0;
} 
