// 这次好难
#include <bits/stdc++.h>
using namespace std;

int n, m, a[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
	int x = a[1];
	sort(a + 1, a + n * m + 1, [&](const int &a, const int &b) {
		return a > b;
	});
	int ansl = 1, ansr = 1;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == x) {
			printf("%d %d\n", ansl, ansr);
			return 0;
		}
		if (ansl % 2 == 1)
			ansr++;
		else
			ansr--;
		if (ansr > n)
			ansr = n, ansl++;
		else if (ansr < 1)
			ansr = 1, ansl++;
	}
}

/*
种花
***** ***** ***** ***** ***** ***** ***** ***** ****  * ***** ***** * ***** *   * *     ***** *
*     *     *       *   *   	*   *   * *   * *   * * *     *     * *     *   * *       *   *
*     *     ****    *   *****   *   *   * *   * *   * * ****  ****  * *     *   * *       *   *
*     *     *       *       *	*   *   * *   * *   * * *     *     * *     *   * *       *   
***** ***** *     ***** *****	*   ***** ***** ****  * *     *     * ***** ***** *****   *   *
*/