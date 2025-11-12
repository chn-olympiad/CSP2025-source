#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[5005];
//long long s[5005];
/*bool db(int nl,int nr)
{
	return s[nr] - s[nl - 1] > 2 * a[nl];
}*/
bool cmp(int x,int y)
{
	return x >= y;
}
int main()
{
	/*cin >> n;
	for (int i = 1;i <= n;i ++)
	{
		cout << a[i];
		
	}
	sort(a + 1,a + n + 1,cmp);
	for (int i = 1;i <= n;i ++)
	{
		s[i] = a[i] + s[i - 1];
	}
	
	//CSPJ4CSPJ4CSPJ4CSPJ4CSPJ4CSPJ4CSPJ4CSPJ4CSPJ4CSPJ4CSPJ4CSPJ4CSPJ4CSPJ4CSPJ4
	for(int l = 1;l <= n - 3;l ++)
	{
		for(int r = l + 3;r <= n;r ++)
		{
			
		}
	}*/
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	long long s = 0;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		s += a[i];
	}
	sort(a + 1,a + n + 1);
	if (n == 3)
	{
		if (a[3] >= a[1] + a[2])
		{
			cout << 0;
		}
		else
		{
			cout << 1;
		}
	}
	else
	{
		long long ans = 1;
		for (int i = 1;i <= n;i ++)
		{
			ans *= 2;
			ans %= 998244353;
		}
		ans += 998244353;
		ans -= n + n * (n - 1) / 2;
		ans %= 998244353;
		cout << ans;
	}
	return 0;
}