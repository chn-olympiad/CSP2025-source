#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n;
int a[10010];
int ans = 0;
vector<int> v[5010][5010];
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	int maxn = -1e9;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		maxn = max(a[i], maxn);
	}
	if(n <= 3) {
		if(n <= 2) cout << 0 << '\n';
		else if(a[1] + a[2] + a[3] > maxn * 2) cout << 1 << '\n';
	}
	// 每个数都是1
	else if(maxn == 1) {
		int tmp = 0;
		// n 选 i
		for(int i=3; i<=n; i++) {
			long long sum = 1;
			for(int j=n; j>i; j--) {
				sum *= j;
				sum %= mod;
//				cout << sum << "\n";
			}
			for(int j=1; j<=(n - i); j++) {
				sum /= j;
				sum %= mod;
//				cout << sum << "\n";
			}
//			cout << sum << '\n';
			tmp += sum;
			tmp %= mod;
//			cout << "tmp:" << tmp << '\n';
		}
		cout << tmp << '\n';
	}
	return 0;
}
/*
5
1 1 1 1 1

*/
