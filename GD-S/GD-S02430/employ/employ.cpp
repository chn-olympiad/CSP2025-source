#include <bits/stdc++.h>
using namespace std;
//4  employ
int a[550], b[550], w, n, m, cnt = 1;
int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
//	printf("%d", rand());
	string s;
	scanf("%d%d", &n, &m);
	scanf("%s", &s);
	for (int i = 1; i <= n; i++) cin >> a[i];
	while (w <= n) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[j] < a[i]) b[i] = a[j];
			}
		}
		int x = b[1];
		for (int i = 1; i <= n; i++) {
			if (b[i] != x) {
				++cnt;
				x = b[i];
			}
		}
		w++;
	}
	printf("%d", cnt);
	return 0;
}
