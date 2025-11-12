#include<bits/stdc++.h>
#define For(i, x, y) for (int i = x; i <= y; i++) 
using namespace std;
struct STU {
	int sc, id;
} a[1005];
bool cmp(STU x, STU y) {
	return x.sc > y.sc;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	For(i, 1, n * m) {
		cin >> a[i].sc;
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	int cnt = 1, x = 1, y = 1;
	while (cnt <= n * m) {
		if (a[cnt].id == 1) {
			cout << x << " " << y;
			break;
		}
		if (x % 2) y++;
		else y--;
		if (y < 1) y = 1, x++;
		if (y > n) y = m, x++;
		cnt++;
	}
}
