#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int K=15;
int fa[N];
int d[K],c[K][N];
inline int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
struct edge
{
	int u,v,w;
};
vector <edge> fe;
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
inline int read()
{
	char ch=getchar();
	int x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	} 
	return x;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	n=read(),m=read(),k=read();
	fe.reserve(m+n*k+1);
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		u=read(),v=read(),w=read();
		fe.push_back({u,v,w});
	}
	int x;
	for(int i=1;i<=k;i++)
	{
		x=read();
		for(int j=1;j<=n;j++)
		{
			c[i][j]=read();
			if(c[i][j]==0) d[i]=j;
			if(d[i]!=0) fe.push_back({d[i],j,c[i][j]});
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<d[i];j++)
		{
			fe.push_back({d[i],j,c[i][j]});
		}
	}
	long long ans=0;
	int cnt=0;
	sort(fe.begin(),fe.end(),cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	int len=fe.size();
	for(int j=0;j<len;j++)
	{
		u=fe[j].u,v=fe[j].v,w=fe[j].w;
		u=find(u),v=find(v);
		if(u==v) continue;
		fa[u]=v;
		cnt++;
		ans+=w;
		if(cnt==n-1) 
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}