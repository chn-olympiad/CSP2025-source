#include<bits/stdc++.h>
using namespace std;
//const int N = 1e6 + 10;
int n, m, v, v2, cnt = 0, a, b = 1, c = 1;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> v;
	for(int i = 2; i <= n * m; i++)
	{
		scanf("%d", &v2);
		if(v2 > v)
		{
			cnt++;
		}
	}
//	cout << cnt;
	a = 1;
	for(int i = 1; i <= cnt; i++)
	{
		b += a; 
		if(b > n)
		{
			a = -1;
			c += 1;
			b = n;
		}
		if(b == 0)
		{
			a = 1;
			c += 1;
			b = 1;
		}
//		cout << c << ' ' << b << endl; 
	}
	cout << c << ' ' << b;
	return 0;
}
