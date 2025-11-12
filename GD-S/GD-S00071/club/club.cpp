#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, a[N][3] = {{0}};
int id[N] = {0};
int b[N] = {0};

void slv() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
	int cnt[3] = {0, 0, 0};
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int mx = max(a[i][0], max(a[i][1], a[i][2]));
		ans += mx;
		for (int j = 0; j < 3; j++)
			if (a[i][j] == mx) {
				cnt[j]++;
				id[i] = j;
				break;
			}
	} 
	int res = max(cnt[0], max(cnt[1], cnt[2]));
	if (res <= n / 2) {
		printf("%d\n", ans);
		return;
	}
	int pos = -1;
	for (int i = 0; i < 3; i++) if (cnt[i] == res) pos = i;
	int m = 0;
	for (int i = 1; i <= n; i++)
		if (id[i] == pos) {
			int mx = 0;
			for (int j = 0; j < 3; j++) if (j != pos) mx = max(mx, a[i][j]);
			b[++m] = mx - a[i][pos];
		}
	sort(b + 1, b + m + 1, greater<int>());
	for (int i = 1; i <= res - n / 2; i++) ans += b[i];
	printf("%d\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) slv();
	return 0;
} 
