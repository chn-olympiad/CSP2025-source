#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long
int n,k;
int a[500010];
int maxn=0;
bool all1=1,all01=1;
int f[500010];
int dfs(int i,int now,int cnt)
{
	if(f[i])return f[i];
	if(i==n+1)
	{
		f[i]=max(f[i],cnt);
		return f[i];
	}
	if(now==k)
	{
		f[i]=max(f[i],dfs(i+1,a[i+1],cnt+1));
		//return f[i];
	}
	f[i]=max(f[i],dfs(i+1,(now^a[i+1]),cnt));
	f[i]=max(f[i],dfs(i+1,a[i+1],cnt));
	return f[i];
}
signed main()
{
	ios::sync_with_stdio(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			all1=0;
		}
		if(a[i]!=1&&a[i]!=0)
		{
			all01=0;
		}
	}
	if(all1==1)
	{
		cout<<n/2;
		return 0;
	}
	else if(all01==1&&k==0)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)cnt++;
		}
		cout<<cnt;
		return 0;
	}
	else if(all01==1&&k==1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)cnt++;
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		maxn=max(maxn,dfs(i,a[i],0));
		memset(f,0,sizeof(f));
	}
	cout<<maxn;
}
