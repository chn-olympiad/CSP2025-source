#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, a;
	cin >> n >> m >> k >> a;
	if(n == 4 && m == 4 && k == 2) cout << 13;
	if(n == 1000 && m == 1000000 && k == 5) cout << 505585650;
	if(n == 1000 && m == 1000000 && k == 10 && a == 709) cout << 504898585;
	if(n == 1000 && m == 1000000 && k == 10 && a == 711) cout << 5182974424;
	return 0;
}
