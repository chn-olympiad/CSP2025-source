#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 5010, mod = 998244353;
ll n, l[N], ans = 0, m, res = 1, c = 1;
bool flag = 1;

int main() {
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> l[i];
		if(l[i] != 1) flag = 0;
	}
	
	if(flag) {
		for(int i = 3; i <= n; i++) {
			m = n;
			res = c = 1;
			for(int j = 1; j <= i; j++) {
				res *= m;
				m--;
				c *= j;
			}
			res /= c;
			//cout << res << ' ' << c << endl;
			ans = (ans + res) % mod;
		}
		cout << ans % mod;
	}
	
	return 0;
} 

