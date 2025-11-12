#include <bits/stdc++.h>
using namespace std;

const int N1 = 10005, N2 = 105;
int n, m, a[N1], r, now, tot, step = 1, s[N2][N2], i = 1, j = 1;
bool haveFind = false;

bool cmp(int x, int y) {
	return x > y;
}

void check() {
	if (step == now) {
		cout << i << " " << j << endl;
		haveFind = true;
	}
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	memset(a, -1, sizeof(a));
	cin >> n >> m;
	tot = n * m;
	for (int i = 1; i <= tot; ++i)
		cin >> a[i];
	r = a[1];
	sort(a + 1, a + tot + 1, cmp);
	for (int i = 1; i <= tot; ++i) {
		if (a[i] == r) {
			now = i;
			break;
		} 
	}
	while (i <= m && j <= n && i >= 1 && j >= 1) {
		check(); 
		while (j >= 1 && j < n) {
			j++, step++;
			check(); 
		}
		i++;
		step++;
		check();
		while (j > 1 && j <= n) {
			if (haveFind) return 0;
			j--, step++;
			check();
		}
		i++;
		step++;
	}
	return 0;
} 
