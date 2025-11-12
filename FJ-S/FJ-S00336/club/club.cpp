#include <bits/stdc++.h>
using namespace std;
int a[100005][3];
bool b[100005][3];
int news[3], n, t, ans=-1;
void func(int k, int ansr) {
	if (k == n) {
		ans = max(ans, ansr);
	}
	for (int j = 0; j < 3; j++) {
		if (!b[k][j] && news[j] < n/2) {
			news[j] ++;
			ansr += a[k][j];
			b[k][j] == 1;
			func(k+1, ansr);
			b[k][j] == 0;
			ansr -= a[k][j];
			news[j]--;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(news, 0, sizeof(news));
		ans = -1;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d%d%d", &a[j][0], &a[j][1], &a[j][2]);
		}
		func(0, 0);
		printf("%d\n", ans);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
