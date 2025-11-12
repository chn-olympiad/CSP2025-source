#include<bits/stdc++.h>
using namespace std;

const int maxn = 10 + 5;

int n, m;
int a[105];
int mp[maxn][maxn];

bool cmp(int a, int b) {
	return a > b;
}

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	scanf("%d%d", &n, &m);

	int len = n * m;

	for (int i = 1; i <= len; i++) scanf("%d", &a[i]);
	int flag = a[1];

	sort(a + 1, a + len + 1, cmp);

	int cnt = 1;
	for (int j = 1; j <= m; j++) {
		if (j % 2 == 1) {
			for (int i = 1; i <= n; i++) {
				if (a[cnt] == flag) {
					printf("%d %d", j, i);
					return 0;
				}
				mp[i][j] = a[cnt++];
			}
		} else {
			for (int i = n; i >= 1; i--) {
				if (a[cnt] == flag) {
					printf("%d %d", j, i);
					return 0;
				}
				mp[i][j] = a[cnt++];
			}
		}
	}

	return 0;
}