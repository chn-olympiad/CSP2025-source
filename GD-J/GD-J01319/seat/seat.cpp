#include <bits/stdc++.h>
using namespace std;
int n, m; 
int p, dx, a[100005]; 
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m; 
	for(int i = 1; i <= n * m; i++)
		cin >> a[i]; 
	p = a[1]; 
	sort(a + 1, a + n * m + 1); 
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i] == p)
		{
			dx = i; 
			continue; 
		}
	}
//	cerr << dx << "\n"; 
	int tmp = n * m; 
	for(int j = 1; j <= m; j++)
	{
		if(j % 2 == 1)
		{
			for(int i = 1; i <= n; i++)
			{
				if(tmp == dx)
				{
					cout << j << " " << i; 
					return 0; 
				}
				tmp--; 
			}
		}
		else
		{
			for(int i = n; i >= 1; i--)
			{
				if(tmp == dx)
				{
					cout << j << " " << i; 
					return 0; 
				}
				tmp--; 
			}
		}
	}
	cout << "???"; 
	return 0; 
}

