#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n, m, selfMarks, a[N * N];

int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out","w",stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf ("%d", a + i);
	selfMarks = a[1];
	sort (a + 1, a + n * m + 1);
	reverse (a + 1, a + n * m + 1);
	//~ for (int i = 1; i <= n * m; i++)
		//~ printf ("%d ", a[i]);
	int selfNumber;
	for (int i = 1; i <= n * m; i++)
		if (a[i] == selfMarks) {
			selfNumber = i;
			break;
		}
	//~ printf ("%d %d\n", selfMarks, selfNumber);
	printf ("%d %d\n", (selfNumber + n - 1) / n, ((selfNumber - 1) % (2 * n) + 1) > n ? (2 * n - (selfNumber - 1) % (2 * n)) : ((selfNumber - 1) % (2 * n) + 1));
	return 0;
}
