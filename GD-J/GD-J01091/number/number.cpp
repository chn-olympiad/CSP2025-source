#include<bits/stdc++.h>
using namespace std;
#define N 1000050
int n, m, i, j, k, s[15];
char a[N];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", a+1);
	for (n=strlen(a+1), i=1; i<=n; i++) {
		if (a[i] >= '0' && a[i] <= '9') s[a[i]-'0']++;
	}
	for (i=9; i>=0; i--) {
		for (j=1; j<=s[i]; j++) printf("%d", i);
	}
	return 0;
} 
