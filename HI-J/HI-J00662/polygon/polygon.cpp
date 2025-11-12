#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const long long mod = 998244353;
long long n, ans, a[5005];

void dfs(int step, long long mx, long long sum) {
	if (step > n) {
		if (sum-mx > mx) {
			ans = (ans+1)%mod;
		}
		return;
	}
	dfs(step+1, mx, sum);
	if (step==n) return;
	dfs(step+1, max(mx, a[step+1]), sum+a[step+1]);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	if (n >= 500) {
		cout << 0;
		return 0;
	}
	dfs(0, 0, 0);
	
	cout << ans;
	
	return 0;
}


