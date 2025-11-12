#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		f=(ch=='-'?-1:f);
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
		return ;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
void writech(ll x,char ch)
{
	write(x);
	putchar(ch);
}
const int MAXM=2e6+10,MAXN=1e4+50;
struct edge{
	int u,v,w;
}e[MAXM],e1[20][MAXN];
int c[20],op[20],fa[MAXN],sz[MAXN],rmg[2000];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)return ;
	if(sz[x]<sz[y])
	{
		fa[x]=y;
		sz[y]+=sz[x];
	}
	else
	{
		fa[y]=x;
		sz[x]+=sz[y];
	}
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		e[i]={u,v,w};
	}
	sort(e+1,e+m+1,cmp);
	bool flag=0;
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		if(c[i]!=0)flag=1;
		bool now=0;
		for(int j=1;j<=n;j++)
		{
			int x=read();
			if(x==0)now=1;
			e1[i][j]={j,n+i,x};
		}
		if(now==0)flag=1;
	}
	if(k<=5)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				e[m+j+(i-1)*n]=e1[i][j];
			}
		}
		sort(e+1,e+m+k*n+1,cmp);
		int newm=m+k*n;
		ll ans=INF;
		for(int i=0;i<(1<<k);i++)
		{
			ll now=0;
			for(int j=0;j<k;j++)
			{
				if((i>>j)&1)
				{
					op[j+1]=1;
					now+=c[j+1];
				}
				else op[j+1]=0;
			}
			for(int j=1;j<=n+k;j++)
			{
				fa[j]=j;
			}
			for(int j=1;j<=newm;j++)
			{
				int u=e[j].u,v=e[j].v,w=e[j].w;
				if(v>n&&op[v-n]==0)continue;
				u=find(u),v=find(v);
				if(u==v)continue;
				merge(u,v);
				now+=w;
			}
			ans=min(ans,now);
		}
		writech(ans,'\n');
	}
	else if(!flag)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				e[m+j+(i-1)*n]=e1[i][j];
			}
		}
		sort(e+1,e+m+k*n+1,cmp);
		int newm=m+k*n;
		ll ans=INF;
		ll now=0;
		for(int j=0;j<k;j++)
		{
			op[j+1]=1;
			now+=c[j+1];
		}
		for(int j=1;j<=n+k;j++)
		{
			fa[j]=j;
		}
		for(int j=1;j<=newm;j++)
		{
			int u=e[j].u,v=e[j].v,w=e[j].w;
			if(v>n&&op[v-n]==0)continue;
			u=find(u),v=find(v);
			if(u==v)continue;
			merge(u,v);
			now+=w;
		}
		ans=min(ans,now);
		writech(ans,'\n');
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				e[m+j+(i-1)*n]=e1[i][j];
			}
		}
		sort(e+1,e+m+k*n+1,cmp);
		int newm=m+k*n;
		ll ans=INF;
		for(int i=0;i<(1<<k);i++)
		{
			rmg[i]=i;
		}
		mt19937 rng(time(0));
		shuffle(rmg,rmg+(1<<k),rng);
		for(int _=0;_<(1<<k);_++)
		{
			int i=rmg[_];
			ll now=0;
			for(int j=0;j<k;j++)
			{
				if((i>>j)&1)
				{
					op[j+1]=1;
					now+=c[j+1];
				}
				else op[j+1]=0;
			}
			for(int j=1;j<=n+k;j++)
			{
				fa[j]=j;
			}
			for(int j=1;j<=newm;j++)
			{
				int u=e[j].u,v=e[j].v,w=e[j].w;
				if(v>n&&op[v-n]==0)continue;
				u=find(u),v=find(v);
				if(u==v)continue;
				merge(u,v);
				now+=w;
				if(now>ans)break;
			}
			ans=min(ans,now);
		}
		writech(ans,'\n');
	}
	return 0;
}

