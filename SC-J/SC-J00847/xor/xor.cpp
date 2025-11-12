#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],vis[500005];
int ma=-1;
void dfs(int d,int cnt)
{
	vis[d]=cnt;
	if(d>=n)
	{
		ma=max(ma,cnt);
		return;
	}
	for(int i=d;i<=n;i++)
	{
		if((b[i]^b[d-1])==k)
		{
			if(cnt+1>vis[i+1])dfs(i+1,cnt+1);
			break;
		}
	}
	if(cnt>=vis[d+1])dfs(d+1,cnt);
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d%d",&n,&k,&a[1]);
	b[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
	}
	dfs(1,0);
	cout<<ma;
	return 0;
}