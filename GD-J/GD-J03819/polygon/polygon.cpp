#include <iostream>
using namespace std;
#define ll long long
const int P = 998244353;
const int N = 5005;
int a[N];
ll c[N][N];
ll fac[N];
ll invfac[N];
int n;
ll qpow(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1) ans = (ans*a)%P;
		a = (a*a)%P;
		b >>= 1;
	}
	return ans;
}
void init()
{
	fac[0] = 1;
	invfac[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		fac[i] = (fac[i-1]*i)%P;
		invfac[i] = qpow(fac[i],P-2);
	}
}
ll C(int n, int m)
{
	return ((fac[n]*invfac[m])%P*invfac[n-m])%P;
}

bool isc[N];
int cnt;
void dfs(int p, int maxn, ll sum)
{
	if (p > n)
	{
		if (sum > 2*(ll)maxn) cnt++;
		return;
	}
	isc[p] = 1;
	dfs(p+1,max(maxn,a[p]),sum+a[p]);
	isc[p] = 0;
	dfs(p+1,maxn,sum);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	init();
	bool flaga = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != 1) flaga = 0;
	}
	if (flaga)
	{
		ll ans = 0;
		for (int i = 3; i <= n; i++) ans = (ans+C(n,i))%P;
		cout << ans;
		return 0;
	}
	dfs(1,0,0);
	cout << cnt%P;
	return 0;
}
