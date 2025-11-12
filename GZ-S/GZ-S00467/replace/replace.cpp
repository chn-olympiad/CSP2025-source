//GZ-S00467 华中师大一附中贵阳学校 陈思佟 
#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int a, b;
	cin >> a >> b;
	
	while (b --)
	{
		int x = rand(), y = rand();
		cout << (rand() + y) % x;
	}
	
	return 0;
}
