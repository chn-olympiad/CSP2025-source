#include<bits/stdc++.h>

using namespace std;

const int maxn = 5e3 + 7;

int n;
int a[maxn];
long long c[maxn];
long long md = 998244353;
long long ans = 0;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	int M = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		M = max(M, a[i]);
	}
	
	if(M == 1) {
		c[3] = n * (n - 1) * (n - 2) / 6;
		ans = c[3] % md;
		for(int i = 4; i <= n; i ++) {
			c[i] = c[i - 1] / i * (n - (i - 1));
			ans = ans + c[i], ans = ans % md;
		}
		cout << ans % md << '\n';
	}
	return 0;	
} 
/*

*/
