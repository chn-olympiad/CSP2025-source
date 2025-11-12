#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, q;
string s[N][2];
string x, y;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i][0] >> s[i][1];
	}
	
	while (q--)
	{
		cin >> x >> y;
		
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			string xx = x;			
			int f = 0;
			for (int j = (int)s[i][0].size() - 1; j < (int)x.size(); ++j)
			{
				xx = x; f = 0;
				for (int k = j - s[i][0].size() + 1, d = 0; k <= j; ++k, ++d)
					if (x[k] != s[i][0][d])
					{
						f = 1;
						break;
					}
				if (!f) 
				{
					xx.erase(j - s[i][0].size() + 1, s[i][0].size());
					xx.insert(j - s[i][0].size() + 1, s[i][1]);
					if (xx == y) ans++;
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
