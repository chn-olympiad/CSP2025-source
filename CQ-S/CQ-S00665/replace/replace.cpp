#include <bits/stdc++.h>
using namespace std;
int n,q,sum;
string s[1005][5],t[1005][5];
void maxn(string a,string b)
{
	for (int i = 1; i <= n; i++)
	{
		string c;
		int m;
		for (int j = 0; j < len(a); j ++)
		{
			if (a[j] != s[i][1][0]) c += a[j];
			else if (a[j] == s[i][0])
			{
				bool f = true;
				for (int z = 1;z < len(a); z++)
				{
					if (s[i][1][z] != a[z])
					{
						f = false;
						return;
					}
				}
				if (f) c += s[i][2];
			}
			if (c == b) m++;
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 2; j++)
			cin >> s[i][j];
	}
	for (int i = 1; i <= q; i++)
	{
		for (int j = 1; j <= 2; j++)
			cin >> t[i][j];
	}
	for (int i = 1; i <= q; i++)
	{
		sum += maxn(t[i][1],t[i][2]);
	}
	cout << sum << endl;
	return 0;
}
