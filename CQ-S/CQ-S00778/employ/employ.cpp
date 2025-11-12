#include <bits/stdc++.h>
#define int long long

using namespace std;

namespace aaaaaa{
	const int N = 1005;
	const int p = 998244353;
	
	int n, m;
	string s;
	int c[N];
	
	signed main() {
		freopen("employ.in", "r", stdin);
		freopen("employ.out", "w", stdout);
		
		cin >> n >> m >> s;
		for (int i = 1; i <= n; ++ i)
			cin >> c[i];
		
		int cnt = 0;
		for (int i = 1; i <= n; ++ i)
			if (c[i])
				cnt ++;
		
		cout << cnt << '\n';
		
		int sum = 1;
		for (int i = 1; i <= cnt; ++ i) {
			sum *= i;
			sum %= p;
		}
		
		int sum1 = 1;
		for (int i = 1; i <= n - cnt; ++ i) {
			sum1 *= i;
			sum1 %= p;
		}
		
		cout << (sum * sum1) % p;
		
		return 0;
	}
}

signed main() {
	aaaaaa::main();
	
	return 0;
}
