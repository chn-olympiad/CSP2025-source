#include <bits/stdc++.h>
using namespace std;

namespace ljw
{
	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		
		freopen("employ.in", "r", stdin);
		freopen("employ.out", "w", stdout);
		
		int n, m;
		cin >> n >> m;
		
		long long res = 1, mod = 998244353;
		for (int i = 1; i <= m; i++)
			res = res * i % mod;
			
		cout << res;
		
		
		return 0;
	}
}

int main()
{
	return ljw::main();
}
