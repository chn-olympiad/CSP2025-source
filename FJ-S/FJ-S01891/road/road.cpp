#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x,y,z;
}q[2000005];
int fa[100005],f[100005],flag[100005];
int find(int x)
{
	if(fa[x]==x)
		return x;
	else return fa[x]=find(fa[x]); 
}
void join(int x,int y)
{
	fa[find(x)]=find(y);
}
bool cmp(node x,node y)
{
	return x.z<y.z;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%lld%lld%lld",&q[i].x,&q[i].y,&q[i].z);
	int cnt=m;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&f[i]);
		for(int j=1;j<=n;j++)
		{
			q[++cnt].x=n+i;
			q[cnt].y=j;
			scanf("%lld",&q[cnt].z);
		}
	}
	sort(q+1,q+cnt+1,cmp);
	int sum=1;
	for(int i=1;i<=k;i++)
		sum*=2;
	for(int i=1;i<=n;i++)
		flag[i]=1;
	int minn=1e18;
	for(int i=0;i<sum;i++)
	{
		int x=i,tot=1,s=0,ans=0,num=0;
		while(tot<=k)
		{
			flag[n+tot]=x%2;
			if(x%2==1)
			{
				s++;
				ans+=f[tot];
			}
			x/=2;
			tot++;
		}
		for(int j=1;j<=n+k;j++)
			fa[j]=j;
		for(int j=1;j<=cnt;j++)
		{
			if(find(q[j].x)!=find(q[j].y)&&flag[q[j].x]==1&&flag[q[j].y]==1)
			{
				ans+=q[j].z;
				num++;
				join(q[j].x,q[j].y);
				if(num==s+n-1)
					break;
			}
		}
		if(num==s+n-1)
			minn=min(minn,ans);
	}
	printf("%lld",minn);
	return 0;
}
