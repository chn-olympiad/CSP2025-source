#include <bits/stdc++.h>
using namespace std;

struct xx {
	int w = 0, h = 0, l = 0;
	bool xr = 0;
}a[10009];

bool cmp(xx a, xx b) {
	return a.w > b.w;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].w;
	}
	a[1].xr = true;
	sort(a + 1, a + (n * m) + 1, cmp);
	for (int i = 1, nq = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++, nq++) {
			a[nq].h = i;
			a[nq].l = j;
			if (a[nq].xr) {
				cout << i << ' ' << j << endl;
				return 0;
			}
		}
		if (i + 1 > n) {
			break;
		}
		i++;
		for(int j = m; j > 0; j--, nq++) {
			a[nq].h = i;
			a[nq].l = j;
			if (a[nq].xr) {
				cout << i << ' ' << j << endl;
				return 0;
			}
		}
	}
	
	return 0;
}
