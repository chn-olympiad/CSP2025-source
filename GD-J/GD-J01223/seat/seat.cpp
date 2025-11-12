#include <bits/stdc++.h>
using namespace std;
int n , m , a[105] , f , cnt , y , x;
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++)
    {
    	cin >> a[i];
	}
	f = a[1];
	sort(a + 1 , a + n * m + 1);
	for(int i = 1; i <= n * m ; i++)
	{
		if(f == a[i])
		{
			cnt = i;
			break;
		}
	}
	cnt = n * m - cnt + 1;
	if(cnt % n == 0)
	{
		x = (cnt - 1) / n + 1;
	}
	else
	{
		x = cnt / n + 1;
	}	
	if(x % 2== 0)
	{
		if(cnt % m != 0)
		{
			y = m - cnt % m + 1;
		}
	    else
	    {
	    	y = 1;
		}
	}
	else if(cnt == m)
	{
		y = m;
	}
	else
	{
		y = cnt % m;
	}
	cout << x << " " << y;
	return 0;
}
