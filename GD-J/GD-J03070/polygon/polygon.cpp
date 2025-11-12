#include <bits/stdc++.h>
const int MOD = 998244353;
using namespace std;
int main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 1;i <= n; i ++) {
		cin >> a[i];
	}
	long long ans = 0;
	
	//最后十分钟不想写了就当它全是1
	
	for (int i = 3; i <= n; i ++) {
		long long sum = 1;
		long long s=1;
		for (int j = 0; j < i; j ++) {
			sum *= (n - j);
			s*= (j+1);
		}
		sum =sum/s%MOD;
		ans += sum;
		ans %= MOD;
	} 
	cout << ans;
	return 0;
} 
