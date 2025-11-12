#include <bits/stdc++.h>
using namespace std;

struct v
{
	int x,id;
};

v a[105] = {};

bool cmp(v x,v y)
{
	return x.x > y.x;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i  = 1;i <= n * m;i++)
	{
		cin >> a[i].x;
		a[i].id = i;
	}
	sort(a + 1,a + n * m + 1,cmp);
	int k = 0;
	for(int i = 1;i <= n * m;i++)
	{
		if (a[i].id == 1)
		{
			k = i;
			break;
		}
	}
	int h,l;
	h = k / (2 * n) * 2 + 1;
	l = k % (2 * n);
	if (l > n)
	{
		h++;
	    l -= n;
	    l = n - l + 1;
	}
	else if (l == 0)
	{
		h--;
		l = 1; 
	}
	cout << h << " " << l;
	return 0;
} 
