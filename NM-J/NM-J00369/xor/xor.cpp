#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int ans,cnt,anss;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		ans = a[i];
		cnt = 0;
		for (int j = i;j <= n;j++)
		{
			if (ans == k)
			{
				cnt++;
				if (j + 1 <= n)
				{
					ans = a[j + 1];
					continue;
				}
				else
					break;
			}
			ans ^= a[j + 1];
		}
		anss = max(cnt,anss);
	}
	cout << anss;
	return 0;
}
