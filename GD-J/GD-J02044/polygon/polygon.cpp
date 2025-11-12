#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 998244353
#define maxx(a,b) ((a >= b) ? a : b)
unsigned int n,f[5001][5001],ans;
int a[5001];
int main() {
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i) { cin >> a[i]; }
	sort(a + 1,a + n + 1);
	f[0][0] = 1;
	//j = 0
	for(int i = 1;i <= n;++i) {
		f[i][0] = (f[i - 1][0] << 1) % MOD;
	}
	for(int i = 1;i < n;++i) {
		for(int j = 1;j <= a[n];++j) {
			if(j <= a[i]) {
				f[i][j] = f[i - 1][0];
			} else {
				f[i][j] = (f[i - 1][j] + f[i - 1][j - a[i]]) % MOD;
			}
		}
	}
	for(int i = 3;i <= n;++i) {
		ans = (ans + f[i - 1][a[i]]) % MOD;
	}
	cout << ans;
}

