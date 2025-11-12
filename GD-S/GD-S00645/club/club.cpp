#include<bits/stdc++.h>
using namespace std;
int n,a[100005][10];
int b[10]={0};
int maxx,s=0;
int ans[100005],k=0;
void dfs(int summ,int xx)
{
	if(xx==n+1)
	{	
		s=max(s,summ);
		return ;
	}
	else
	{
		for(int i=1;i<=3;i++)
		{
			if(b[i]<maxx)
			{
				b[i]++;
				dfs(summ+a[xx][i],xx+1);
				b[i]--;
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		maxx=n/2;
		s=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		if(n==2)
		{
			int cnt=0;
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(i==j)
						continue;
					cnt=max(cnt,a[1][i]+a[2][j]);
				}
			}
			printf("%d",cnt);
		}
		else
		{
			dfs(0,1);
			printf("%d",s);
			cout<<endl;
		}
	}
	return 0;
	
} 


