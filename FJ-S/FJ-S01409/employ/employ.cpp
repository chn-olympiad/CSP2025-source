#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll N= 502;
const ll mod =  998244353;

ll n, c[N], ans,a[N],vis[N],m;
string s;

void check()
{
	ll f = 0;
	for (ll i =1; i<=n;i++)
	{
		if (f >= c[a[i]])
		{
			f++;
			continue;
		}
		if (s[i-1]=='0') 
		{
			f++;
		}
	}
	if (n - f>=m)
	{
//		for(ll i=1; i<=n;i++)
//		{
//			cout <<a[i]<<" ";
//		}
//		cout << "\n";
//		cout << "m: " << m << "\n";
		ans++;
	}
}

void dfs(ll now)
{
	if (now== n+1)
	{
		check();
		return ;
	}
	for (ll i =1; i<=n;i++)
	{
		if (!vis[i])
		{
			vis[i]=1;
			a[now]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >>n>>m;
	cin >>s;
	for (ll i = 1; i <=n; i++) cin>>c[i];
	string tmp = "";
	for (ll i = 1;i <=n;i++)tmp.push_back('1');
	if (tmp==s)
	{
		long long ans = 1;
		for (ll i =1;i<=n;i++)
		{
			ans *= i;
			ans%=mod;
		}
		cout<<ans<<"\n";
		return 0;
	}
	dfs(1);
	cout << ans << "\n";
	return 0;
}
