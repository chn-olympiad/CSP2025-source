#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n,ans = 3,cnt = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(n < 3)
	{
		cout << 0 << endl;
		return 0;
	} 
	if(n == 3)
	{
		if(a[1] + a[2] + a[3] > max(max(a[1], a[2]), a[3]) * 2)
		{
			cout << 1 << endl;
			return 0;
		}
	}
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n - ans + 1; j++)
		{
			int x = 0,maxn = -1;
			for(int k = j; k <= ans + j - 1; k++)
			{
				x += a[k];
				maxn = max(maxn, a[k]);
			}
			if(x > maxn * 2)
			{
				cnt++;
			}
		}
		ans++;
	}
	cout << cnt << endl;
	return 0;
} 
