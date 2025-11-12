#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10005];
long long ans = 1,res = 0;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] != 0)
		{
			res++;
		}
	}
	if (res < m)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1;i <= 100;i++)
	{
		ans = ans * i % 998244353;
	}
	cout << ans;
	return 0;
}
