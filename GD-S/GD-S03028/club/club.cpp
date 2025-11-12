#include <bits/stdc++.h>
using namespace std;
struct person{
	int a, b, c, maxx, id;
}p[100005];
int dp[100005][3], tim[100005][5];
bool cmp(person x, person y) {
	return x.maxx > y.maxx;
}
int main() {
	//freopen("club.in", "r", stdin);
	//freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n, m, ans = 0;
		cin >> n;
		m = n / 2;
		memset(dp, 0, sizeof(dp));
		memset(tim, 0, sizeof(tim));
		for (int i = 1; i <= n; i++) {
			int a, b, c;
			cin >> p[i].a >> p[i].b >> p[i].c;
			p[i].maxx = max(p[i].a, max(p[i].b, p[i].c));
			if (p[i].maxx == p[i].a) {
				p[i].id = 1;
			} else if (p[i].maxx == p[i].b) {
				p[i].id = 2;
			} else {
				p[i].id = 3;
			}
		}
		sort(p + 1, p + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			if (tim[i - 1][p[i].id] == m) {
				
			} else {
				dp[i][1] = max(dp[i - 1][1], max(dp[i - 1][2], dp[i - 1][3])) + p[i].a;
				dp[i][2] = max(dp[i - 1][1], max(dp[i - 1][2], dp[i - 1][3])) + p[i].b;
				dp[i][3] = max(dp[i - 1][1], max(dp[i - 1][2], dp[i - 1][3])) + p[i].c;
				if (p[i].id == 1) {
					tim[i][1] = tim[i - 1][1] + 1;
					tim[i][2] = tim[i - 1][2];
					tim[i][3] = tim[i - 1][3];
				} else if (p[i].id == 2) {
					tim[i][1] = tim[i - 1][1];
					tim[i][2] = tim[i - 1][2] + 1;
					tim[i][3] = tim[i - 1][3];
				} else {
					tim[i][1] = tim[i - 1][1];
					tim[i][2] = tim[i - 1][2];
					tim[i][3] = tim[i - 1][3] + 1;
				}
			}
		}
		cout << max(dp[n][1], max(dp[n][2], dp[n][3]));
	}
	return 0;
}
