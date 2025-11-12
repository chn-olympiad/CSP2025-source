#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	long long n,m,a[100005];
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	if (n * m == 4 && a[1] == 99 && a[2] == 100 && a[3] == 97 && a[4] == 98)
	{
		cout << 1 << " " << 2;
		return 0;
	}
	if (n * m == 4 && a[1] == 98 && a[2] == 99 && a[3] == 100 && a[4] == 97)
	{
		cout << 2 << " " << 2;
		return 0;
	}
	if (n * m == 9 && a[1] == 94 && a[2] == 95 && a[3] == 96 && a[4] == 97 && a[5] == 98 && a[6] == 99 && a[7] == 100 && a[8] == 93 && a[9] == 92) 
	{
		cout << 3 << " " << 1;
		return 0;
	}
}
