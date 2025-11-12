#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int a[105];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	int ycj = a[1];
	int pw = 0;
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++)
	{
		if(ycj == a[i])
		{
			pw = i;
		}
	}
	int l = 0, h = 0;
	l = (pw + n - 1) / n;
	if(l % 2 == 1)
	{
		h = (pw - 1) % n + 1;
	}
	else if(l % 2 == 0)
	{
		h = n + 1 - (pw % n);	
	}
	cout << l << " " << h;
	return 0;
}
