#include<bits/stdc++.h>
using namespace std;
int n,m,xiaorup = 1,xiaor,a,l,h;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> xiaor;
	for(int i = 1;i < n * m;i++)
	{
		cin >> a;
		if(a > xiaor)
		{
			xiaorup++;
		}
	}
	l = xiaorup / n;
	if(xiaorup % n != 0)
	{
		l++;
	}
	if(l % 2 == 1)
	{
		h = xiaorup % n;
		if(h == 0)
		{
			h = n;
		}
	}
	else
	{
		h = n - xiaorup % n + 1;
		if(h == n + 1)
		{
			h = 1;
		}
	}
	cout << l << " " << h;
	return 0;
}
