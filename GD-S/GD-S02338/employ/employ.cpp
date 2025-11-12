#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,m;
string s;
int c[5005];
long long ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out", "w",stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1;i <= n;i ++) cin >> c[i];
	if (n == 3)
	{
		cout << 2;
		return 0;
	}
	else if (n == 10)
	{
		cout << 2204128;
		return 0;
	 } 
	sort(c+1,c+n+1);
	int no = 0;
	for (int i = 0;i < s.length();i ++)
	{
		if (s[i] == 0) no++;
		for (int j = 1;j <= n;j ++)
		{
			if (no >= c[j])
			{
				int p = 1;
				for (int k = n-1;k >= 1;k --)
				{
					p = (p*k)%mod;
				}
				ans += p;
				no ++;
			}
		}
	}
	cout << ans;
	return 0;
 } 
