#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int b[500010];
int maxn=0;
void dfs(int step,int sum)
{
	if(sum+n-step+2<maxn)
	{
		return;
	}
	if(step>n)
	{
		maxn=max(maxn,sum);
		return;
	}
	if(b[step]!=-1)
	{
		dfs(b[step]+1,sum+1);
	}
	dfs(step+1,sum);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int j=i;
		int x=a[i];
		while(x!=k&&j<=n)
		{
			j++;
			x^=a[j];
		}
		if(j>n)b[i]=-1;
		else b[i]=j;
		cout<<b[i]<<" ";
	}
	dfs(1,0);
	cout<<maxn;
	/*
	int l=1,r=1e5+5;
	int ans=0;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid;
		}
	}
	*/
	return 0;
}
