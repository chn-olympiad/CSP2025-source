#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n, m, a[1001], s[1001]; string s1;
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> s1; int sum = 0;
	for (int i = 1; i <= n; i++){cin >> a[i]; s[i] = s[i - 1] - '0';}
	for (int i = 1; i <= n; i++) sum += s[i];
	if (sum <= m){cout << "0\n"; return 0;}
	/*if (m == 1){
		
	}
	else if (m == n){
		
	}
	else{*/
		long long ans = 1;
		for (int i = 1; i <= n; i++) ans = ans * i % mod;
		cout << ans << '\n';
	//}
	return 0;
}
//24+pts
