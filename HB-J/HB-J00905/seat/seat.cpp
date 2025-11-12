#include <bits/stdc++.h>

using namespace std;

int n, m, a[520];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
	int sum = 0;
	for (int i = 1; i <= n * m; i++)
		if (a[i] >= a[1])
			++sum;
	int c = (sum - 1) / n + 1, r;
	if (((sum - 1) / n) % 2)
		r = n - (sum - 1) % n;
	else
		r = (sum - 1) % n + 1;
	printf("%d %d", c, r);
	return 0;
}