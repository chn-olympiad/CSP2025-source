#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],c,b,h,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >>m;
	int y = n*m;
	for (int i = 1;i <= y;i++)
	{
		cin >> a[i];
	}
	b = a[1];
	sort(a+1,a+y+1);
	for (int i = 1;i <= y;i++)
	{
		if(a[i] == b)
		{
			c = i;
		}
	}
	c = y+1-c;
	c = c+1;
	h = c/m;
	c -= 1;
	if(h % 2 == 1)
	{
		l = c-(h-1)*m;
	}
	else
	{
		l = (m+1)-c+(h-1)*m;
	}
	cout << h << " " << l;
	return 0;	
} 
