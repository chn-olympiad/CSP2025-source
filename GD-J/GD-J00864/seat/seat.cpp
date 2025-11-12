#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3 + 10, RP = LONG_LONG_MAX;

int n, m, xiaoA, a[N], ansn = 1, ansm = 1, addn = 1;

bool cmp(int a, int b)
{
	return a > b;
}

signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	int size = n * m;
	for (int i = 1; i <= size; i++)
	{
		cin >> a[i];
		if (i == 1)
			xiaoA = a[i];
	}
	sort(a + 1, a + size + 1, cmp);
	for (int i = 1; i <= size; i++)
	{
		if (ansn > n)
			ansn--, ansm++, addn = -1;
		else if (ansn < 1)
			ansn++, ansm++, addn = 1;
		if (a[i] == xiaoA)
			break;
		ansn += addn;
	}
	cout << ansm << " " << ansn;
	
	return 0;
 } 
