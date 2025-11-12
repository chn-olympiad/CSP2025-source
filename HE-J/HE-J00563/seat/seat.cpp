#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
int n, m, a[N], R = 0;

bool cmp(const int &x, const int &y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int l = n * m;
	for (int i = 1; i <= l; i++) {
		scanf("%d", &a[i]);
	}
	R = a[1];
	int id = 0;
	sort(a + 1, a + l + 1, cmp);
	for (int i = 1; i <= l; i++) {
		if (a[i] == R) {
			id = i;
			break;
		}
	}
	int w = id / n + (id % n != 0),
		h = id - (w - 1) * n;
	if (w % 2 == 0) h = n - h + 1;
	printf("%d %d\n", w, h);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


