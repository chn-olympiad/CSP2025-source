#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e5 + 5;

struct node {
	int v, i;
} s[N];

int n, a[N][4];
int ans, num[4];
int A = 1, B = 1;

bool cmp(node a, node b) {
	return a.v > b.v;
}

void dfs(int t, int sum) {
	if (t > n) {
		ans = max(sum, ans);
		return ;
	}
	for (int i = 1; i <= 3; i++) {
		if (num[i] >= n / 2) continue;
		num[i]++;
		dfs(t + 1, sum + a[t][i]);
		num[i]--;
	}
	return ;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if (j == 3 && a[i][j]) A = B = 0;
				if (j == 2 && a[i][j]) A = 0;
			}
		}
		if (A || B) {
			for (int i = 1; i <= n; i++) {
				s[i].v = a[i][1] - a[i][2];
				s[i].i = i;
			}
			sort(s + 1, s + 1 + n, cmp);
			int ans = 0;
			for (int i = 1; i <= n / 2; i++) {
				ans += a[s[i].i][1];
			}
			for (int i = n / 2 + 1; i <= n; i++) {
				ans += a[s[i].i][2];
			}
			cout << ans << "\n";
		} else {
			ans = 0;
			dfs(1, 0);
			cout << ans << "\n";
		}
	}
	return 0;
}
