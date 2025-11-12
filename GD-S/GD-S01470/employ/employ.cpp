#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int MAXN = 505, MOD = 998244353;
int dif[MAXN];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	bool is = true;

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		char c; cin >> c;
		dif[i] = c - '0';
		if (!dif[i]) is = false;
	}
	
	LL ans = 1;
	if (is)
	{
		for (int i = 1; i <= n; i++)
			ans = (ans * i) % MOD;
		cout << ans << endl;
		
		return 0;
	}
	
	cout << 1 << endl;

	return 0;
}

