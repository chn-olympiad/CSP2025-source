#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,ans;
ll a[5050];
void dfs(ll step,ll num,ll mx,ll sum)
{
	if(step==n+1)
	{
		if(num<3)
		{
			return;
		}
		if(mx*2>=sum)
		{
			return;
		}
		ans++;
		ans=ans%mod;
		return;
	}
	dfs(step+1,num+1,max(mx,a[step]),sum+a[step]);
	dfs(step+1,num,mx,sum);
}
int main()
{
	freopen("r","polygon.in",stdin);
	freopen("w","polygon.out",stdout);
	ll i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans%mod;
	return 0;
}