#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll Mod = 998244353;
const int N = 5000;

int n;
int a[N + 5];

ll pw[N + 5];
ll f[N + 5][5005];//表示前i个,和为j的可能个数 

void calc()
{
	pw[0] = 1;
	for(int i = 1; i <= n; i++) pw[i] = (pw[i - 1] * 2) % Mod;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	calc();
	
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= 5000; j++)
		{
			f[i][j] = f[i - 1][j];
			if(j >= a[i])
			{
				f[i][j] += f[i - 1][j - a[i]];
				f[i][j] %= Mod;
			} 
			
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ll g = 0;
		for(int j = 0; j <= a[i]; j++)
		{
			if(f[i - 1][j] == 0) continue;
			g = (g + f[i - 1][j]) % Mod;
		}
		ans += (pw[i - 1] + Mod - g) % Mod;
		ans %= Mod;
	}
	
	cout << ans << '\n';
	
	return 0;
}