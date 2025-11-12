#include <bits/stdc++.h>
using namespace std;
int a[6][100001],b[6][100001],c[6][100001],n;
long long dfs(int t,int x,int y,int z,int cnt)
{
	if(x+y+z==n)
	{
		return cnt;
	}
	long long maxn=0;
	if(x<n/2)
	{
		maxn=max(maxn,dfs(t,x+1,y,z,cnt+a[t][x+y+z+1]));
	}
	if(y<n/2)
	{
		maxn=max(maxn,dfs(t,x,y+1,z,cnt+b[t][x+y+z+1]));
	}
	if(z<n/2)
	{
		maxn=max(maxn,dfs(t,x,y,z+1,cnt+c[t][x+y+z+1]));
	}
	return maxn;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[j][i],&b[j][i],&c[j][i]);
		}
		long long maxn=dfs(j,0,0,0,0);
		cout<<maxn<<endl;
	}
	return 0;
}
