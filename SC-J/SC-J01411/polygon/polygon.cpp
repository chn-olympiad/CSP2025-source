#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
long long ans;
int tot;
int v[5010];
int p[5010];
void dfs(int sum,int Max,int num)
{
	if(num==tot)
	{
		if(Max*2<sum)
		{
			ans=(ans+1ll)%998244353ll;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0&&i>p[num])
		{
			v[i]=1;
			p[num+1]=i;
			dfs(sum+a[i],max(Max,a[i]),num+1);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(tot=3;tot<=n;tot++)
	{
		dfs(0,0,0);
	}
	cout<<ans;
	return 0;
}