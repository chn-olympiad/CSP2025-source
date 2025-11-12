#include<bits/stdc++.h>
using namespace std;
const int MAXM=2000010,MAXN=20010;
int n,m,k,c[MAXN];
struct edge
{
	int u,v,w;
}e[MAXM];
int f[MAXN];
bool cmp(edge a,edge b)
{
	if(a.u>n)return a.w+c[a.u]<b.w;
	return a.w<b.w;
}
int find(int i)
{
	if(f[i]==i)return i;
	return f[i]=find(f[i]);
}
bool becity[MAXN],vis[MAXN];
bool check()
{
	for(int i=1;i<=n;i++)
		if(!vis[i])return 0;
	return 1;
}
int kruscal()
{
	sort(e+1,e+1+m,cmp);
	int len=0,cnt=0;
	for(int i=1;i<=m;i++) 
	{
		int u=e[i].u,v=e[i].v;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		if(u>n)//is village
		{
			if(becity[u])len+=e[i].w,f[fv]=fu;
			else len+=e[i].w+c[u],becity[u]=1,f[fv]=fu;
		}
		else//is city
			len+=e[i].w,f[fv]=fu;
		vis[u]=1,vis[v]=1;
		if(check())return len;
	}
	return -1;
}
int main()
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	//ovo qwq awa
	//我要上迷惑行为大赏 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i+n];
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			e[++m]={i+n,j,w};
		}
	}
	cout<<kruscal();
	return 0;
}
