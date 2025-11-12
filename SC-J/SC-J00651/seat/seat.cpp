#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(const int& a, const int& b)
{
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, x = 1, y = 1, idx;
	bool down = true;
	cin >> n >> m;
	vector<int> a(n * m);
	for (int i = 0; i < n * m; i++)
	{
		cin >> a[i];
	}
	int r = a[0];
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < n * m; i++)
	{
		if (a[i] == r) idx = i;
	}

	for (int i = 0; i < idx; i++)
	{
		if (down)
		{
			if (y == n)
			{
				down = false;
				x++;
			}
			else
			{
				y++;
			}
		}
		else
		{
			if (y == 1)
			{
				down = true;
				x++;
			}
			else
			{
				y--;
			}
		}
	}
	cout << x << ' ' << y;
	
	return 0;
}