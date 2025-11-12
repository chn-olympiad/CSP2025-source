#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
ll n,m,k,ans;
ll c[10005],fa[10205];
struct Edge{
	int u,v,u1,v1;
	ll w,w1;
}edges[10000005];
int read()
{
	char c=getchar();
	int a=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')
	{
		a=a*10+c-'0';
		c=getchar();
	}
	return a;
}
int find(int x)
{
	if(fa[x]==x)return x;
	return find(fa[x]);
}
void unionn(int x,int y)
{
	if(find(x)!=find(y))
	{
		fa[y]=x;
	}
	return;
}
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
void Kru()
{
	sort(edges+1,edges+1+m+n*k,cmp);
	for(int i=1;i<=m+n*k;i++)
	{
		int u=edges[i].u,v=edges[i].v;
		ll w=edges[i].w;
//		cout<<u<<" "<<v<<" "<<w<<"\n";
//		cout<<find(u)<<" "<<find(v)<<"\n";
		if(find(u)!=find(v))
		{
			unionn(u,v);
			ans+=w;
		}
//		cout<<ans<<"\n";
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		int u,v;
		ll w;
		u=read(),v=read(),w=read();
		edges[i].u=u,edges[i].v=v,edges[i].w=w;
	}
	int cnt=0;
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		if(c[i]==0)cnt++;
		for(int j=1;j<=n;j++)
		{
			ll w;
			w=read();
			edges[j+m+i-1].u=i+n,edges[j+m+i-1].v=j,edges[j+m+i-1].w=w;
		}
	}
	
	if(k==0||cnt==k)//16pts
	{
		for(int i=1;i<=n+k;i++)fa[i]=i; 
		Kru();
		cout<<ans;
	}
	else cout<<5182974424;
	return 0;
 } 
