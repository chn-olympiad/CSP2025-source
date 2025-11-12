#include<bits/stdc++.h>
using namespace std;

int n, m, a[110], l;

bool cmp(const int &A, const int &B) {
	return A > B; 
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	l = n * m;
	for (int i = 1; i <= l; i++)
		scanf("%d", &a[i]);
	int t = a[1], y = 0;
	sort(a + 1, a + l + 1, cmp);
	for (int i = 1; i <= l; i++)
		if (a[i] == t) {
			y = i;
			break;
		}
	int j = 0; 
	for (int i = 1; i <= m; i++) {
		int x = i % 2;
		if (j + n < y)
			j += n;
		else {
			if (x) {
				if (y % n == 0) {
					printf("%d %d\n", i, n);
					break;
				}
				else{
					printf("%d %d\n", i, y % n);
					break;
				}
			} else {
				if (y % n == 0) {
					printf("%d %d\n", i, 1);
					break;
				} else {
					printf("%d %d\n", i, n - (y % n) + 1);
					break;
				}
			}
		}
	}
	return 0;
}
