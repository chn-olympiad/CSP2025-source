#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, i, j, k, x, y, a[N];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(a[1]=k, i=2; i<=n*m; i++) scanf("%d", a+i);
	sort(a+1, a+n*m+1);
	j = lower_bound(a+1, a+n*m+1, k) - a, j = n*m-j+1;
	x = j/n+1, y = j%n;
	if(!y) x--, y = n;
	printf("%d %d\n", x, x&1?y:n-y+1);
	return 0;
}
