#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt;ll n;
ll a[5010];
void dfs(int ge,int x,int maxn,int sumn)
{
	if(x<1)
	{
		return;
	}
	if(ge>=3&&sumn>2*maxn)
	{
		cnt++;
	}
	for(int i=x-1;i>=1;i--)
	{
		dfs(ge+1,i,maxn,sumn+a[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		dfs(1,i,a[i],a[i]);
	}
	cout<<cnt%998244353;
	return 0;
}
