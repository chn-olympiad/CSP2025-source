#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod=998244353;
const int N=5005;
int a[N];
int n;
ll qsm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if((b&1))
		{
			ans=ans*a%mod;
		}
		a=a*a%mod;
		b/=2;
	}
	return ans;
}
bool cmp(int u,int v)
{
	return u<v;
}
ll ans=0;
void dfs(int now,int use,int sum)
{
	if(now==n+1)
	{
		return ;
	}
	if(use>=2 && sum>a[now])
	{
		//cout << "sum=" << sum << "\n";
		ans++;
	}
	dfs(now+1,use,sum);
	dfs(now+1,use+1,sum+a[now]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	bool FLAG=1;
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]!=1)
		{
			FLAG=0;
		}
	}
	if(FLAG)
	{
		ll ans1=((qsm(2,n)-n+mod)%mod-n*(1ll*(n-1))%mod*qsm(2,mod-2)%mod+mod)%mod-1;
		while(ans<0) ans+=mod;
		cout << ans1;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	dfs(1,0,0);
	cout << ans;
	return 0;
}
