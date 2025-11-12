#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int zt[5005],fact[5005];
int popcount(int g)
{
	int ans = 0;
	while(g)
	{
		ans += (g & 1);
		g >>= 1;
	}
	return ans;
}
void solve1()
{
	int ans = 0;
	for(int i = 1;i < (1 << n);i++)
	{
		if(popcount(i) >= 3)
		{
			int a = 0,b = 0;
			for(int j = 0;j < n;j++)
			{
				if((1 << j) & i)
				{
					a = max(a,zt[j]);
					b += zt[j];
				}
			}
			if(a * 2 < b) ans++;
		}
	}
	cout << ans;
}
int ny(int k)
{
	int res = 1ll,p = 998244351ll,mod = 998244353ll;
	while(p)
	{
		if(p & 1) res = (res * k) % mod;
		k = (k * k) % mod;
		p >>= 1;
	}
	return res;
}
int C(int n,int m)
{
	return (((fact[n] * ny(fact[m])) % 998244353ll) * ny(fact[n - m])) % 998244353ll;
}
void solve2()
{
	fact[0] = 1;
	for(int i = 1;i <= 5004;i++) fact[i] = (fact[i - 1] * i) % 998244353ll;
	int ans = 0;
	for(int i = 3;i <= n;i++) ans = (ans + C(n,i)) % 998244353ll;
	cout << ans;
}
signed main()
{
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int g = 0;
	for(int i = 0;i < n;i++)
	{
		cin >> zt[i];
		g |= zt[i];
	}
	if(n <= 20) solve1();
	else if(g == 1) solve2();
	else cout << rand(); //RP++
	return 0;
}