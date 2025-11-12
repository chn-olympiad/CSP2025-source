#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m;
int a[N];

bool cmp(const int& a, const int& b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int tot = n * m;
	for (int i = 1; i <= tot; i++) {
		scanf("%d", &a[i]);
	}
	int num = a[1];
	sort(a + 1, a + 1 + tot, cmp);
	for (int i = 1; i <= tot; i++) {
		if (a[i] == num) {
			num = i;
			break;
		}
	}
	int x, y;
	if (num % n == 0) {
		x = num / n;
		y = (x & 1) == 1 ? n : 1;
	} else {
		x = num / n + 1;
		y = num % n;
		y = (x & 1) == 1 ? y : n - y + 1;
	}
	printf("%d %d", x, y);
	return 0;
}
