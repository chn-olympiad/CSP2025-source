#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 5e3 + 1;
int n, a[N];
ll ans;

void dfs(int cur, int num, int sum)
{
	if(num >= 2)
	{
		for(int i = cur; i <= n; i++) if(sum > a[i]) ans++;
		ans %= mod;
	}
	for(int i = cur; i <= n; i++)
	{
		{
			dfs(i + 1, num + 1, sum + a[i]);
		}
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}

