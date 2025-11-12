#include <bits/stdc++.h>
using namespace std;
int a[20][20], s[1005];
bool t(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n * m; i++)
		cin >> s[i];
	int r1 = s[0];
	sort(s, s + n * m, t);
	//for(int i = 0; i < n * m; i++) cout << s[i];
	for(int i = 1; i < n * m; i++)
	{
		if(s[i] == r1)
		{
			if(i <= n)
			{
				cout << 1  << ' ' << i + 1;
				break;
			}
			else
			{
				cout << (i + 1) / 2 << ' ' << 2;
			}
		}
	}
	/*for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(a[i][j] == r1)
				cout << j << i;
		}
	}*/
	return 0;
}
