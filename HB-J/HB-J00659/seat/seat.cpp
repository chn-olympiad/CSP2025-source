#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;
const int MAXN = 15, MAXM = 15, MXSZ = 105;
int n, m;
int a[MAXN][MAXM];
pr sco[MXSZ];
int cnt;
bool cmp(pr x, pr y) {
	return x.first > y.first;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; ++i) {
		scanf("%d", &sco[i].first);
		sco[i].second = i;
	}
	sort(sco + 1, sco + 1 + n * m, cmp);
	for (int j = 1; j <= m; ++j) {
		if (j & 1) {
			for (int i = 1; i <= n; ++i) {
				a[i][j] = sco[++cnt].second;
				if (a[i][j] == 1) {
					printf("%d %d", j, i);
					return 0;
				}
			}
		} else {
			for (int i = n; i; --i) {
				a[i][j] = sco[++cnt].second;
				if (a[i][j] == 1) {
					printf("%d %d", j, i);
					return 0;
				}
			}
		}
	}
	return 0;
}