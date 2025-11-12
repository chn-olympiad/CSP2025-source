#include <bits/stdc++.h>
using namespace std;
int n,q;
string sa[200010], sb[200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1; i<=n; i++)
	{
		string s1,s2;
		cin >> s1 >> s2;
		sa[i] = s1;
		sb[i] = s2;
	}
	while(q--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if(s1.size() != s2.size())
		{
			cout << 0 << endl;
			continue;
		}
		int len = s1.size();
		int cnt = 0;
		
		for(int i=0; i<len; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(i+sa[j].size() > len) continue;
				int l2 = sa[j].size();
				if(s1.substr(i,l2) != sa[j] || s2.substr(i,l2) != sb[j]) continue;
				if(i+l2 < len && s1.substr(i+l2) != s2.substr(i+l2)) continue;
				cnt++;
			}
			if(s1[i] != s2[i]) break;
		}
		cout << cnt << endl;
	}
	return 0;
}
