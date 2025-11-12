#include <bits/stdc++.h>
int score[105];
int main() {
	freopen("seat.in", "r", stdin), freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n * m; ++i) scanf("%d", score + i);
	int LR = score[0];
	std::sort(score, score + n * m, std::greater<int>());
	int pm = std::lower_bound(score, score + n * m, LR, std::greater<int>()) - score, lie = pm / n;
	int hang = lie & 1 ? (n - pm % n) : pm % n + 1;
	printf("%d %d", lie + 1, hang);
}
