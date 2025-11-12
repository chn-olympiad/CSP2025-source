#include<bits/stdc++.h>
#define int long long
#define p pair<int,int>
using namespace std;
const int N=1e4+20;
const int INF=0x3f3f3f3f;
inline int read()
{
	int num=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') num=num*10+c-'0',c=getchar();
	return num*f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10),x%=10;
	putchar(x+'0');
}
int n,m,k,u,v,w,dis[N],c[N],a[N][N],ans;
bool vis[N];
vector<p >vc[N];
priority_queue<p,vector<p >,greater<p > >q;
inline void dij()
{
	memset(dis,INF,sizeof(dis));
	memset(vis,0,sizeof(vis));
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		u=read(),v=read(),w=read();
		vc[u].push_back(p{v,w});
		vc[v].push_back(p{u,w});
		ans+=w;
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
//	dij();
	write(ans);
	return 0;
}
