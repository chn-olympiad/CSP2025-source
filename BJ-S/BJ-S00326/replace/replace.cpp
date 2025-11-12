#include <bits/stdc++.h>
using namespace std;

int n,q;
string s[200005][2];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i][0] >> s[i][1];
		s[i][0] = " "+s[i][0];
		s[i][1] = " "+s[i][1];
	}
	while (q--)
	{
		string a,b;
		cin >> a >> b;
		a = " "+a,b = " "+b;
		if (a.size() != b.size() || n >= 1000)
		{
			cout << "0\n";
			continue;
		}
		int ans = 0;
		for (int i = 1;i <= n;i++)
		{
			for (int l = 1;l+s[i][0].size()-2 < a.size();l++)
			{
				int r = l+s[i][0].size()-2;
				int f = 0;
				for (int x = 1;x < l;x++)
				{
					if (a[x] != b[x]) f = 1;
				}
				if (f == 1) break;
				for (int x = l,y = 1;x <= r;x++,y++)
				{
					if (a[x] != s[i][0][y] || b[x] != s[i][1][y]) f = 1;
				}
				if (f == 1) continue;
				for (int x = r+1;x < (int)a.size();x++)
				{
					if (a[x] != b[x]) f = 1;
				}
				if (f == 1) continue;
				ans++;
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}
