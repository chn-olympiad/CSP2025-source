#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	int cnt = 0;
	if(a[0] + a[1] > a[2])
		cnt++;
	if(a[0] + a[2] > a[1])
		cnt++;
	if(a[1] + a[2] > a[0])
		cnt++;
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
