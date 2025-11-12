# include <bits/stdc++.h>
# define ll long long
using namespace std;
const ll N =5050,Mod=998244353;
ll n,ans=0,a[N];
ll dfs(ll x,ll sum,ll Max)
{
	if(x>n)return (sum>Max*2);
	return (dfs(x+1,sum+a[x],max(Max,a[x]))+dfs(x+1,sum,Max))%Mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	cout<<dfs(1,0,0);
}