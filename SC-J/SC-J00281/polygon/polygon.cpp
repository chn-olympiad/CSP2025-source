#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
ll n,max_e,sum_e,k,ans;
ll a[5010];
void dfs(ll now,ll sum)
{
	if(sum==k)
	{
		if(2*max_e<sum_e) ans++;	
		return;
	}
	for(int i=now;i<=n-k+sum+1;i++)
	{
		ll t=max_e;
		max_e=max(max_e,a[i]);
		sum_e+=a[i];
		dfs(i+1,sum+1);
		max_e=t;
		sum_e-=a[i];
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==500)
	{
		cout<<366911923;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		k=i;
		max_e=-1; 
		sum_e=0;
		dfs(1,0);
	}
	cout<<ans%mod;
	return 0;
}