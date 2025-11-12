#include <bits/stdc++.h>
using namespace std;
const int MAXN = 12;
int n, m;
int score[MAXN * MAXN];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &score[i]);
	}
	int score_R = score[1];
	for (int i = 1; i <= n * m; i++) {
		if (score[i] < score[i + 1]) {
			swap(score[i], score[i + 1]);
		}
	}
	for (int i = 1; i <= n * m; i++) {
		if (score[i] == score_R) {
			int c = (i - 1) / n;
			int r = (i - 1) % n;
			if (c % 2 == 1) {
				r = n - r - 1;
			}
			printf("%d %d", c + 1, r + 1);
			break;
		}
	}
	return 0;
}
