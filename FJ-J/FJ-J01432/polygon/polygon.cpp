#include <bits/stdc++.h>
using namespace std;
int l[5005];
int qwer(int n)
{
	long summ = 0;
	for(int i = n - 2;i >= 1;i--)
	{
		sum += i;
	}
	return summ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,unmin = 10000;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> l[i];
		unmin = max(unmin,l[i]);
	}
	if(n == 3)
	{
		if(l[1]+l[2]+l[3] < 2 * max(l[1],max(l[2],l[3])))
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
	if(unmin == 1)
	{
		cout << qwer(n);
		return 0;
	}
	int xuan = 3,_begin = 1,maxn = -1;
	long long ans = 0;
	while(xuan != n + 1)
	{
		long long s = 0,summ = 0;
		for(int i = _begin;i <= n;i++)
		{
			if(summ > (2 * maxn))
			{
				ans += 1;
			}
			ans %= 998244353;
		}
		xuan ++;
	}
	cout << ans;
	
	return 0;
}
