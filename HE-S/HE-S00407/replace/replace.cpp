#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n,q;
string s1[N],s2[N];
string t1,t2;
void solve()
{
	cin >> n >> q;
	for(int i = 1;i <= n;++i)
	{
		cin >> s1[i] >> s2[i];
	}
	while(q--)
	{
		cin >> t1 >> t2;
		int ans = 0;
		for(int k = 1;k <= n;++k)
		{
			int j = 0,cnt = 0;
			bool flag = 0;
			for(int i = 0;i < t1.length();++i)
			{
				
				if(t1[i] == s1[k][j]) ++j;
				else j = 0;
				if(j == s1[k].length())
				{
					flag = 1;
					j = i;
					break;
				}
			}
			if(flag == 0) continue;
			string t = t1;
			for(int i = j,p = s2[k].length() - 1;i >= j + 1 - s1[k].length(),p >= 0;--i,--p) t1[i] = s2[k][p];
			if(t1 == t2) ++ans;
			t1 = t;
		}
		cout << ans << '\n';
	}
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	solve();
	return 0;
}

