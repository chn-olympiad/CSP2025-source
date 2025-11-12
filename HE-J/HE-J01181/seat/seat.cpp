#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	int a[n * m + 5];
	int k;
	for(int i = 1;i <= n * m; ++ i)
	{
		cin >> a[i];
	}
	k = a[1];
	int pm;
	int u = 0;
	sort(a + 1,a + 1 + n * m);
	for(int i = n * m;i >= 1; -- i)
	{
		u ++;
		if(a[i] == k)
		{
			pm = u;
			break;
		}
	}
	int x = 1,y = 1;
	int t = 1;
	if(t == pm)
	{
		cout << x << ' ' << y;
		return 0;
	}
	while(t != pm)
	{
		if(x < n && y % 2 != 0)
		{
			x ++;
			t ++;
			if(t == pm) break;
		}
		if(x == n)
		{
			y ++;
			t ++;
			if(t == pm) break;
		}
		if(y % 2 == 0 && x > 1)
		{
			x --;
			t ++;
			if(t == pm) break;
		}
		if(x == 1)
		{
			y ++;
			t ++;
			if(t == pm) break;
		}
	}
	cout << y << ' ' << x;
	return 0;
}
