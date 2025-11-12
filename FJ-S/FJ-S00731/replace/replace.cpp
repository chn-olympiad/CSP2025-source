#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, q;
string s[N][2], t[2];
int x[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i][0] >> s[i][1];
		x[i] = s[i][0].length();
	}
	while (q--)
	{
		long long ans = 0, num = 0;
		cin >> t[0] >> t[1];
		if (t[0].length() != t[1].length())
		{
			cout << 0 << endl;
			continue;
		}
		for (int i = 0;i < t[0].length();i++)
		{
			if (t[0][i] == t[1][i])
			{
				num++;
			}
		}
		for (int i = 0;i < t[0].length();i++)
		{
			int cnt = 0;
			for (int j = 1;j <= n;j++)
			{
				bool o = true;
				if (x[j] + num < t[0].length())
				{
					break;
				}
				for (int k = 0;k < x[j];k++)
				{
					if (s[j][0][k] != t[0][i+k] || s[j][1][k] != t[1][i+k])
					{
						o = false;
						break;
					}
				}
				if (o)
				{
					cnt++;
				}
			}
			ans += cnt;
		}
		cout << ans << endl;
	}
	return 0;
}
