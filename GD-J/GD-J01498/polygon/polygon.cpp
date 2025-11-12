#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int l[5010]; 
long long f[5010][3];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &l[i]);
	sort(l+1, l+1+n);
	for(int i = 1; i <= n; i++) {
		ans = (ans + f[l[i]][2]) % mod;
		for(int j = l[n]; j >= 0; j--) {
			if(j >= l[i]) f[j][2] = (f[j][2] + f[j - l[i]][2] + f[j - l[i]][1]) % mod;
			if(j < l[i]) f[j][2] = (f[j][2] + f[0][2] + f[0][1]) % mod, f[j][1] += 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
