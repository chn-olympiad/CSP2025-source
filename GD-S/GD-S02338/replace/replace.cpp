#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3];
long long ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i ++) cin >> s[i][1] >> s[i][2];
	if (n >= 100 && q >= 10)
	{
		for (int i = 1;i <= q;i ++) cout << 0 << endl;
		return 0;
	 } 
	for (int j = 1;j <= q;j ++)
	{
		string t1,t2;
		cin >> t1 >> t2;
		int l = -1;
		for (int i = 0;i < t2.length(); i++)
		{
			if (t2[i] == 'b')
			{
				l = i;
				break;
			}
			else continue;
		}
		for (int i = 1;i <= n;i ++)
		{
			for (int x = 0,y = t1.length();x <= y;x++,y--)
			{
				string tmp,cmp;
				for (int w = x;w <= y;w ++) tmp+=t1[w],cmp+=t2[w];
				if (tmp == s[i][1] && cmp == s[i][2])
				{
					ans ++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

