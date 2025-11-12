#include<bits/stdc++.h>
using namespace std;
int t;
int n,m=3;
int ans[100002];
int a[100001][4];
void dfs(int x,int s1,int p1,int s2,int p2,int s3,int p3)
{
	if(p1>n/2||p2>n/2||p3>n/2)
	return;
	ans[x]=max(ans[x],s1+s2+s3);
	if(x>n)
	return;
	dfs(x+1,s1+a[x][1],p1+1,s2,p2,s3,p3);
	dfs(x+1,s1,p1,s2+a[x][2],p2+1,s3,p3);
	dfs(x+1,s1,p1,s2,p2,s3+a[x][3],p3+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		bool p=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			ans[i]=-2e9;
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
				if(j!=1)
				p&=(a[i][j]==0);
			}
		}
		if(p)
		{
			int t[10001],ju=0;
			for(int i=1;i<=n;i++)
			t[i]=a[i][1];
			sort(t+1,t+n+1);
			for(int i=n;i>n/2;i--)
			ju+=t[i];
			printf("%d\n",ju); 
			continue;
		}
		ans[n+1]=-2e9;
		dfs(1,0,0,0,0,0,0);
		printf("%d\n",ans[n+1]);
	}
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0 

*/
