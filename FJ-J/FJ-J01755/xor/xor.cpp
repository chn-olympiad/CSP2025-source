#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(k == 0)
	{
		int f = 0;
		for(int i = 1;i <= n;i++)
		{
			f += a[i];
			if(f == 0 || f == 2)
			{
				ans++;
				f = 0;
			}
		}
		cout << ans;
		return 0;
	}
	else if(k == 1)
	{
		int f = 0;
		for(int i = 1;i <= n;i++)
		{
			f += a[i];
			if(f == 1)
			{
				ans++;
				f = 0;
			}
		}
		cout << ans;
		return 0;
	}
	return 0;
}
