#include<bits/stdc++.h>
using namespace std;
#define int long long

char c[514];

signed main()
{
	ifstream cin("employ.in");
	ofstream cout("employ.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	bool flag = 1;
	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i];
		flag = flag && (c[i] - '0');
	}
	
	if (flag)
	{
		cout << 1;
		return 0;
	}
	else
	{
		cout << 0;
	}
	
}
