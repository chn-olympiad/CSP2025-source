// 这次好难
#include <bits/stdc++.h>
using namespace std;

char s[1000100];
int l, cnt, num[1000100];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	l = strlen(s + 1);
	for (int i = 1; i <= l; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			num[++cnt] = s[i] - '0';
	}
	sort(num + 1, num + cnt + 1, [&](const int &a, const int &b) {
		return a > b;
	});
	for (int i = 1; i <= cnt; i++)
		printf("%d", num[i]);
}

/*
种花
***** ***** ***** ***** ***** ***** ***** ***** ****  * ***** ***** * ***** *   * *     ***** *
*     *     *       *   *   	*   *   * *   * *   * * *     *     * *     *   * *       *   *
*     *     ****    *   *****   *   *   * *   * *   * * ****  ****  * *     *   * *       *   *
*     *     *       *       *	*   *   * *   * *   * * *     *     * *     *   * *       *   
***** ***** *     ***** *****	*   ***** ***** ****  * *     *     * ***** ***** *****   *   *
*/