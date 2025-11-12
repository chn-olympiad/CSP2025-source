#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[500009];
	cin >> n >> k;
	int ans = 0;
	int maxx = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 3;i <= n;i++)
	{
		ans = a[i-1];
		for (int j = 2;j <= i;j++)
		{
			ans ^= a[j];
		}
		maxx = max(ans,maxx);
	}
	cout <<maxx;
	return 0;
}
