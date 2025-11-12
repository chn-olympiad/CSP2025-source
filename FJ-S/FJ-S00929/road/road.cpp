#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,ans=0x3f3f3f3f;
int pre[10005];
int vil[15][10005];
bool f=true;
struct edge
{
	int u,v,w;
}e[2024005];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(pre[x]==x)return x;
	return pre[x]=find(pre[x]);
}
void solve(int z)
{
	int cnt=m,sum=0,ccnt=0;
	for(int i=1;i<=n;i++)pre[i]=i;
	for(int i=1;i<=k;i++)
	{
		if(z&(1<<(i-1)))
		{
			sum+=vil[i][0];
			for(int j=1;j<=n;j++)
			{
				e[++cnt].u=0;
				e[cnt].v=j;
				e[cnt].w=vil[i][j];
			}
		}
	}
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int r1=find(e[i].u),r2=find(e[i].v);
		if(r1!=r2)
		{
			pre[r2]=r1;
			ccnt++;
			sum+=e[i].w;
			if((z==0&&ccnt==n-1)||(z!=0&&ccnt==n))
			{
				break;
			}
		}
	}
	ans=min(ans,sum);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&vil[i][0]);
		if(vil[i][0]!=0)f=false;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&vil[i][j]);
		}
	}
	if(f)
	{
		solve((1<<k)-1);
		printf("%d",ans);
		return 0;
	}
	for(int i=0;i<=(1<<k)-1;i++)
	{
		solve(i);
	}
	printf("%d",ans);
	return 0;
}

