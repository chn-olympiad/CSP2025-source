#include <bits/stdc++.h>
using namespace std;

int n, m;
int r;
int pos;
int li, ro;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &r);
	pos = 1;
	for (int i = 2; i <= n * m; ++i) {
		int a;
		scanf("%d", &a);
		if (a > r) {
			++pos;
		}
	}
	
	li = pos / n;
	if (pos % n) {
		++li;
	}
	
	ro = pos % n;
	if (ro == 0) {
		ro = n;
	}
	if (li % 2 == 0) {
		ro = n - ro + 1;
	}
	printf("%d %d", li, ro);
	return 0;
}