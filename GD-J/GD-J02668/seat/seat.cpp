#include <bits/stdc++.h>
using namespace std;
int n,m,rch,rp,h,l;
int a[105]; 
bool cmp (int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	rch = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for (int i = 1;i <= n * m;i++)
	{
		if (rch == a[i])
		{
			rp = i;
			break;
		}
	}
	if (rp % n == 0)
	{
		l = rp / n;
	}
	else
	{
		l = rp / n + 1;
	}
	if (l % 2 == 1)
	{
		h = rp % n;
		if (h == 0)
		{
			h = n;
		}
	}
	else
	{
		h =  n - (rp % n) + 1;
		if (h == n + 1)
		{
			h = 1;
		}
	}
	cout << l << " " << h;
	return 0;
} 
