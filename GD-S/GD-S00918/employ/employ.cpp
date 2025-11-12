#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , m , f[20] , a[20] , b[20] , ans;
string s;
void dfs (int id) {
	if (id == n + 1) {
		int num = 0;
		for (int i = 1;i <= n;i ++) {
			if (b[a[i]] <= num) {
				num ++;
			}
			else if (s[i] == '0') num ++;
		}
		if (n - num >= m) ans ++;
		return;
	}
	for (int i = 1;i <= n;i ++) {
		if ( !f[i] ) {
			f[i] = 1;
			a[id] = i; 
			dfs (id + 1);
			f[i] = 0;
		}
	}
}
signed main () {
	freopen ("employ.in" , "r" , stdin);
	freopen ("employ.out" , "w" , stdout); 
	ios::sync_with_stdio (0);
	cin.tie (0); cout.tie (0);
	cin >> n >> m >> s; s = ' ' + s;
	for (int i = 1;i <= n;i ++) cin >> b[i];
	if (m == n) {
		int flag = 0;
		for (int i = 1;i <= n;i ++) {
			if (s[i] == '0' || b[i] == 0) {
				flag = 1;
				break;
			}
		}
		if ( flag ) {
			cout << 0;
		}
		else {
			int ans = 1;
			for (int i = 1;i <= n;i ++) {
				ans = (ans * i) % 998244353;
			}
			cout << ans;
		}
		return 0;
	}
	dfs (1);
	cout << ans;
	
	return 0;
} 
