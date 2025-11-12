#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int t = 0;
int n = 0;
int a[N][4] = {};
int f[N][4] = {};
int fp[N][4][4] = {};
int tt[4] = {};
int ans = 0;

void dfs(int x, int sum) {
	ans = max(ans, sum);
	if (x > n) {
		return;
	}
	if (tt[1] + 1 <= n / 2) {
		tt[1]++;
		dfs(x + 1, sum + a[x][1]);
		tt[1]--;
	}
	if (tt[2] + 1 <= n / 2) {
		tt[2]++;
		dfs(x + 1, sum + a[x][2]);
		tt[2]--;
	}
	if (tt[3] + 1 <= n / 2) {
		tt[3]++;
		dfs(x + 1, sum + a[x][3]);
		tt[3]--;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		}
		memset(f, 0, sizeof(f));
		ans = 0;
/*		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				for (int k = 1; k <= 3; k++) {
					if (f[i - 1][k]+ a[i][j] > f[i][j]) {
						if (fp[i - 1][j][j] + 1 <= n / 2) {
							f[i][j] = f[i - 1][k] + a[i][j];
							fp[i][j][j] = fp[i - 1][j][j] + 1;
							for (int t = 1; t <= 3; t++) {
								if (t != j) {
									fp[i][j][t] = fp[i - 1][j][t];
								}
							}
						}
					}
				}
			}
		}*/
		dfs(1, 0);
		cout << ans << endl;
	}
	return 0;
}
