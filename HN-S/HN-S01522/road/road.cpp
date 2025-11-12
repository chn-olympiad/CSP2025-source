#include<bits/stdc++.h>
#define MAXN 1000002
using namespace std;
int n,m,k,a[12+MAXN];
vector<int> road[2*MAXN];
vector<int> r[MAXN];
int chen[20],ans=INT_MAX;
inline void dfs(int x,int ans1)
{
	bool flag=true;
	for(int i=1;i<=n+k;i++)
	{
		if(i<=n)
		{
			if(a[i]==0)
			{
				flag=false;
				break;
			}
		} 	
		else
		{
			if(chen[i-n]==0)
			{
				if(a[i]==0) 
				{
					flag=false;
					break;
				}
			}
		}
			
	}
	if(flag==true) 
	{
		ans=min(ans,ans1);
		return ;
	}
	for(int i=1;i<=n+k;i++)
	{
		if(i<=n&&a[i]==0)
		{
			if(road[i][x]==0) a[i]=1,dfs(i,ans1),a[i]=0;
			else
			{
			    int asd=road[i][x];
				road[i][x]=road[x][i]=0;
				a[i]=1;
				dfs(i,ans1+asd);
				a[i]=0;
				road[i][x]=road[x][i]=asd;
			}
		}
		else if(a[i]==0)
		{
			if(chen[i-n]==0)
			{
				if(road[i][x]==0) a[i]=1,dfs(i,ans1),a[i]=0;
			    else
			    {
				    int asd=road[i][x];
				    road[i][x]=road[x][i]=0;
				    a[i]=1;
				    dfs(i,ans1+asd);
				    a[i]=0;
				    road[i][x]=road[x][i]=asd;
			    }//chen[i-n];
			}
			else
			{
				int asd=chen[i-n];
				chen[i-n]=0;
				dfs(x,ans1+asd);
				chen[i-n]=asd;
			}
		}
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		road[a].push_back(b);
		road[b].push_back(a);
		road[a][b]=road[b][a]=c;
	}
	for(int i=1;i<=k;i++)
	{
		int a;
		cin>>a;
		chen[i]=a;
		for(int j=1;j<=n;j++) 
		{
		    road[j].push_back(i+n);
			road[i+n].push_back(j);
			scanf("%d",&road[i+n][j]);
			road[j][i+n]=road[i+n][j];
		}
	}
	//dfs(1,0);
	printf("%d",ans);
	return 0;
}
