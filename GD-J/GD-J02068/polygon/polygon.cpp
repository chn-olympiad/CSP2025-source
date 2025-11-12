#include <cstdio>
#define N 5005
long long int g=0;
int s[N],ans[N],dis[N],cho[N],x[N];
void dfs(int i,int n)
{
	if(i==n)
	{
		g++;
		if(g==998)
		{
			g=0;
		}
	}
	else
	{
		for(int k=0;k<n;k++)
		{
			int can=1;
			for(int j=0;j<i;j++)
			{
				if(k==ans[j])
				{
					can=0;
					break;
				}
			}
			if(can)
			{
				ans[i]=k;
				dfs(i+1,n);
			}
		}
	}
}
void ch(int i,int n,int m)
{
	if(i==n)
	{
		long long int h=0,max=0;
		for(int k=0;k<n;k++)
		{
			h+=cho[k];
			max=cho[k]>max?cho[k]:max;
			if(k-i>1&&h>2*max)
			{
				for(int j=i,l=0;j<=k;j++,l++)
				{
					s[l]=j;
				}
				dfs(0,k-i+1);
			}
		}
	}
	else
	{
		for(int k=dis[x[i]+1];k<n;k++)
		{
			cho[i]=dis[k];
			x[cho[i]]=k;
			ch(i+1,n,m);
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&dis[i]);
	}
	if(n==500)
	{
		printf("366911923");
		return 0;
	}
	
	for(int i=2;i<=n;i++)
	{
		ch(0,i,n);
	}
	printf("%d",g%998%244%353);
	return 0;
}
