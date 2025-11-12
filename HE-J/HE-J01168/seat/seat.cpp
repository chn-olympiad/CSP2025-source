#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, m;
int a[N];
int arr;
int tot = 1;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) cin >> a[i];
	
	arr = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
//	for (int i = 1; i <= n * m; ++i)  cout << a[i] << ' ';
//	cout << '\n';
	int i = 1, j = 1;
	if (a[1] == arr)
	{
		cout << j << ' ' << i << '\n';
		return 0;
	}
	while (1)
	{
		if (j % 2 == 1 && i < n) i++;
		else if (j % 2 == 0 && i > 1) i--;
		else if (j % 2 == 1 && i == n) j++;
		else if (j % 2 == 0 && i == 1) j++;
//		cout << i << ' ' << j << '\n';
		tot++;
		if (a[tot] == arr)
		{
			cout << j << ' ' << i << '\n';
			break; 
		}
	}
	
	return 0;
}
