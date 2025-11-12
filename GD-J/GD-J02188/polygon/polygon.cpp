#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[50005],s[50005];
void dfs(int x,int mx,int s,int k)
{ 
	if(x==n+1)
	{
		if(k>=3)
		{
			if(mx*2<s) ans++;
		}
		ans%=998244353;
		return ;
	}
	dfs(x+1,max(mx,a[x]),s+a[x],k+1);
	dfs(x+1,mx,s,k);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	dfs(1,-1,0,0);
	printf("%d",ans);
	return 0;
}
