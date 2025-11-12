#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e4 + 5;
int T, n, ans, a1[N], a2[N], a3[N];

void init() {
	memset(a1, 0, sizeof a1);
	memset(a2, 0, sizeof a2);
	memset(a3, 0, sizeof a3);
	ans = 0;
}

void search(int p, int w, int l1, int l2, int l3) {
	// 3 ^ n
	if (p > n) {
		ans = max(ans, w);
		return;
	}
	if (l1 < n / 2 )
		search(p + 1, w + a1[p], l1 + 1, l2, l3);
	if (l2 < n / 2)
		search(p + 1, w + a2[p], l1, l2 + 1, l3);
	if (l3 < n / 2)
		search(p + 1, w + a3[p], l1, l2, l3 + 1);
}

void __solve1() {
	scanf("%d", &T);
	while (T--) {
		init();
		scanf("%d", &n);
		int a_1 = 0, a_2 = 0, a_3 = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", &a1[i], &a2[i], &a3[i]);
			a_1 |= a1[i];
			a_2 |= a2[i];
			a_3 |= a3[i];
		}
		if (a_2 == 0 && a_3 == 0) {
			// Special A
			sort(a1 + 1, a1 + n + 1);
			for (int j = n; j > n / 2; j--)
				ans += a1[j];
			printf("%d\n", ans);
			continue;
		}
		search(1, 0, 0, 0, 0);
		printf("%d\n", ans);
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	__solve1();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
