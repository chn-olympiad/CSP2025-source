#include<bits/stdc++.h>
using namespace std;
int a[5010],ans;
int n;
void dfs(int sum,int maxn,int u)
{
	maxn=max(maxn,a[u]);
	sum+=a[u];
	if(sum>maxn*2)
	{
		ans++;
	}
	for(int i=u+1;i<=n;i++)
	{
		dfs(sum,maxn,i);
	}
	return;
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
	for(int i=1;i<=n;i++)
	{
		dfs(0,0,i);
	}
	cout<<ans;
	return 0;
}
