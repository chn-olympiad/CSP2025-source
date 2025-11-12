#include<bits/stdc++.h>
using namespace std;
const int N=100010;
struct node{
	int x,y,z;
}a[N];
int n,sum,ans;
void dfs(int o,int p,int q,int i)
{
	if(i>n)
	{
		ans=max(ans,sum);
		return ;
	}
	int x=a[i].x,y=a[i].y,z=a[i].z;
	if(o<n/2)
	{
		sum+=x;
		dfs(o+1,p,q,i+1);
		sum-=x;
	}
	if(p<n/2)
	{
		sum+=y;
		dfs(o,p+1,q,i+1);
		sum-=y;
	}
	if(q<n/2)
	{
		sum+=z;
		dfs(o,p,q+1,i+1);
		sum-=z;
	}
}
bool cmp(node x,node y)
{
	return x.x>y.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		sum=0;
		ans=0;
		scanf("%d",&n);
		int fl=1,fl1=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y!=0 || a[i].z!=0)
				fl=0;
			if(a[i].z!=0)
				fl1=0;
		}
		if(fl)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].x;
			printf("%d\n",ans);
			continue;
		}
		/*if(fl1)
		{
			sort(a+1,a+n+1,cmp);
			
			continue;
		}*/
		dfs(0,0,0,1);
		printf("%d\n",ans);
	}
	
	return 0;
}