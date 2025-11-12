#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll M=998244353;
ll n,a[10000],ans=0;

void dfs(ll x,ll maxn,ll sum,ll num)
{
	if(x>n) return;
	dfs(x+1,maxn,sum,num);
	
	maxn=max(maxn,a[x]);
	sum+=a[x];
	x++;
	num++;
	dfs(x,maxn,sum,num);
	if(num>=3 && maxn*2<sum) ans++;
	
	return;
}

void solve()
{
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	dfs(1,-1e18,0,0);
	cout<<ans%M;
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
