#include <bits/stdc++.h>
using namespace std;
const long long N = 998244353;
long long n,a[50005],maxx = -1,sum,ans = 1;
bool flag = true; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != 1)
		{
			flag = false;
		}
	}
	if(n == 3)
	{
		for(int i = 1;i <= 3;i++)
		{
			maxx = max(maxx,a[i]);
			sum += a[i];
		}
		if(sum > maxx * 2)
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
	if(flag)
	{
		long long x = 1;
		ans = 0;
		for(int i = 1;i <= n - 2;i++)
		{
			ans += x;
			x += 1;
			ans %= N;
		}
		cout << ans;
		return 0;
	}
	return 0;
}
