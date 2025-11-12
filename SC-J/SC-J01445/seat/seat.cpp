#include <iostream>
#include <math.h>
using namespace std;
const int N = 15;
int n, m, c, r, rs, pos = 1;
int score[N * N];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	rs = n * m;
	for (int i = 1; i <= rs; i++) {
		scanf("%d", &score[i]);
		if (score[i] > score[1])
			pos++;
	}
	c = ceil(pos * 1.0 / n);
	r = pos - (c - 1) * n;
	if (c % 2 == 0) r = n - r + 1;
	printf("%d %d\n", c, r);
	return 0;
}
