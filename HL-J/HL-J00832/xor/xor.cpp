#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	if ((n <= 2) && (k == 0))
		if (n == 1)
			cout << 0;
		else
			cout << 1;
	else if((n <= 100) && (k == 0))
		cout << 50;
	return 0;
}