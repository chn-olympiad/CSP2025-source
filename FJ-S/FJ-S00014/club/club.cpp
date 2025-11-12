#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int a[N][4],d[N],club[N];
int n,maxx;
void dfs(int i,int x,int y,int z,int t)
{
	if(i==n+1)
	{
		maxx=max(maxx,t);
		return;	
	}
	if(x==n/2) 
	{
		if(a[i][2]>a[i][3]) dfs(i+1,x,y+1,z,t+a[i][2]);
		else dfs(i+1,x,y,z+1,t+a[i][3]);
	}
	else if(y==n/2)
	{
		if(a[i][1]>a[i][3]) dfs(i+1,x+1,y,z,t+a[i][1]);
		else dfs(i+1,x,y,z+1,t+a[i][3]); 
	}
	else if(z==n/2)
	{
		if(a[i][1]>a[i][2]) dfs(i+1,x+1,y,z,t+a[i][1]);
		else dfs(i+1,x,y+1,z,t+a[i][2]);
	}
	else 
	{
		if(t+d[n]-d[i-1]>maxx) dfs(i+1,x+1,y,z,t+a[i][1]);
		if(t+d[n]-d[i-1]>maxx) dfs(i+1,x,y+1,z,t+a[i][2]);
		if(t+d[n]-d[i-1]>maxx) dfs(i+1,x,y,z+1,t+a[i][3]);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		maxx=0;
		int fl=0;
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
			}
			club[i]=a[i][1];
			if(a[i][2]!=0||a[i][3]!=0) fl=1;
			d[i]=max(a[i][1],max(a[i][2],a[i][3]));
			d[i]=d[i-1]+d[i];
		}
		if(fl==0)
		{
			sort(club+1,club+1+n);
			for(int i=n/2+1;i<=n;i++) maxx+=club[i];
			printf("%d\n",maxx);
			continue;
		}
		dfs(1,0,0,0,0);
		printf("%d\n",maxx);
	}
	return 0;
}