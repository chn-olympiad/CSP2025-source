#include <bits/stdc++.h>
using namespace std;
bool cmp (int x, int y) {
	return x > y;
}
int a[105];
int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	int n, m;
	scanf ("%d %d", &n, &m);
	int all = n * m;
	for (int i=1; i<=all; i++)
		scanf ("%d", &a[i]);
	int student = a[1]; 
	sort (a + 1, a + 1 + all, cmp);
	int k=1; bool flag = true;
	for (int i=1; i<=m; i++) { 
		if (flag) {
			for (int j=1; j<=n; j++) {
				if (a[k] == student) {
					printf ("%d %d\n", i, j);
					return 0;
				}
				k++;
			}
			flag = !flag;
		}
		else {
			for (int j=n; j>=1; j--) {
				if (a[k] == student) {
					printf ("%d %d\n", i, j);
					return 0;
				}
				k++;
			}
			flag = !flag;
		}
	}
	return 0;
}
