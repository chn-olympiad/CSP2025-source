#include<bits/stdc++.h>
using namespace std;
int n;int a[5005];
int vis[5005];
int ans;
void dfs(int s,int x,int turn,int sum)
{
	if(turn==0&&sum>a[x])
	{
		ans++;
		ans%=998244353;
	}
	for(int i=s;i<x;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			dfs(i+1,x,turn-1,sum+a[i]);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1) sum++;
	}
	if(sum==n)
	{
		int s=1;
		for(int i=1;i<=n;i++)
		{
			s*=i;
			s%=998244353;
		}
		for(int i=3;i<=n;i++)
		{
			int f=1;
			for(int j=1;j<=n-i;j++)
			{
				f*=j;
				f%=998244353;
			}
			int k=s/f,l=1;
			for(int j=2;j<=i;j++)
			{
				l*=j;
				l%=998244353;
			}
			ans+=k/l;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		for(int j=2;j<=i;j++)
		{
			dfs(1,i,j,0);
		}
	}
	printf("%d",ans);
	return 0;
}
