#include <bits/stdc++.h>
#define ll long long 
#define N 111
#define inf 0x7fffffff
using namespace std;
int n, m;
int a[N], key;
int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", a + i);
		a[i]  = -a[i];
	}
	key = a[1];
	sort(a + 1, a + n * m + 1);
	int pos = lower_bound (a + 1, a + n * m + 1, key) - a;
	int md = pos % n;
	int ch = pos / n;
	if (md == 0)
		if (ch % 2) 
			printf("%d %d", ch, n);
		else 
			printf("%d %d", ch, 1);
	else 
		if(ch % 2) 
			printf("%d %d", ch + 1, n - md + 1);
		else 
			printf("%d %d", ch + 1, md);
	return 0;
} 
