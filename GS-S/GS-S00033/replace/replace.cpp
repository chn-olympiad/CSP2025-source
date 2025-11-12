#include <bits/stdc++.h>
using namespace std;
struct X
{
	string s1 , s2;
}a[200005] , b;
int main()
{
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	int n , q;
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
		cin >> a[i].s1 >> a[i].s2;
	for (int i = 1;i <= q;i++)
	{
		int ans = 0;
		cin >> b.s1 >> b.s2;
		for (int j = 0;j < b.s1.length();j++)
		{
			for (int k = j;k < b.s1.length();k++)
			{
				string s = b.s1.substr(j , k - j + 1);
				for (int p = 1;p <= n;p++)
				{
					if (a[p].s1 == s)
					{
						string t = b.s1;
						for (int p2 = 0;p2 < s.length();p2++)
							t[p2 + j] = a[p].s2[p2];
						if (t == b.s2)
							ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
