#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int N = 3e2 + 5;
int n, m, a[N];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n * m; i++)
		cin >> a[i];
	int t = a[0];
	sort(a, a + n * m, cmp);
	int i = 0, x = 1, y = 1, f = 0;
	while(a[i] != t)
	{
		i++;
		if(f == 0)
			x++;
		else
			x--;
		if(x == n + 1)
		{
			f = 1;
			x = n;
			y++;
		}
		else if(x == 0)
		{
			f = 0;
			x = 1;
			y++;
		}
	}
	cout << y << " " << x << endl;
	return 0;
}
