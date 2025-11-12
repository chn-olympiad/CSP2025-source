#include <bits/stdc++.h> 
using namespace std;
int a[1005];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int x = a[1], now;
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			if (i % 2 == 1) now = n * (i - 1) + j;
			else now = n * (i - 1) + n - j + 1;
			if (a[now] == x) 
			{
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}	
	return 0;
}
