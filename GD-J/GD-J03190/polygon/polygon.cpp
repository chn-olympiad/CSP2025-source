#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
long long ksm(long long x, long long y){
	long long ans = 1;
	while (y > 0){
		if (y % 2 == 1){
			ans *= x;
			ans %= mod;
		}
		x *= x;
		x %= mod;
		y /= 2;
	}
	return ans;
}
int a[5100];
int f[2][10100][4][2];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int v = a[n] * 2;
	for (int i = 0; i <= v; i++){
		f[0][i][0][0] = 1;
	}
	long long ans = ((ksm(2, n) - n * (n - 1) / 2 - n - 1) % mod + mod) % mod;
//	cout << ans << '\n';
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= v; j++){
			for (int k = 0; k <= 3; k++){
				f[i & 1][j][k][0] = f[i & 1][j][k][1] = 0;
				if (k == 0){
					f[i & 1][j][k][0] = 1;
				}
				else{
					f[i & 1][j][k][0] = (f[(i & 1) ^ 1][j][k][0] + f[(i & 1) ^ 1][j][k][1]) % mod;
					if (j < a[i]){
						continue;
					}
					f[i & 1][j][k][1] = (f[(i & 1) ^ 1][j - a[i]][k - 1][0] + f[(i & 1) ^ 1][j - a[i]][k - 1][1]) % mod;
					if (k == 3){
						f[i & 1][j][k][1] += (f[(i & 1) ^ 1][j - a[i]][k][0] + f[(i & 1) ^ 1][j - a[i]][k][1]) % mod;
						f[i & 1][j][k][1] %= mod;
					}
				}
			}
		}
		ans -= f[i & 1][2 * a[i]][3][1];
		ans = (ans + mod) % mod;
//		cout << ans << '\n';
	}
	cout << ans << '\n';
	return 0;
} 
