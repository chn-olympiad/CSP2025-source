#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
long long ans;
void dfs(int sl,int id,int maxn,int sum)
{
	if(id>n)
	{
		if(sl>=3&&sum>(maxn*2))ans++;
		return;
	}
	dfs(sl+1,id+1,max(maxn,a[id]),sum+a[id]);
	dfs(sl,id+1,maxn,sum);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n<=20)
	{
		dfs(0,1,0,0);
		cout<<ans;
	}
	else
	{
		ans=1;
		for(int i=1;i<=n;i++)ans=(ans*2)%998244353;
		cout<<(ans-n-(n-1)*n/2)%998244353;
	}
	return 0;
}
