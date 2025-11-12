#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxm = 2e5 + 10;
map<pair<string,string>,int> mp;
int n,q;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		string s1,s2;cin >> s1 >> s2;
		mp[{s1,s2}] = i;
	}
	while(q--)
	{
		string l1,l2;cin >> l1 >> l2;
		if(l1.size() != l2.size())cout << "0\n";
		else
		{
			int cnt = 0;
			for(int i = 0;i < l1.size();i++)
			{
				string y1 = "",y2 = "";
				for(int j = i;j < l1.size();j++)y1.push_back(l1[j]),y2.push_back(l2[j]);
				for(int j = l1.size() - 1;j >= i;j--)
				{
					if(mp.count({y1,y2}))cnt++;
					y1.pop_back();y2.pop_back();
					if(l1[j] != l2[j])break;
				}
				if(l1[i] != l2[i])break;
			}
			cout << cnt << '\n';
		}
	}
	return 0;
}
