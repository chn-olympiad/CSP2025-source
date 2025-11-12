#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int i, j, k, l, n, m, y, z, s;
char a[N], b[N], x;
struct AB {
	int x, y, z;
}c[N];
int main (){
	freopen ("replace4.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	scanf ("%d %d", &n, &m);
	for (i=1; i<=n; i++) {
		scanf ("%s%s", a+1, b+1);
		for (j=1; a[j]; j++);
		j--;
		if (i==1) {
			if (a[1]!=a[2]&&a[1]!=a[3]) x=a[1];
			else if (a[n]!=a[n-1]&&a[n]!=a[n-2]) x=a[n];
			else {
				for (k=2; k<j; k++) {
					if (a[j]!=a[j-1]&&a[j]!=a[j+1]) x=a[j];
				}
			}
		}
		for (k=1; k<=j; k++) {
			if (a[k]==x) break;
		}
		for (l=1; l<=j; l++) {
			if (b[l]==x) break;
		}
		c[i].x=max (k, l);
		c[i].y=max (n-k, n-l);
		c[i].z=k-l;
	}
	for (i=1; i<=m; i++) {
		s=0;
		scanf ("%s %s", a+1, b+1);
		for (j=1; a[j]; j++);
		j--;
		for (k=1; b[k]; k++);
		k--;
		if (j!=k) {
			printf ("0\n");
			continue;
		}
		for (j=1; j<=k; j++) {
			if (a[j]==x) y=j;
			if (b[j]==x) z=j;
		}
		for (j=1; j<=n; j++) {
			if (y<c[j].x) continue;
			if (k-y<c[j].y) continue;
			if (y+c[j].z==z) s++;
		}
		printf ("%d\n", s);
	}
	return 0;
}

