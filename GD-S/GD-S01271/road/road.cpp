#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
int in()
{
	int ans=0,ff=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
	{
		if(c=='-')
		{
			ff*=-1;
		}
	}
	for(;isdigit(c);c=getchar())
	{
		ans=ans*10+c-'0';
	}
	return ans*ff;
}
void out(int x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x>=10)
	{
		out(x/10);
	}
	putchar(x%10+'0');
}
int n,m,k;
int cost[20];
int a[N][20];
bool st[N][20];
struct rode
{
	int u,v,w;
}rd[M];
int p[M];
int find(int x)
{
	if(x!=p[x])
	{
		p[x]=find(p[x]);
	}
	return p[x];
}
bool cmp(rode x,rode y)
{
	return x.w<y.w;
}
bool fg1;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(st,0,sizeof st);
	n=in(),m=in(),k=in();
	for(int i=1;i<=m;i++)
	{
		rd[i].u=in(),rd[i].v=in(),rd[i].w=in();
	}
	for(int i=1;i<=n+k;i++)
	{
		p[i]=i;
	}
	for(int i=1;i<=k;i++)
	{
		cost[i]=in();
		if(cost[i]!=0)
		{
			fg1=1;
		}
		for(int j=1;j<=n;j++)
		{
			a[j][i]=in();
			if(a[j][i]==0)
			{
				st[j][i]=1;
				p[find(j)]=find(i+n);
			}
		}
	}
	if(k==0)
	{
		int ans=0;
		sort(rd+1,rd+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			int x=rd[i].u,y=rd[i].v,z=rd[i].w;
			if(find(x)!=find(y))
			{
				p[find(x)]=find(y);
				ans+=z;
			}
		}
		out(ans);
	}
	else if(!fg1)
	{
		int ans=0;
		sort(rd+1,rd+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			int x=rd[i].u,y=rd[i].v,z=rd[i].w;
			if(find(x)!=find(y))
			{
				int ct=z;
				for(int j=1;j<=k;j++)
				{
					if(st[x][j])
					{
						if(a[y][j]<=ct)
						{
							ct=a[y][j];
							st[y][j]=1;
						} 
					}
					else if(st[y][j])
					{
						if(a[x][j]<=ct)
						{
							ct=a[x][j];
							st[x][j]=1;
						} 
					}
					else
					{
						if(a[x][j]+a[y][j]<=ct)
						{
							ct=a[x][j]+a[y][j];
							st[x][j]=1;
							st[y][j]=1;
						}
					}
				}
				p[find(x)]=find(y);
				ans+=ct;
			}
		}
		out(ans);
	}
	return 0;
}

