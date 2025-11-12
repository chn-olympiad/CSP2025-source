#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, box[10000 + 9];
string s;
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int u = 1;
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i ++)
	{
		u *= i;
	}
	cout << u;
	return 0;
}
