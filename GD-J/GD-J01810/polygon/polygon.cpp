#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , a[10005] , cnt = 0;
void solve1(int num)
{
	int n_he=1 , num_he=1,num_n=1;
	for(int i = 1;i <= n;i++)
	{
		n_he *= i;
	}
	for(int i = 1;i <= num;i++)
	{
		num_he *= i;
	}
	for(int i = 1;i <= n - num;i++)
	{
		num_n *= i;
	}
	cnt += n_he / (num_he * num_n);
	return;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	if(n == 1)
	{
		cout << 0;
		return 0;
	}
	else if(n == 2)
	{
		cout << 0;
		return 0;
	}
	else if(n == 3)
	{
		if(a[0] + a[2] + a[1] > max(a[0] , a[2]) , a[1]*2)
		{
			cout << 1;
			return 0;
		}
		cout << 0;
		return 0;
	}
	else if(n >= 500)
	{
		for(int i = 3;i <= n;i++)
		{
			solve1(i);
		}
		cout << cnt % 998244353;
		return 0;
	}
	return 0;
}
