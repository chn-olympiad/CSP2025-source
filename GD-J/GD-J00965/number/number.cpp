#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int i, n, m, a[N];
char s[N];
int main (){
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	scanf ("%s", s+1);
	for (n=1; s[n]; n++);
	n--;
	for (i=1; i<=n; i++) {
		if (s[i]>='0'&&s[i]<='9') a[++m]=s[i]-'0';
	}
	sort (a+1, a+m+1);
	for (i=m; i>=1; i--) {
		printf ("%d", a[i]);
	}
	return 0;
}
