#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define N 5050
int n, m, i, j, k, f[N], a[N], ans;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (i=1; i<=n; i++) scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	for (f[0]=i=1; i<=n; i++) {
		for (j=a[i]+1; j<=5001; j++) ans = (ans+f[j])%mod; 
		for (j=5001; j>=0; j--) {
			k = min(5001, j+a[i]);
			f[k] = (f[k]+f[j])%mod;
		}
	}
	printf("%d", ans);
	return 0;
}

