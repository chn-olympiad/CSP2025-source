#include<bits/stdc++.h>
using namespace std;
const int M = 1000005;
int n,m,k,tail,vis[M],cnt=1,total;
int dui[M*4],dis[M];
int head[M],nxt[M*2],to[M*2],pre[M*2],tot;
void add(int u,int v,int w)
{
	nxt[++tot]=head[u];
	head[u]=tot;
	to[tot]=v;
	pre[tot]=w;
}
struct fw{
	int a,b,c;
}f[1005];
int My_min(int x,int y)
{
	return x<y?x:y; 
}
int My_max(int x,int y)
{
	return x>y?x:y;
}
void shang(int id)
{
	while(dis[id/2]>dis[id]&&id!=1)
	{
		swap(dui[id/2],dui[id]);
		id/=2;
	}
}
void weihu(int id)
{
	while((dui[id]>dui[id*2]&&id*2<=tail)||(dui[id]>dui[id*2+1]&&id*2+1<=tail))
	{
		if(dui[id*2+1]<dui[id*2]&&id*2+1<=tail)
		{
			swap(dui[id*2+1],dui[id]);
			id=id*2+1;
		}
		else
		{
			swap(dui[id*2],dui[id]);
			id*=2;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);add(v,u,w);
	}
	for(int i=1;i<=n;i++)
	{
		dis[i]=1e9;
		dui[i]=i;
	} 
	vis[1]=1;
	dis[1]=0;
	tail=n;
	while(1)
	{
		cnt++;
		total+=dis[dui[1]];
		vis[dui[1]]=1;
		int u=dui[1];
		swap(dui[1],dui[tail]);
		tail--;
		if(cnt==n) break;
		weihu(1);
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			if(!vis[v]&&dis[v]>dis[u]+pre[i])
			{
				dis[v]=dis[u]+pre[i];
				shang(v);	
			}	
		}	
	}
	cout<<total;
	return 0;
} 
