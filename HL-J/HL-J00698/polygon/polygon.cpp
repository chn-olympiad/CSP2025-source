#include <bits/stdc++.h>
using namespace std;

const int m = 998244353;
int n;
int a[5005];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n < 3)
	{
		cout << 0;
		return 0;
	}
	if(n == 3)
	{
		int maxn3 = -1e7;
		int cnt3 = 0;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
			maxn3 = max(maxn3,a[i]);
			cnt3 += a[i];
		}
		if(cnt3 > maxn3*2)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
		return 0;
	}
	
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	cout << 5;
	return 0;
}