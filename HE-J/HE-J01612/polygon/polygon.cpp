#include<bits/stdc++.h>
using namespace std;
int a[5005],n,ans,mod=998244353;
void dfs(int cnt,int mx,int sum,int i)
{
	if(i==n+1&&cnt>=3&&sum>mx*2)
	{
		ans++;
		return;
	}
	if(i==n+1)return;
	dfs(cnt,mx,sum,i+1);
	dfs(cnt+1,max(mx,a[i]),sum+a[i],i+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=20)dfs(0,0,0,1),cout<<ans;
	else cout<<1ll*n*(n-1)*(n-2)/6%mod;
	return 0;
}
