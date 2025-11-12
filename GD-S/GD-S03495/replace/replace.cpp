#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

int n, q; string s1[MAXN], s2[MAXN]; unordered_map <string, vector <string> > ump;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; i ++)
	{
		cin >> s1[i] >> s2[i]; ump[s1[i]].push_back(s2[i]);
	}
	
	while (q --)
	{
		string t1, t2;
		
		cin >> t1 >> t2;
		
		int ans = 0;
		
		for (auto tmp : ump)
		{
			string a = tmp.first; auto p = tmp.second;
			
			for (int i = 0; i < t1.length(); i ++)
			{
				bool flag = true;
				
				for (int j = 0; j < a.length(); j ++)
				{
					if (t1[i + j] != a[j])
					{
						flag = false; break;
					}
				}
				
				if (flag == true)
				{
					for (string str : p)
					{
						if (t1.substr(0, i) + str + t1.substr(i + a.length()) == t2) ans ++;
					}
				}
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}
