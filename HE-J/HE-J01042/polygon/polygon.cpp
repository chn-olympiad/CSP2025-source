#include<bits/stdc++.h>
using namespace std;

const long long N = 5e3 + 53, mod = 998244353;
long long n, a[N], ans;
long long cnt(int k)
{
	long long mul = 1;
	while(k--) mul = mul * 2 % mod;
	return mul;
}
void dfs(long long now, long long sum, long long end)
{
	if(sum > a[end])
	{
		ans = (ans + cnt(end - now) % mod) % mod;
		return;
	}
	if(now == end) return;
	dfs(now + 1, sum + a[now], end);
	dfs(now + 1, sum, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(long long i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(long long i = 3; i <= n; i++) dfs(1, 0, i);
	cout << ans << endl;
	return 0;
}
