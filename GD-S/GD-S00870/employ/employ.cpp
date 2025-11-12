#include <bits/stdc++.h>
using namespace std;
int i, j, k, a[505], b[505], n, m;
char s[505];
long long ss, mo=998244353, x, y, z;
int main (){
//	freopen ("employ.in", "r", stdin);
//	freopen ("employ.out", "w", stdout);
	scanf ("%d %d", &n, &m);
	scanf ("%s", s+1);
	for (i=1; i<=n; i++) {
		a[i]=s[i]-'0';
	}
	for (i=1; i<=n; i++) {
		scanf ("%d", &b[i]);
		k+=b[i]>0;
	}
	if (m==1) {
		y=0;
		x=1;
		ss=1;
		for (i=1; i<n; i++) {
			ss*=i;
			ss=ss%mo;
		}
		ss*=k;
		ss=ss%mo;
		for (i=1; i<=n; i++) {
			if (a[i]>0) {
				for (j=1; j<=n; j++) {
					if (b[j]>=i) y++;
				}				
				ss+=x*(n-k)*y;
				ss%=mo;
			}
		}
		printf ("%lld", ss);
	}
	else printf ("0");
	return 0;
}

