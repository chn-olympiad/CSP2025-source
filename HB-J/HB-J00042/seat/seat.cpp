#include <bits/stdc++.h>
using namespace std;

int n, m, a[105], tmp, idx;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	const int N = n * m;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	tmp = a[1];
	sort(a + 1, a + N + 1, cmp);
	for (int i = 1; i <= N; i++) {
		if (a[i] == tmp) {
			idx = i;
			break;
		}
	}
	printf("%d %d", (idx - 1) / n + 1, ((idx - 1) / n + 1) % 2 == 0 ? n - ((idx - 1) % n + 1) + 1 : (idx - 1) % n + 1);
	return 0;
}
