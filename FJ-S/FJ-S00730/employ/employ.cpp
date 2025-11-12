#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e2 + 10, mod = 998244353;
int n, p[N], q[N], m, ans;
string can;
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> can;
	bool flag = 1;
	for(int i = 0; i < n; i ++ )
		if(can[i] == '0')
			flag = 0;
	int now = 0;
	for(int i = 1; i <= n; i ++ )
		cin >> p[i], q[i] = i, now += (p[i] == 0);
	if(n <= 10)
	{
		do
		{
			int cnt = 0, now = 0;
			for(int i = 1; i <= n; i ++ )
			{
				if(can[i - 1] == '0')
				{
					cnt ++ ;
					continue;
				}
				else
				{
					if(cnt >= p[q[i]])
					{
						cnt ++ ;
						continue;
					}
					now ++ ;
				}
			}
			if(now >= m)
				ans ++ ;
		}while(next_permutation(q + 1, q + n + 1));
		cout << ans <<endl;
	}
	else
	{
		int ans = 1ll;
		for(int i = 1; i <= n; i ++ )
			ans = ans * i % mod;
		cout << ans << endl;
	}
	return 0;
}
