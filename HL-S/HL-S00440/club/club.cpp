#include <bits/stdc++.h>
using namespace std;

int t, n, ans;
int a[100005][5], cnt[5];
int c[100005];

int maxm(int x, int y, int z) {
	if (x >= y && x >= z) return 1;
	if (y >= x && y >= z) return 2;
	if (z >= x && z >= y) return 3;
}


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		memset(cnt, 0, sizeof(cnt));
		priority_queue<int, vector<int>, greater<int> > que;
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", &a[i][1], &a[i][2], &a[i][3]);
			c[i] = maxm(a[i][1], a[i][2], a[i][3]);
			ans += a[i][c[i]];
			cnt[c[i]]++;
		}
		int most = maxm(cnt[1], cnt[2], cnt[3]);
		if (cnt[most] <= n / 2) printf("%d\n", ans);
		else {
			for (int i = 1; i <= n; i++) {
				if (c[i] == most) {
					int minm = 1e9;
					for (int k = 1; k <= 3; k++) {
						if (k != most) minm = min(minm, a[i][most] - a[i][k]);
					}
					que.push(minm);
				}
			}
			while (cnt[most] > n / 2) {
				ans -= que.top();
				que.pop();
				cnt[most]--;
			}
			printf("%d\n", ans);
		}
	}
	return 0;	
}
