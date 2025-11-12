#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') ret=(ret<<3)+(ret<<1)+c-'0',c=getchar();
	return ret;
}
int n,m,k,tot;
struct L
{
	int a,b,v;
}uu[1000010],u[10010],u0[100010];
bool cmp(L x,L y)
{
	return x.v<y.v;
}
int fa[10050];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int o[15][10010],w[15],tot0;
long long now,ans;
double t1,t2;
void dfs()
{
	for(int g=1;g<(1<<k);g++)
	{
		t2=clock();
		if(t2-t1>998) return;
		now=0,tot0=tot;
		int now0=0;
		for(int i=1;i<n;i++) u0[i]=u[i];
		for(int i=1;i<=k;i++)
		{
			if(g&(1<<i-1))
			{
				now+=w[i];
				for(int j=1;j<=n;j++)
				{
					u0[++tot0]={n+i,j,o[i][j]};
				} 
			} 
		}
		now0=now;
		memset(fa,0,sizeof(fa));
		for(int i=1;i<=n+k;i++) fa[i]=i;
		sort(u0+1,u0+tot0+1,cmp);
		for(int i=1;i<=tot0;i++)
		{
			if(find(u0[i].a)==find(u0[i].b)) continue;
			fa[fa[u0[i].b]]=fa[u0[i].a];
			now+=u0[i].v;
		}
		if(now<ans) ans=now;
	}
}
main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	t1=clock();
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		uu[i].a=read(),uu[i].b=read(),uu[i].v=read();
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(uu+1,uu+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(find(uu[i].a)==find(uu[i].b)) continue;
		fa[fa[uu[i].b]]=fa[uu[i].a];
		ans+=uu[i].v;
		u[++tot]=uu[i];
	}
	for(int i=1;i<=k;i++)
	{
		w[i]=read();
		for(int j=1;j<=n;j++) o[i][j]=read();
	}
	dfs();
	printf("%lld",ans);
//	cout<<endl<<t2-t1;
	return 0;
 } 

