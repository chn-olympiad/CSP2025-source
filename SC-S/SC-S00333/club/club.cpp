#include<bits/stdc++.h>
using namespace std;
int t,n,h[100005][5],a[5],b[100005];
bool f[10005][5];
long long int ans,maxa;
long long dfs(int x,int j)   //x为第几个人。 
{
	b[0]=0;
	if(b[x]!=-1) return b[x];
	if (x==-1)  return 0;
	if (a[j]>(n/2))	return 0;
	if (j>3) return 0;
	if (f[x][j]==false)
	{
		f[x][j]=true;
		a[j]++;
		dfs(x-1,j);
		dfs(x-1,j-1);
		a[j]--;
		f[x][j]=false;
		return ans=h[x][j]+max(dfs(x-1,j),dfs(x-1,j-1));		
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	memset(b,-1,sizeof(b));
	for (int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for (int j=1;j<=n;j++)
			scanf("%d%d%d",&h[j][1],&h[j][2],&h[j][3]);
		ans=0;
		maxa=0;
		a[1]=0;
		a[2]=0;
		a[3]=0;
		dfs(n,3);
		printf("%lld\n",ans);
	}
	return 0;
}