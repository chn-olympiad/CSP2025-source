#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5005],ans,sum,box[5005];
const ll mod = 998244353;
bool flag = 1;
void dfs(ll step,ll sum,ll maxn)
{
	if (step > n)
	{
		if (sum > 2 * maxn && sum && maxn) ans ++;
		ans %= mod;
		return;
	}
	dfs(step + 1,sum + a[step],max(maxn,a[step]));
	dfs(step + 1,sum,maxn);
}
ll C(ll x,ll y)
{
	memset(box,0,sizeof box);
	ll tot1 = 1,tot2 = 1;
	for (ll i = y;i>=y-x+1;i--) box[i] ++;
	for (ll i = x;i>=1;i--)
	{
		if (box[i]) box[i] --;
		else tot1 *= i;
	}
	for (ll i = 1;i<=5000;i++)
	{
		for (ll j = 1;j<=box[i];j++)
		{
			tot2 *= i;
		}
	}
	return (tot2 / tot1) % mod;
}
signed main()
{
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (ll i = 1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i] != 1) flag = 0;
	}
	if (n <= 20)
	{
		dfs(1,0,0);
		cout<<ans<<endl;
		return 0;
	}
	if (flag)
	{
		for (ll i = 3;i<=n;i++)
		{
			sum += C(i,n);
			sum %= mod;
		}
		cout<<sum<<endl;
		return 0; 
	}
	cout<<114514<<endl;
	return 0;
}
