#include<bits/stdc++.h>
using namespace std;
int n, m, a[1010], me;
int cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> m >> n;
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
	}
	me = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	int pos = 1, now = 1;
	for (int i = 1; i <= n; i++) {
		if (now == 1) {
			while (now <= m) {
				if (a[pos] == me) return cout << i << " " << now, 0;
				now++;
				pos++;
			}
			now--;
		}else {
			while (now >= 1) {
				if (a[pos] == me) return cout << i << " " << now, 0;
				now--;
				pos++;
			}
			now++;
		}
	}
	return 0;
}
