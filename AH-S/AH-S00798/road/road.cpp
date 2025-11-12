#include<bits/stdc++.h>
using namespace std;
struct node
{
	int u,v,w;
}b[1000005];
vector<node> a[1000005];
int c[10005],fa[10005],f[1005][1005];
int find(int x)
{
	if(fa[x]==x)
	return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	fa[x]=y;
}
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(k==0)
	{
	    for(int i=1;i<=m;i++)
	    {
		    int u,v,w;
		    u=read(),v=read(),w=read();
		    b[i].w=w;
		    b[i].u=u;
		    b[i].v=v;
	    }
		sort(b+1,b+m+1,cmp);
		int need=n-1,ans=0;
		for(int i=1;i<=n;i++)
		fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			if(need==0)
			break;
			int u=b[i].u;
			int v=b[i].v;
			int w=b[i].w;
			if(find(u)!=find(v))
			{
				merge(u,v);
				need--;
				ans+=w;
			}
		}
		cout<<ans<<endl;
	}
	if(k!=0)
	{
		int ta[10005];
		memset(ta,0,sizeof(ta));
		memset(b,0,sizeof(b));
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=m;i++)
		{
			int u=read(),v=read(),w=read();
			f[u][v]=f[v][u]=w;
		}
		for(int i=1;i<=k;i++)
		{
			memset(ta,0,sizeof(ta));
			c[i]=read();
			for(int j=1;j<=n;j++)
			ta[j]=read();
			for(int j=1;j<=n;j++)
			for(int k=j;k<=n;k++)
			{
				if(j==k)
				f[j][k]=0;
				f[j][k]=min(f[j][k],ta[j]+ta[k]);
				f[k][j]=f[j][k];
			}
		}
		m=0;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			b[++m].w=f[i][j];
			b[m].u=i;
			b[m].v=j;
		}
		sort(b+1,b+m+1,cmp);
		int anss=0;
		for(int i=1;i<=999;i++)
		anss+=b[i].w;
		cout<<anss<<endl;
		int need=n-1,ans=0;
		for(int i=1;i<=n;i++)
		fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			if(need==0)
			break;
			int u=b[i].u;
			int v=b[i].v;
			int w=b[i].w;
			if(find(u)!=find(v))
			{
				merge(u,v);
				need--;
				ans+=w;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 4 1
2 3 4
1 2 4
1 3 5
2 4 6
0 5 2 3 3
*/
