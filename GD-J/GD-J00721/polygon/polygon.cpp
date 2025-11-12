#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N = 5e3 + 10;
const ll mod = 998244353;
int n,a[N];
bool flag = true;
ll ans;
ll qp(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res % mod;
}
void dfs(int p,int sum,int mx)
{
	if(p == n + 1)
	{
		if(sum > mx * 2)
			ans++;
		return;
	}
	dfs(p + 1,sum + a[p],max(mx,a[p]));
	dfs(p + 1,sum,mx);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != 1)
			flag = true;
	}
	if(n < 3)
	{
		cout << 0;
		return 0;
	}
	if(!flag)
	{
		cout << (((qp(2,n) + mod - 1ll * n) % mod) + mod - (1ll * (1ll * n * (n - 1) % mod) * qp(2,mod - 2) % mod)) % mod;
		return 0;
	}
	dfs(1,0,0);
	cout << ans;
	return 0;
}

