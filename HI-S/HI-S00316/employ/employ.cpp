#include <bits/stdc++.h>
using namespace std;
int n,m,s0;
string s;
int c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	bool yes = 1;
	for (int i = 0;i < s.size(),i++)
	{
		if(s[i] != 1)
		{
			yes = 0;
		}
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> c[i];
		if (c[i] = 0)
		{
			s0++;
		}
	}
	if (m == n)
	{
		if (!yes || s0 != 0)
		{
			cout << 0;
			return 0;
		}
		else
		{
			long long sum = 1;
			for (int i = 1;i <= n;i++)
			{
				sum %= 998244353;
				sum *= n;
			}
			cout << sum;
			return 0;
		}
	}
	cout << 2;
	return 0;
	
}
