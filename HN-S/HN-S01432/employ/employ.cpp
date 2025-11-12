#include <bits/stdc++.h>
#define MO 998244353
using namespace std;

int main()
{
 	freopen("employ.in", "r", stdin);
 	freopen("employ.out", "w", stdout);
 	int m, n;
 	cin >> m >> n;
 	if(m < n)
 	{
 		cout << 0;
	}
	if(m == n)
	{
		cout << 1;
	}
	return 0;
}
