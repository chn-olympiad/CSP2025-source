#include <bits/stdc++.h>
using namespace std;
long long n, a[500005], k, sum;
long long check; 
int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	scanf ("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
		if (a[i] == 1) check++;
	}
	if (k == 0 && check == n) sum = (n - n % 2) / 2;
	else if (k == 1) sum = check;
	printf ("%lld", sum); 
	return 0;
}
