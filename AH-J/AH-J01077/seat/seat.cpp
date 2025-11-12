#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , m , a[105] , x , y , R , s[105] , t , pos , f;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	R = a[1];
	sort(a + 1 , a + n * m + 1);
	x = 1;
	y = 1;
	for(ll i = n * m;i >= 1;i--)
	{
		s[++t] = a[i];
		if(s[t] == R)
		{
			pos = t;
		}
	}
	while(1)
	{
		pos--;
		if(pos == 0)
		{
			cout << x << " " << y;
			break;
		}
		if(f == 0)
		{
			y++;
		}
		else
		{
			y--;
		}
		if(y == n + 1)
		{
			y = n;
			f = 1;
			x++;
		}
		if(y == 0)
		{
			y = 1;
			f = 0;
			x++;
		}
	}
	return 0;
}
