#include <bits/stdc++.h>
using namespace std;
int t,n,a[1001][4],ans;
void dfs (int u,int sum,int x,int y,int z)
{
	if(u>n) ans=max(ans,sum);
	if(u>n) return ;
	if(x+1<=n/2) dfs(u+1,a[u][1]+sum,x+1,y,z);
	if(y+1<=n/2) dfs(u+1,a[u][2]+sum,x,y+1,z);	if(z+1<=n/2) dfs(u+1,a[u][3]+sum,x,y,z+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		ans=0;
		dfs(0,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
