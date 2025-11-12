#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[200][200];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]>a[1][1]) cnt++;
		}
	}
	
	for(int j=1;j<=m;j++)
	{
		if(cnt<n)
		{
			if(j%2==1)
			{
				printf("%d %d",j,cnt+1);	
			}	
			else
			{
				printf("%d %d",j,n-cnt);
			}
			return 0;
		}
		else 
		{
			cnt-=n;
		}
	}
	return 0;
} 
