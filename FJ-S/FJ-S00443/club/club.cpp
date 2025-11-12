#include <bits/stdc++.h>

using namespace std;

int t, n, res[5];
int a[114514][4]; 
int c[114514][2], c1, c2, c3;

int club () {
	c1=0; c2=0; c3=0;
	int myd=0;
	for (int i=1; i<=n; i++) {
		if (a[i][1]>=a[i][2] && a[i][1]>=a[i][3]) {
			c[i][0] = 1; c1++;
			c[i][1] = a[i][1];
		}
		if (a[i][2]>=a[i][1] && a[i][2]>=a[i][3]) {
			c[i][0] = 2; c2++;
			c[i][1] = a[i][2];
		}
		if (a[i][3]>=a[i][2] && a[i][3]>=a[i][1]) {
			c[i][0] = 3; c3++;
			c[i][1] = a[i][3]; 
		}
	}
	if (c1>n/2 || c2>n/2 || c3>n/2) {
		
	}
	for (int i=1; i<=n; i++) myd += c[i][1];
	return myd;
}

int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	memset (res, 0, sizeof(res));
	
	scanf ("%d", &t);
	for (int i=0; i<t; i++) {
		memset (a, 0, sizeof(a)); 
		memset (c, 0, sizeof(c));
		scanf("%d", &n);
		for (int j=1; j<=n; j++) {
			scanf("%d%d%d", &a[j][1], &a[j][2], &a[j][3]);
		}
		res[i] = club();
	}
	
	for (int i=0; i<t; i++) printf("%d", res[i]);
	
	return 0;
}