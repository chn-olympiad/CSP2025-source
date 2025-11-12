#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , m;
ll a[105];
ll r;
bool cmp(ll x , ll y)
{
	return x > y;
}
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1 , a + n * m + 1 , cmp);
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i] == r)
		{
			r = i;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1;j <= m;j++)
			{
				r--;
				if(r == 0)
				{
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
		else
		{
			for(int j = m;j >= 1;j--)
			{
				r--;
				if(r == 0)
				{
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}
	return 0;
}