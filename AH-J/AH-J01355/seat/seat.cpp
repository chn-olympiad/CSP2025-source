#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int n, m;
int a[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie();
	freopen("seat.in","r",stdin);
	freopen("seat.out","w", stdout);
	cin >> n >>m;
	int t = 0;
	for(int i = 1; i <= n * m; i++)
	{
		cin >>a[i];
	}
	int now = 0;
	t = a[1];
	sort (a + 1,a + n * m+ 1);
	for (int i = 1 ; i <= n *m; i++)
	{
		if(a[i] == t)
		{
			now = (n * m - i + 1);
			break;
		}	
	}
	int x = 1,y = 1;
	int dx= 1, dy = 0;
	now--;
	while(now--)
	{
		if(x == n && dx == 1 && !dy) dx = 0, dy = 1;
		else if (x == 1 && dx == -1 && !dy) dx=0,dy = 1;
		else if (!dx && dy == 1)
		{
			if (y % 2 == 0) dx = -1, dy = 0;
			else dx = 1, dy= 0;
		}
		x += dx, y += dy;
	}
	cout << y << " " << x<< endl;
	return 0;
}
