#include <bits/stdc++.h>
using namespace std;
int sum;
int m[3];
int a[10010];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, maxx, ans;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		sum = 0;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> m[0] >> m[1] >> m[2];
			maxx = max(max(m[0], m[1]), m[2]);
			sum += maxx;
		} 	
		cout << sum << endl;
	}
	return 0;
} 
