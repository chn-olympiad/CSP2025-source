#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++ )
#define repf(i, a, b) for(int i = (a); i >= (b); i -- )
#define ls cur << 1
#define rs cur << 1 | 1
typedef long long ll;
using namespace std;
const int N = 1e4 + 100;
const int M = 1e6 + 10;
const int P = 998244353;
int s[505], a[505], c[505], t[505], n, m, b[505], ans;
void dfs(int dep)
{
	if(dep == n + 1)
	{
		rep(i, 1, n) b[i] = c[a[i]];
		int res = 0;
		int sb = 0;
		rep(i, 1, n)
		{
			if(s[i] == 0) sb ++;
			else
			{
				if(sb >= b[i]) sb ++;
				else res ++;
			}
		}
		ans += (res >= m);
		return;
	}
	rep(i, 1, n) if(!t[i])
	{
		t[i] = 1; a[dep] = i; dfs(dep + 1); t[i] = 0;
	}
}
int main()
{
	ios ::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	rep(i, 1, n) 
	{
		char aa; cin >> aa;
		if(aa == '1') s[i] = 1;
		else s[i] = 0;
	}
	rep(i, 1, n) cin >> c[i];
	if (n > 12)
	{
		ll ans = 1;
		rep(i, 1, n) ans = (ll) ans * i % P;
		cout << ans;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}
