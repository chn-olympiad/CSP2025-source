#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;

const int N = 1e5 + 50;
ll t, ans = 0, a[N], b[N], c[N], dp[210][210][210];
pair<ll, ll> d[N];

void dfs_1(ll dep, ll sum, ll n, ll a_size, ll b_size, ll c_size)
{
	if(dep > n)
	{
		if(a_size > n / 2) return;
		if(b_size > n / 2) return;
		if(c_size > n / 2) return;
//		cout << "sum = " << sum << "\n"; 
		ans = max(ans, sum);
		return;
	}
	if(a_size > n / 2) return;
	if(b_size > n / 2) return;
	if(c_size > n / 2) return;
	dfs_1(dep + 1, sum + a[dep], n, a_size + 1, b_size, c_size);
	dfs_1(dep + 1, sum + b[dep], n, a_size, b_size + 1, c_size);
	dfs_1(dep + 1, sum + c[dep], n, a_size, b_size, c_size + 1);
}

void dfs_2(ll dep, ll sum, ll n, ll a_size, ll b_size, ll c_size) // 这个dfs貌似并不是正确的 
{
	if(dep > n)
	{
		if(a_size > n / 2) return;
		if(b_size > n / 2) return;
		if(c_size > n / 2) return;
//		cout << "sum = " << sum << "\n"; 
		ans = max(ans, sum);
		return;
	}
	dp[dep][a_size][b_size] = max(dp[dep][a_size][b_size], sum);
	if(dp[dep + 1][a_size + 1][b_size] < sum + a[dep]) dfs_2(dep + 1, sum + a[dep], n, a_size + 1, b_size, c_size);
	if(dp[dep + 1][a_size][b_size + 1] < sum + b[dep]) dfs_2(dep + 1, sum + b[dep], n, a_size, b_size + 1, c_size);
	if(dp[dep + 1][a_size][b_size] < sum + c[dep]) dfs_2(dep + 1, sum + c[dep], n, a_size, b_size, c_size + 1);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--)
	{
		// 输入 
		ll n = 0;
		bool flagA= 1, flagB = 1;
		ans = 0;
		cin >> n;
		for(ll i = 1; i <= n; i++) 
		{
			cin >> a[i] >> b[i] >> c[i];
			d[i].first = a[i]; d[i].second = b[i];
			if(b[i] != 0 || c[i] != 0) flagA = 0;
			if(c[i] != 0) flagB = 0;
		}
		if(n <= 10) // 20pts 
		{
			dfs_1(1, 0, n, 0, 0, 0);
			cout << ans << "\n";
		}
		else if(n <= 30) // 20pts?
		{
			memset(dp, 0, sizeof(dp));
			dfs_2(1, 0, n, 0, 0, 0);
			cout << ans << "\n";
		}
		else if(flagA == 1) // 特殊性质 A：ai2 = ai3 = 0 5pts
		{
			sort(a + 1, a + n + 1, greater<ll>());
			for(ll i = 1; i <= n / 2; i++) ans += a[i];
			cout << ans << "\n";
		}
		else // 特殊性质 C：独立均匀随机生成 10pts
		{
			ll a_size = 0, b_size = 0, c_size = 0;
			for(ll i = 1; i <= n; i++) 
			{
				if(a[i] >= max(b[i], c[i]) && a_size <= n / 2) ans += a[i];
				else if(b[i] >= max(a[i], c[i]) && b_size <= n / 2) ans += b[i];
				else ans += c[i];
			}
			cout << ans << "\n";
		}
	}
	return 0;	
} 
