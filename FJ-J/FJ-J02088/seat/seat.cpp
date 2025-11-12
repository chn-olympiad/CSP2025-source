#include <bits/stdc++.h>
using namespace std;
const int N = 510;
struct node {
	int id, x;
}a[N];
bool cmp (node s1, node s2) {
	return s1.x > s2.x; 
}
int n, m, l = 1, h = 1;
int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i].x;
		a[i].id = i;
	}
	sort (a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= n * m; i ++) {
		if (a[i].id == 1) {
			break;
		}
		if (l % 2 == 1) h ++;
		else h --;
		if (h == n + 1) {
			l ++;
			h = n;
		}
		if (h == 0) {
			l ++;
			h = 1;
		}
	}
	cout << l << ' ' << h << endl;
}
