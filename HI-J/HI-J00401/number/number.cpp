#include <bits/stdc++.h>
#define int long long
using namespace std;

int b1[11] = {};
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	string b = "0123456789";
	if (a.size()==1)
	{
		cout << a;
		return 0;
	}
	for (int i = 0;i<a.size();i++)
	{
		for (int j = 0;j<=9;j++)
		{
			if (a[i] == b[j])
			{
				b1[b[j]-'0']++;
			}
		}
	}
	string ans = "";
	for (int i = 9;i>=0;i--)
	{
		for (int j = 1;j<=b1[i];j++)
		{
			ans += b[i];
		}
	}
	cout << ans;
	return 0;
}
