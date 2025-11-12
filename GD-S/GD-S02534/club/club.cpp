#include<bits/stdc++.h>
using namespace std;
struct data
{
	int x,y,z;
}a[100005];
bool cmp(data x,data y)
{
	return x.x>y.x;
}
bool cmq(data x,data y)
{
	return x.y>y.y;
}
int t,n,sum,xr,yr,zr;
void dfs(int t,int s)
{
	if(t>n)
	{
		sum=max(sum,s);
		return ;
	}
	if(xr<n/2)
	{
		xr+=1;
		dfs(t+1,s+a[t].x);
		xr-=1;
	}
	if(yr<n/2)
	{
		yr+=1;
		dfs(t+1,s+a[t].y);
		yr-=1;
	}
	if(zr<n/2)
	{
		zr+=1;
		dfs(t+1,s+a[t].z);
		zr-=1;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		bool f=false;
		bool g=false;
		sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y||a[i].z)
			{
				f=true;
			}
			if(a[i].z)
			{
				g=true;
			}
		}
		if(!f)
		{
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++)
			{
				sum+=a[i].x;
			}
		}
		else if(!g)
		{
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++)
			{
				sum+=a[i].x;
			}
			sort(a+1,a+1+n,cmq);
			for(int i=1;i<=n/2;i++)
			{
				sum+=a[i].y;
			}
		}
		else
		{
			dfs(1,0);
		}
		printf("%d\n",sum);
	} 
	return 0;
}
