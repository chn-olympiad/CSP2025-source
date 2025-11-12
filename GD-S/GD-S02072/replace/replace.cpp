#include <bits/stdc++.h>
using namespace std;
string s1[200001], s2[100001];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i<=n; i++)
	{
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1; i<=q; i++)
	{
		string t1, t2;
		cin >> t1 >> t2;
		if(t1.size()!=t2.size())
		{
			cout << 0 << '\n';
		}
		else
		{
			int ans = 0;
			for(int j = 1; j<=n; j++)
			{
				if(t1.size()<s1[j].size())
				{
					continue;
				}
				for(int k = 0; k<=t1.size()-s1[j].size(); k++)
				{
					if(t1.substr(k, s1[j].size())==s1[j] && t1.substr(0, k)+s2[j]+(k==t1.size()-s1[j].size() ? "" : t1.substr(k+s1[j].size()))==t2)
					{
						ans++;
					}
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
