#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 10000
#define M 2000000
#define K 10
inline int read()
{
	int res=0;
	char x=getchar();
	while(x<'0'||x>'9')x=getchar();
	while(x>='0'&&x<='9')res=res*10+(x-'0'),x=getchar();
	return res;
}
int n,m,k,tot;
int fa[N+5];
int a[K+5][N+5];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
struct node
{
	int x,y,w;
	bool operator<(const node &t)const
	{
		return w<t.w;
	}
}e[M+5],E[M+5];
int ans=0;
int bz[K+5];
void solve2()
{
	int tot=m;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			e[++tot]={n+i,j,a[i][j]};
	sort(e+1,e+tot+1);
	int ans=LONG_LONG_MAX;
	for(int i=0;i<1<<k;i++)
	{
		for(int p=1;p<=n+k;p++)fa[p]=p;
		int res=0;
		int ll=0;
		for(int j=1;j<=k;j++)
		{
			bz[j]=0;
			if((i>>(j-1))&1)
			{
				ll++;
				res+=a[j][0];
				bz[j]=1;
			}
		}
		int cnt=0;
		for(int p=1;p<=tot;p++)
		{
			if(e[p].x>n&&!bz[e[p].x-n])continue;
			if(e[p].y>n&&!bz[e[p].y-n])continue;
			int x=find(e[p].x),y=find(e[p].y);
			if(x==y)continue;
			fa[x]=y;
			res+=e[p].w;
			cnt++;
			if(cnt==n+ll-1)break;
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		e[i].x=read(),e[i].y=read(),e[i].w=read();
		E[i]=e[i];
	}
	int tag=0;
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
		{
			a[i][j]=read();
			if(a[i][j]!=0)tag=1;
		}
	if(tag==0)
	{
		printf("0\n");
		return 0;
	}
	solve2();
	return 0;
} 
