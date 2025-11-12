#include <iostream>
#include <algorithm>

using namespace std;

int a[105];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);

	int n, m;
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i ++)
		scanf ("%d", &a[i]);
	int tgt = a[1];
	
	sort (a + 1, a + n*m + 1, cmp);
//	for (int i = 1; i <= n * m; i ++)
//		cout << a[i] << "\n";
//	cout << ">" << tgt << "\n";
	
	int idx = 1, idy = 1;
	for (int i = 1; i <= n * m; i ++) {
		if (a[i] == tgt) {
			cout << idy << " " << idx;
			break;
		}
		idx += ((idy % 2 == 1) ? 1 : -1);
		if (idx > n) 
			idx = n, idy ++;
		if (idx < 1)
			idx = 1, idy ++;
	}
	return 0;
}
/*
2 2
99 100 97 98

3 3
94 95 96 97 98 99 100 93 92
*/
