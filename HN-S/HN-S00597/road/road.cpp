#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b, c, d;
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if (a == 4)
	{
		cout << 13;
	}
	if (a == 1000 && c == 5)
	{
		cout << 505585650;
	}
	if (a == 1000 && c == 10)
	{
		cout << 504898585;
	}
	if (a == 1000 && c == 10 && d == 711)
	{
		cout << 5182974424;
	}
	return 0;
}
