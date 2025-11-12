#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
string s[MAXN][2], t[2];
int sum[MAXN]; 
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q, ans = 0;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++)
	{
		cin >> s[i][0] >> s[i][1];
	}
	for(int i = 1; i <= q; i ++)
	{
		ans = 0;
		cin >> t[0] >> t[1];
		int len1 = (int)(t[0].size());
		int len2 = (int)(t[1].size());
		t[0] = " " + t[0], t[1] = " " + t[1];
		if(len1 != len2)
		{
			cout << 0 << endl;
			continue;
		}
		for(int j = 1; j <= len1; j ++)
		{
			sum[j] = sum[j - 1];
			if(t[0][j] != t[1][j]) sum[j] ++;
		}
		for(int j = 1; j <= n; j ++)
		{
			for(int l = 1; l <= len1 - (int)(s[j][0].size()) + 1; l ++)
			{
				int r = l + (int)(s[j][0].size()) - 1;
				if(sum[l - 1] != 0 || sum[n] - sum[r] != 0) continue;
				bool flag = true;
				for(int o = 0; o < (int)(s[j][0].size()); o ++)
				{
					if(s[j][0][o] != t[0][l + o] || s[j][1][o] != t[1][l + o])
					{
						flag = false;
						break;
					}
				}
				if(flag)
				{
					ans ++;
				}
			}
		}
		cout << ans << endl; 
	}
	return 0;
}
//ÃÜÂë£ºRen5Jie4Di4Ling5% 
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
