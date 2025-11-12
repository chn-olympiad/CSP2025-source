#include <bits/stdc++.h>
using namespace std;

int a[500005],g[500005],ii;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt = 0,tt = 0;
	bool pf = true;
	cin >> n >> k;
	for (int i = 1;i <= n;i++) 
	{
		cin >> a[i];
		g[i] = g[i - 1] ^ a[i];
		if (a[i] > 1) pf = false;
	}
	if (pf)
	{
		if (k == 0) 
		{
			bool f = false;
			int tmp = 0;
			for (int i = 1;i <= n;i++)
			{
				if (!f)
				{
					if (a[i]) f = true;
					else cnt++;
				}
				else
				{
					if (a[i]) 
					{
						if (tmp >= 1) cnt += tmp;
						else cnt++,f = false;
						tmp = 0;
					}
					else tmp++;
				}
			}
			cout << cnt;
			return 0;
		}
		else
		{
			for (int i = 1;i <= n;i++) if (a[i]) cnt++;
			cout << cnt;
			return 0;
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = i - 1;j >= tt;j--)
		{
			if ((g[i] ^ g[j]) == k) 
			{
				cnt++,tt = i;
				//cout << "//" << i << " " << j << endl;
			}
		}
	}
	cout << cnt;
	return 0;
}
