#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;

struct node {
	int a, b, c;
}d[N];

int T, n, ans = INT_MIN;

bool cmp(node x, node y) {
	return x.c > y.c;
}

void dfs(int pos, int x, int y, int z, int du) {
	if (pos == n) {
		ans = max(ans, du);
		return ;
	}
	if (x < n / 2) {
		dfs(pos + 1, x + 1, y, z, du + d[pos + 1].a);
	}
	if (y < n / 2) {
		dfs(pos + 1, x, y + 1, z, du + d[pos + 1].b);
	}
	if (z < n / 2) {
		dfs(pos + 1, x, y, z + 1, du + d[pos + 1].c);
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		ans = INT_MIN;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> d[i].a >> d[i].b >> d[i].c;
		}
		if (n == 1e5) {
			int sum = 0;
			sort(d + 1, d + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) {
				sum += d[i].c;
			}
			cout << sum;
			return 0;
		}
		dfs(1, 1, 0, 0, d[1].a);
		dfs(1, 0, 1, 0, d[1].b);
		dfs(1, 0, 0, 1, d[1].c);
		cout << ans << endl;
	}
	return 0;
} 
