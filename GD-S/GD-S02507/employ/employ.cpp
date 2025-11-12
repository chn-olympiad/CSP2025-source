#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
char s[505];
int c[505],a[25];
long long mod = 998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{	
		char c;
		cin >> c;
		s[i] = (int)(c - '0');
	}
	for (int i = 1;i <= n;i++)
		cin >> c[i];
	for (int i = 1;i <= n;i++)
	{
		if (s[i] == 1 && c[i] != 0)
			cnt++;
		//cout << s[i] << " " << c[i] << " " << cnt << endl;
	}
	if (m > cnt)
	{
		cout << 0;
		return 0;
	}
	else
	{
		if (m == n)
		{
			long long ans = 1;
			for (int i = 1;i <= n;i++)
				ans = ans * i % mod;
			cout << ans;
			return 0;
		}
		else
		{
			int ans = 0;
			for (int i = 1;i <= n;i++)
			{
				a[i] = i;
			}
			do
			{
				int cntt = 0,fang = 0;
				for (int i = 1;i <= n;i++)
				{
					if (s[i] == 0 || fang >= c[a[i]])
						fang++;
					else
						cntt++;
				}
				if (cntt >= m)
					ans = (ans + 1) % mod;
				//cout << cntt << endl;
			} while(next_permutation(a + 1,a + n + 1));
			cout << ans;
			return 0;
		}
	}
}
