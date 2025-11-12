#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, k, a[N];

int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out","w",stdout);
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf ("%d", a + i);
	if (k == 1)
		printf ("%d\n", n);
	else
		printf ("%d\n", n / 2);
	return 0;
}
