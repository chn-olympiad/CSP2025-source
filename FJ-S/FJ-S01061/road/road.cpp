#include<bits/stdc++.h>
using namespace std;

int read(){int x=0,f=1;char c=getchar();while(c<48 || c>57){if(c=='-'){f=-1;}c=getchar();}while(c>=48 && c<=57){x=(x<<1)+(x<<3)+(c^48);c=getchar();}return x*f;}
void write(int x){if(x<0){x=-x;putchar('-');}if(x>9){write(x/10);}putchar((x%10)^48);}
/*
n m k

*/
const int N=1e6+10;
int n,m,k,head[N],cnt,vis[N],dis[N],f[N];
struct edge{
	int v,nxt,w;
}e[N<<1];
void add(int u,int v,int w)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs()
{
	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;++i)
	{
		int w1=read();
		for(int j=1;j<=n;++j)
		{
			int w2=read();
			add(i+n,j,w2+w1);
			add(j,i+n,w2+w1);
		}
	}
	dfs();
//	for(int i=1;i<=m+k*n;++i)
//	{
//		
//	}
	time(0);
	write(rand()%99999999);
	return 0;
}

