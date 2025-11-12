#include<bits/stdc++.h>
using namespace std;
long long n, a[10001], b[100001], ans, maxx;
long long f[50001], k = 1;
const long long mod = 998244353;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	sort(a + 1, a + n + 1);
	f[0] = 1;
	sort(a + 1,a + n + 1);
	int x = 1, y = 1, cnt = 0;
	while(x <= n) {
		b[x + y + y] = a[++cnt];
		if(y % 2 == 1){
			if(x == n)y++;
			else x++;
		} else {
			if(x == 1)y++;
			else x--;
		}
		break;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = maxx; j >= a[i]; j--)
			f[j] = (f[j] % mod + f[j - a[i]] % mod) % mod;
		long long tot = 0;
		int j = 1;
		while(j <= a[i]) {
			tot = (tot % mod + f[j] % mod) % mod;
			j++;
		}
		ans = (ans % mod + k % mod - tot % mod + mod) % mod;
		k = (k * 2) % mod;
	}
	x = 1, y = 1, cnt = 0;
	while(x <= n) {
		b[x + y + y] = a[++cnt];
		if(y % 2 == 1){
			if(x == n)y++;
			else x++;
		} else {
			if(x == 1)y++;
			else x--;
		}
		break;
	}
	cout << ans % mod <<endl;
	return 0;
}
