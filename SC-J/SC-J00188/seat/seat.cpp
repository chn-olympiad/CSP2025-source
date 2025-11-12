#include <cstdio>
#include <algorithm>
typedef long long ll;
int n, m, a, b, cnt;
int main() {
	//qwq rp++!
	//Ya int_4096 desu.
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%d", &a);
	for (int i = 2; i <= n * m; i++)
		scanf("%d", &b), cnt += (b > a);
	int x = 1, y = 1;
	while (cnt) {
		if (y & 1) {
			if (x == n) y++;
			else x++;
		} else {
			if (x == 1) y++;
			else x--;
		}
		cnt--;
	}
	printf("%d %d\n", y, x); // Xian Lie Hou Hang.
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
CSP-J 2025
KaoShengMiHuoXingWeiDaShang:
8:35
Open T2.
n <= 10, m <= 10?
just emulate it.
8:56
finished.
ZheTiHeYiWei?
*/