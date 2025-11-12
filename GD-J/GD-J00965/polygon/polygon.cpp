#include <bits/stdc++.h>
using namespace std;
#define N 5005
#define M 998244353
int i, j, k, a[N], n;
long long s, c[N+5][N+5];
int main (){
	freopen ("polygon", "r", stdin);
	freopen ("polygon", "w", stdout);
	scanf ("%d", &n);
	for (i=0; i<=N; i++) {
		c[0][i]=1;
	}
	for (i=1; i<=N; i++) {
		for (j=i; j<=N; j++) {
			c[i][j]=c[i-1][j-1]+c[i][j-1];
		}
	}
	for (k=i=1; i<=n; i++) {
		scanf ("%d", &a[i]);
		if (a[i]>a[k]) k=i;
	}
	if (k==1) {
		for (i=3; i<=n; i++) {
			s+=c[i][n];
			s%=M;
		}
		printf ("%lld", s);
	}
	else if (n<=3) {
		if (n<3) printf ("0");
		else {
			sort (a+1, a+n+1);
			if (a[1]+a[2]>a[3]) printf ("1");
			else printf ("0");			
		}
	}
	else {
		
	}
	return 0;
}

