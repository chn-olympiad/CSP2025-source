#include <bits/stdc++.h>

using namespace std;
const int N = 5e3 + 5;

int n;
int a[N], f[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	
	if (n == 1 || n == 2)
		cout << 0;
	else if (n == 3)
	{
		if (a[3] < a[1] + a[2]) cout << 1;
		else cout << 0;
  	}

	return 0;
} 
