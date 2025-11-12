#include <bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005],s3,s4;
int n,q,ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout .tie(0);
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1;i <= q;i++)
	{
		cin >> s3 >> s4;
		ans = 0;
		for (int j = 1;j <= n;j++)
		{
			string res = "";
			int x = s3.find(s1[j]);
//			if (x)
//			{
//				continue;
//			}
			for (int k = 0;k < x;k++)
			{
				res = res + s3[k];
			}
			res = res + s2[j];
			for (int k = x + s1[j].size();k < s3.size();k++)
			{
				res = res + s3[k];
			}
			if (res == s4)
			{
				ans++;
//				cout << j << ' ';
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
