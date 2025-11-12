#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m;
long long ans;
int c[505];
string s;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i ++)
	{
		cin >> c[i];
	}
	sort(c + 1, c + m + 1);
	for(int i = 1; i <= n; i ++)
	{
		if(c[i] > i - 1)
		{
			if(n - i + 1 < m)
			{
				cout << 0 << "\n";
				break;
			}
			ans = 1;
			for(long long j = 1; j <= n - i + 1; j ++)
			{
				ans *= j;
				ans %= MOD;
			}
			cout << ans << "\n";
			break;
		}
	}
	return 0;
}
//ÃÜÂë£ºRen5Jie4Di4Ling5%
