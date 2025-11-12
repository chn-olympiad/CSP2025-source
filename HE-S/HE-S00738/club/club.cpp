#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1e5 + 15;
LL t, n, a[N], b[N], c[N], ans;
void dfs(LL now, LL cnta, LL cntb, LL cntc, LL sum)
{
	if(now > n)
	{
		ans = max(ans, sum);
		return;
	}
	if(cnta < n / 2) dfs(now + 1, cnta + 1, cntb, cntc, sum + a[now]);
	if(cntb < n / 2) dfs(now + 1, cnta, cntb + 1, cntc, sum + b[now]);
	if(cntc < n / 2) dfs(now + 1, cnta, cntb, cntc + 1, sum + c[now]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		ans = 0;
		for(LL i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}
