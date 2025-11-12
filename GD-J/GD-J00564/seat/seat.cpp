#include <stdio.h>
#include <algorithm>
int n, m, points[32768];
bool cmp(int a, int b) {
	return (a & 0b11111111) > (b & 0b11111111);
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	int i, Target = 0, j;
	for(i = 1; i <= n * m; i += 1) {
		scanf("%d", &points[i]);
	}
	points[1] |= 0b100000000;
	std::sort(points + 1, points + 1 + n * m, cmp);
	for(i = 1; i <= n * m; i += 1) {
		if(points[i] & 0b100000000) {
			Target = i;
			break;
		}
	}
	//printf("%d\n", Target);
	printf("%d %d", (Target - 1) / n + 1, ((((Target - 1) / n + 1) & 0b1) == 1) ? ((Target - 1) % n + 1) : (n - (Target - 1) % n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
