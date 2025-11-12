#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,q;
string s1[200005],s2[200005];
string t1,t2;
int len1,len2;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> s1[i] >> s2[i];
	}
	while(q--)
	{
		cin >> t1 >> t2;
		len1 = t1.size();
		len2 = t2.size();
		t1 = " " + t1;
		t2 = " " + t2;
		int ans = 0;
		for(int i = 1;i <= len1;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(i < s1[j].size())continue;
				if(t1.substr(i-s1[j].size()+1,s1[j].size()) == s1[j])
				{
					string tmp = t1;
					for(int k = i-s1[j].size()+1;k <= i;k++)
					{
						tmp[k] = s2[j][k-s1[j].size()+1];
					}
					if(tmp == t2)
					{
						ans++;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

