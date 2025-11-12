#include<bits/stdc++.h>
using namespace std;
int n,a[1001001];
int temp[1001001];
long long ans;
int dfs(int x,int o)
{
	if(x==o+1)
	{
		int sum=0;
		int maxn=0;
		for(int i=1;i<=o;i++)
		{
			sum+=a[temp[i]];
			maxn=max(maxn,a[temp[i]]);
		}
		if(sum>(maxn*2))
			ans++;

	}
	else
	{
		for(int i=temp[x-1]+1;i<=n;i++)
		{
			temp[x]=i;
			dfs(x+1,o);
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<3)
		cout<<0;
	else
	{
		for(int i=3;i<=n;i++)
			dfs(1,i);
		cout<<ans;
	}
	return 0;
}
