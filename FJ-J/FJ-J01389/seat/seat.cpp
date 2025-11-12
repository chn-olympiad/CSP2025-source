#include <bits/stdc++.h>
#define N 11
using namespace std;

int n, m;
int a[N * N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	scanf("%d%d", &n, &m);
	
	int R;
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
		
		if (i == 1) {
			R = a[i];
		}
	}
	
	sort(a + 1, a + n * m + 1, greater<int>());
	
	int x = 1, c, r;
	for (int i = 1; i <= n * m; i += n) {
		int y = 1;
		for (int j = i; j <= i + n - 1; j++) {
			if (a[j] == R) {
				c = x;

				if (x % 2) {
					r = y;
				} else {
					r = n - y + 1;
				}
				
				break;
			}

			y++;
		}

		x++;
	}
	
	printf("%d %d\n", c, r);

	return 0;
}