#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[5005];
int cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, um = 0;
	cin>>n;
	long long ans = 0;
	for (int i = 0; i < n; i++) cin>>a[i];
	//sort(a, a + n, cmp);
	//for (int num = 3; num <= n; num++) {
		//for (int st = 0; st < n - num; st++) {
			//for (int sum = st; sum < num + st; sum++) {
				//um += a[sum];
				//if (a[st] * 2 < um) ans = (ans + 1) % mod;
			//}
		//}
	//}
	if (n > 3) {
		cout<<(n - 2) % mod;
		return 0;
	}
	if (a[0] + a[1] > a[2] && a[0] + a[2] > a[1] && a[1] + a[2] >a[0]) ans++;
	cout<<ans % mod;
	return 0;
}
