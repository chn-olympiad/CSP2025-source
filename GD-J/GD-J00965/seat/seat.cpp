#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, s, x, y, a[105];
int main (){
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdin);
	scanf ("%d %d", &n, &m);
	for (i=1; i<=n*m; i++) {
		scanf ("%d", &a[i]);
		if (i==1) continue;
		if (a[i]>a[1]) k++;
	}
	k++;
	s=(k%(n*2));
	y=(k+n-1)/n;
	if (s>0&&s<=n) {
		x=s;
	}
	else if (s==0) {
		x=1;
	}
	else {
		x=(2*n)-s+1;
	}
	printf ("%d %d", y, x);
	return 0;
}
