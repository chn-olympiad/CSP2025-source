#include<bits/stdc++.h>
using namespace std;
const int M=1e6+7;
const int N=1e4+7;
int n,m,k,now;
int c[N],fa[N];
bool vis[N];
struct road
{
	int u,v,w;
	bool operator < (const road& TT) const 
	{
		return TT.w<w;
	}
};
priority_queue<road>e[2];
int read()
{
	char c;
	c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	int k=0;
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return k;
}
void out(int x)
{
	if(x<10)
	{
		putchar('0'+x);
		return ;
	}
	out(x/10),putchar(x%10+'0');
}
void add(int u,int v,int w)
{
	e[0].push((road){u,v,w});
}
int find(int x)
{
	if(x==fa[x])
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
int kruskal(int tmp111)
{
	int ans=0;
	while(!e[now].empty())
	{
		road tmp=e[now].top();
		e[now^1].push(tmp);
		e[now].pop();
		int u=tmp.u,v=tmp.v,w=tmp.w;
		if(find(u)==find(v))
		{
			continue;
		}
		if(u>n&&!vis[u])
		{
			continue;
		}
		if(v>n&&!vis[v])
		{
			continue;
		}
		fa[find(u)]=find(v);
		ans+=w;
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1,u,v,w;i<=m;i++)
	{
		u=read(),v=read(),w=read();
		add(u,v,w);
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1,kk;j<=n;j++)
		{
			kk=read();
			add(i+n,j,kk);
		}
	}
	int rec=1e9;
	for(int i=0;i<=((1<<k)-1);i++)
	{
		int tmp=i,ans=0;
		for(int j=1;j<=n+k;j++)
		{
			fa[j]=j;
			vis[j]=false;
		}
		for(int j=0;j<k;j++)
		{
			if(tmp&(1<<j))
			{
				ans+=c[j+1];
				vis[j+1+n]=true;
			}
		}
		rec=min(rec,ans+kruskal(tmp));
		now^=1;
	}
	cout<<rec;
	return 0;
}
