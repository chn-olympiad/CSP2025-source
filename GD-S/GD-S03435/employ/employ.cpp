#include <bits/stdc++.h>

using namespace std;

const int N = 507;

int n, m, c[N];
string s;

inline int cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	sort(c + 1, c + n + 1, cmp);
	
	int ans = 1, cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (c[i] == 0) break;
		++cnt;
		ans = (ans * i) % 998244353;
	}
	if (m == cnt) cout << ans << endl;
	else cout << 0 << endl;
	
	return 0;
}
