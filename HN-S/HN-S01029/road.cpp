#include<bits/stdc++.h>
using namespace std;
unsigned int n,m,k,road[10002][10002],cty[10002][10002],r2[10002][10002],val[11],ans; 

int min(int a,int b)
{
	if (a>=b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{	
	freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i<=m;i++)
	{
		int u,v,val1;
		scanf("%d%d%d",&u,&v,&val1);
		road[u][v]=val1;
	}
	for(int i =1; i<=k;i++)
	{
		scanf("%d",val+i);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&cty[i][j]);
		}
	}
	for(int i =1; i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			r2[i][j] = -1;
			for(int num =1; num<=k;num++)
			{	
				int numval =0;
				numval = cty[num][i] + cty[num][j] +val[num];
				if(numval!=0){
					r2[i][j] = min(numval,r2[i][j]);
				}
				
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j =1;j<=n;j++)
		{	
			if(i>=j)
			{
				continue;
			}
			if(road[i][j]==0&&road[j][i]!=0)
			{
				road[i][j] = road[j][i];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j =1;j<=n;j++)
		{
			if(i>=j&&road[i][j]==0)
			{
				continue;
			}
			road[i][j] =min(road[i][j],r2[i][j]);
		}
	}
	ans =0;
	for(int i=1;i<=n;i++)
	{
		for(int j =1;j<=n;j++)
		{	
			if(i>=j)
			{
				continue;
			}
			int numval;
			numval =  road[i][j];
			ans = min(road[i][j],road[i][j-1])+ans;
		}
	}
	printf("%d",ans);
	return 0;
} 
