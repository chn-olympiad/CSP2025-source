#include<bits/stdc++.h>
using namespace std;
struct node {
	int id1, id2, val;
}a[100010];
int t, n, cnt, anss;
bool vis[100010], flag1 = true, flag2 = true;
int q[100010][4];
bool cmp(node a, node b) {
	return a.val > b.val;
}
void dfs(int x, int s, int c1, int c2, int c3) {
	if (x > n) {
		anss = max(anss, s);
		return;
	}
	if (c1 < n / 2) {
		dfs(x + 1, s + q[x][1], c1 + 1, c2, c3);
	}
	if (c2 < n / 2) {
		dfs(x + 1, s + q[x][2], c1, c2 + 1, c3);
	}
	if (c3 < n / 2) {
		dfs(x + 1, s + q[x][3], c1, c2, c3 + 1);
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			vis[i] = false;
			for (int j = 1; j <= 3; j++) {
				cin >> a[++cnt].val;
				a[cnt].id1 = i;
				a[cnt].id2 = j;
				if ((a[cnt].id2 == 2 && a[cnt].val != 0) || (a[cnt].id2 == 3 && a[cnt].val != 0)) {
					flag1 = false;
				}
				if (a[cnt].id2 == 3 && a[cnt].val != 0) {
					flag2 = false;
				}
				q[i][j] = a[cnt].val;
			}
		}
		if (flag1) {
			int ans = 0;
			sort(a + 1, a + cnt + 1, cmp);
			for (int i = 1; i <= n / 2; i++) {
				ans += a[i].val;
			}
			cout << ans << '\n';
		}
		else if (n <= 10) {
			anss = 0;
			dfs(1, 0, 0, 0, 0);
			cout << anss << '\n';
		}
		else {
			sort(a + 1, a + cnt + 1, cmp);
			int ans = 0, s[5] = {0};
			for (int i = 1; i <= cnt; i++) {
				if (s[1] + s[2] + s[3] == n) {
					break;
				}
				if (!vis[a[i].id1] && s[a[i].id2] < n / 2) {
					vis[a[i].id1] = true;
					s[a[i].id2]++;
					ans += a[i].val;
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
