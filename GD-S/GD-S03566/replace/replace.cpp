#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, q;
string s[maxn], t[maxn];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i] >> t[i];
	}
	while(q--)
	{
		string a, b;
		cin >> a >> b;
		int ans = 0;
		for(int i = 0; i < a.size(); i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i + s[j].size() < a.size() && a.substr(i, s[j].size()) == s[j])
				{
					bool flag = 0;
					for(int k = 0; k < b.size(); k++)
					{
						if(k < i)
						{
							if(b[k] != a[j])
							{
								flag = 1;
								break;
							}
						}
						if(i <= k && k <= i + s[j].size() - 1)
						{
							if(b[k] != t[j][k - i])
							{
								flag = 1;
								break;
							}
						}
					}
					if(!flag) ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
