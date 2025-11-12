#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],ans;
int main()
{
	freopen("seat.in",r,stdin);
	freopen("seat.out",w.stdout);
	cin >> n;
	cin >> m;
	for (int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
		int maxx = 0;
		if (a[i] > maxx)
		{
			maxx = a[i];
			ans = i;
		}
	}
	cout << n*m-ans+n << " " << n*m-ans+m-(n/2);
	return 0;
}