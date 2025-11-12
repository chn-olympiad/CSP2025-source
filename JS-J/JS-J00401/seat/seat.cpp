#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m, a[N], id;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	id = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i] == id)
		{
			if(i % n == 0)
			{
				cout << i / n << " ";
				if((i / n) % 2 == 0)
				{
					cout << "1\n";
				}
				else
				{
					cout << n << "\n";
				}
			}
			else
			{
				cout << i / n + 1 << " ";
				if((i / n + 1) % 2 == 0)
				{
					cout << n - (i % n) + 1 << "\n";
				}
				else
				{
					cout << i % n << "\n";
				}
			}
			return 0;
		}
	}
	return 0;
}
