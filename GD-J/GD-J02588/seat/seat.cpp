#include <bits/stdc++.h>
using namespace std;
int m,n;
int a[200];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i ++)
	{
		cin >> a[i];
	}
	int tmp = a[1];
	int q;
	sort(a+1,a+n*m+1,cmp);
	for (int i = 1;i <= n*m;i++) 
	{
		if (a[i] == tmp)
		{
			q = i;
			break;
		}
	}
	int c,r;
	float q1 = q;
	float n2 = n;
	c = ceil(q1/n2);
	if (c %2 == 0)
	{
		if (q%n == 0)
		{
			r = 1;
		}
		else r = n-(q%n)+1;
	}
	else
	{
		if (q%n == 0)
		{
			r = n;
		}
		else r = q%n;
	}
	cout << c <<" " << r ;
	return 0;
}

