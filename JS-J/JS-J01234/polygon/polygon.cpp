#include<bits/stdc++.h>
using namespace std;
int jiecheng(int x) {
	int ans = 1;
	for(int i = 1; i <= x; ++i) ans = ans * i;
	return ans;
}
int main() {
	freopen("polyon.in", "r", stdin);
	freopen("polyon.out", "w", stdout);
	int n, ans = 0, a[5009];
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	if(n == 3) {
		sort(a + 1, a + 1 + n);
		a[1] + a[2] > a[3] ? cout << 1 : cout << 0;
	}
	else {
		int nn = jiecheng(n);
		for(int i = 3; i <= n; ++i) ans += (nn / (jiecheng(i) * jiecheng(n - i)));
		cout << ans;
	}
	return 0;
}
