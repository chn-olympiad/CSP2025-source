#include<bits/stdc++.h>
using namespace std;
pair<string, string> s[200005]; 
map<char, vector<int> > mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n, q, i, j, ans;
	string a, b;
	cin >> n >> q;
	for(i = 1; i <= n; i++)
	{
		cin >> s[i].first >> s[i].second;
		mp[s[i].first[0]].push_back(i);
	}
	while(q--)
	{
		cin >> a >> b;
		if(a.size() != b.size())
		{
			cout << "0\n";
			continue;
		}
		ans = 0;
		for(i = 0; i < a.size(); i++)
		{
			if(mp[a[i]].size())
			{
				for(j = 0; j < mp[a[i]].size(); j++)
				{
					if(s[mp[a[i]][j]].first.size() >= mp[a[i]].size() - j && a.substr(i, s[mp[a[i]][j]].first.size()) == s[mp[a[i]][j]].first)
					{
						if(b.substr(i, s[mp[a[i]][j]].first.size()) == s[mp[a[i]][j]].second)
							if(a.substr(i + s[mp[a[i]][j]].first.size() - 1) == b.substr(i + s[mp[a[i]][j]].first.size() - 1))
								ans++;
					}
				}
			}
			else if(a[i] != b[i])
				break;
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/
 // 什么意思啊 -ST3出个AC自动机板子题 
