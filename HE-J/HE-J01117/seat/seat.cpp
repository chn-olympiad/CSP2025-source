#include <bits/stdc++.h>
using namespace std;
int a[105], n, m;

void find_seat(int me) {
	int id = lower_bound(a + 1, a + 1 + n * m, me) - a;
	id = n * m - id + 1;
	int lie = ((id - 1) / n) + 1;
	if (lie & 1) cout << lie << " " << id - n * (lie - 1);
	else cout << lie << " " << n - (id - n * (lie - 1)) + 1;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> a[1];
	int me = a[1];
	for (int i = 2; i <= n * m; i++) cin >> a[i];
	sort(a + 1, a + 1 + n * m);
	
	find_seat(me);

	return 0;
	
}

