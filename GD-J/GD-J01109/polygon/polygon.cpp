#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int n;
int a[N];
int ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if (n==3)
	{
		int he,maxx=0;
		for (int i=1;i<=n;i++)
		{
			he+=a[i];
			maxx = max(maxx,a[i]);
		}
		if (he>maxx*2)
		{
			cout << 1;
			return 0;
		}
		else 
		{
			cout << 0;
			return 0;
		}
	}
	for (int j=3;j<=n;j++)
	{
		for (int i=1;i<=n-j+1;i++)
		{
			int st = i,ed = i+j-1;
			int he,maxx = 0;
			for (int k=st;k<=ed;k++)
			{
				he+=a[k];
				maxx = max(maxx,a[k]);
			}
			if (he>maxx*2)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
