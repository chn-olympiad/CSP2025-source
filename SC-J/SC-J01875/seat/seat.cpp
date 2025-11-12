#include <bits/stdc++.h>
using namespace std;
struct sx{
	int chengji, id;
};
bool cmp(sx a, sx b) {
	return a.chengji > b.chengji;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	sx a[101];
	cin >> n >> m;
	for (int i = 1; i <= n * m;i++) {
			cin >> a[i].chengji;
			a[i].id = i;
	}
	sort(a + 1, a + 1 + n * m, cmp);
	int hang = 1, lie = 1;
	for (int i = 1; i <= n * m; i++) {
		if (a[i].id == 1) {
			cout << lie << " " << hang;
		} else {
			if (lie % 2 == 0) {
				hang--;
				if (hang == 0) {
					hang = 1;
					lie++;
				}
			} else {
				hang++;
				if (hang == n + 1) {
					hang = n;
					lie++;
				}
			}
		}
	}
	return 0;
}