#include<iostream>
#include<algorithm>
using namespace std;

int n, m, ansx, ansy = 1, d;
struct node{
	int id, x;
}a[110];
bool cmp(node x, node y)
{
	return x.x > y.x;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i].x;
		a[i].id = i;
	}
	sort(a + 1, a + n * m, cmp);
	for(int i = 1; i <= n * m; i++)
	{
		if(!d)
		{
			ansx++;
			if(ansx > n)
			{
				ansx--;
				ansy++;
				d = !d;
			}
		}
		else
		{
			ansx--;
			if(ansx < 1)
			{
				ansx++;
				ansy++;
				d = !d;
			}
		}
		if(a[i].id == 1)
		{
			cout << ansy << ' ' << ansx;
			return 0;
		}
	}
}
