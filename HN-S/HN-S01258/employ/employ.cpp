#include <bits/stdc++.h>
using namespace std;
int n , m , a[505] , cnt;
char c[505];
int main(){
	freopen ("employ.in" , "r" , stdin);
	freopen ("employ.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> c[i];
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		if (a[i] == 0) cnt ++;
	}
	if (n - cnt < m) cout << 0;
	else{
		long long ans = 1;
		for (int i = n; i >= 1; i --){
			ans *= i;
			ans %= 998244353;
			cout << ans << " ";
		}
		cout << ans;
	}
	return 0;
}
