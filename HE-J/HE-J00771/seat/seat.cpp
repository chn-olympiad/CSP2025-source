#include<bits/stdc++.h>
using namespace std;

int sc[101];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, rk = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> sc[i];
		if (sc[i] > sc[1])
			rk++;
	}
	int c, r;
	c = rk / n + 1;
	int temp = rk + 1 - rk / n * n;
	r = c % 2 == 1 ? temp : n + 1 - temp;
	cout << c << " " << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
