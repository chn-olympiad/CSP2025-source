// D
// expect pts = 40 + 24
// expect diff = idk, blue?

#include <bits/stdc++.h>
using namespace std;
const int maxn = 25, mod = 998244353;
const int maxm = 5010;
typedef long long LL;

int n;
LL a[maxn];
int C[maxm][maxm];
LL ans;

bool check(int x)
{
	LL sum = 0, mx = 0, cnt = 0;
	int idx = 1;
	while(x)
	{
		if(x & 1)
		{
			sum += a[idx];
			mx = max(mx, a[idx]);
			cnt ++;
		}
		x >>= 1;
		idx ++;
	}

	return ((sum > ((LL)2 * mx)) && cnt >= 3);
}

void init()
{
	for(int i = 0 ; i <= 5005 ; i ++)
		for(int j = 0 ; j <= i ; j ++)
		{
			if(!j)
				C[i][j] = 1;
			else
				C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
		}
}

void spesol()
{
	init();
	//cout << C[5][4];

	LL ans = 0;
	for(int i = 3 ; i <= n ; i ++)
		ans = (ans % mod + C[n][i] % mod) % mod;
	cout << ans << endl;

	exit(0);
}

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	bool isspecial = 1;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
		if(a[i] != 1)
			isspecial = 0;
	}

	if(isspecial)
		spesol();

	for(int i = 1 ; i < (1 << n) ; i ++)
		if(check(i))
			ans = (ans % mod + 1 % mod) % mod;
	cout << ans << endl;

	return 0;

}
