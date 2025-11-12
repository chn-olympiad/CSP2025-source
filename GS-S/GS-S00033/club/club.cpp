#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int t;
	cin >> t;
	for (int k = 1;k <= t;k++)
	{
		int n , a[100005][3] , pos = 1;
		cin >> n;
		for (int i = 1;i <= n;i++)
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		int f[100005];
		f[0] = 0;
		for (int i = 1;i <= n;i++)
			f[i] = max(a[i][0] , max(a[i][1] , a[i][2])) + f[i - 1];
		cout << f[n] << endl;
	}
	return 0;
}
