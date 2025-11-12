#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005]{0},ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i= 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (k == 0)
	{
		for (int i = 1;i < n;i++)
		{
			if (i == 1 && a[i] == 0)
			{
				ans++;
			}
			else if (a[i] == 0 && a[i - 1] != 0)
			{
				ans++;
			}
		}
		cout << ans;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
