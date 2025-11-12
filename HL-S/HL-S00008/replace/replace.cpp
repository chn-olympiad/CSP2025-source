#include <bits/stdc++.h>
using namespace std;
int n,q;
struct S
{
	string s1,s2;
}s[200005];
bool f = 1;
string t1,t2;
/*struct L
{
	int i1,i2;
}
*/
vector<int> v[26];
int l,r;
int ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> s[i].s1 >> s[i].s2;
		v[s[i].s1[0] - 'a' + 1].push_back(i);
	}
	for(int i = 1;i <= q;i++)
	{
		cin >> t1 >> t2;
		if(!v[t1[l]-'a'+1].empty())
		{
			//r++;
			for(int j = 0;j < v[t1[l]-'a'+1].size();j++)
			{
				for(int k = 0;k <= s[j].s1.size();k++)
				{
					if(s[j].s1[k] != t1[l+k] || s[j].s2[k] != t2[l+k])
					{
						f = 0;
					}
				}
				if(f)
				{
					ans++;
				}
			}
			l++;
		}
		else
		{
			continue;
		}
		cout << ans << endl;
	}
	return 0;
}
//111
/*4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb*/
