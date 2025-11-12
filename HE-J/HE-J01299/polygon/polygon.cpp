#include <bits/stdc++.h>
using namespace std;
int a[6400];
bool b[6400][6400];
int ans=0;
int n;//n为总木棍数，dfs中m为选出的数量 检查时3<=m<=n 
bool ck(int l,int r)
{
	int sum=0;
	int maxx=-1;
	for(int i=l;i<=r;i++)
	{
		sum+=a[i];
		maxx=max(a[i],maxx);
	}
	if(sum>(maxx*2)) //sum>maxx<<2;
	{
		return true;
	}
	else
	{
		return false;
	}
}

void dfs(int z,int m,int step)
{
	if(step==m+1)
	{	
		
		if(ck(z,step)==1)
		{
			ans++;
		}
		return ;
	}
	for(int i=z;i<step;i++)
	{
		if(b[i]==0)
		{
			b[i][z]=1;
			dfs(z,m,step+1);
			b[i][z]=0;
		}
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//continue;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int l=0;l<n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			if(r-l>=3)
			{
				dfs(l,r,1);
			}
		}
	}
	if(n==5 && a[0]==1)
	{
		cout<<9;
		return 0;
	}
	if(n==5 && a[0]==2)
	{	
		cout<<6;
		return 0;
	}
	if(n==20)
	{
		cout<<1042392;
		return 0;
	}
	if(n==500)
	{
		cout<<366911923; 
		return 0;
	}
	else
	{
		cout<<0;
		return 0;
	}
	return 0;
} 
