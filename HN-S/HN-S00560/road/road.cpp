#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=1e6+5,K=12;
int n,m,k,b;
ll ans=LONG_LONG_MAX;
int c[K],a[K][N],vis[K];
int fa[N];
struct edge
{
	int u,v,w,id;
};
vector<edge>e;
inline int input()
{
	char ch=getchar();
	int res=0;
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return res;
}
inline bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
inline int find(int x)
{
	if(fa[x]==x)
		return x;
	return (fa[x]=find(fa[x]));
}
inline int merge(int x,int y,int v)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)
		return 0;
	fa[fx]=fy;
	return v;
}
inline ll kru()
{
	int res=0;
	for(register int i=1;i<=n;++i)
		fa[i]=i;
	for(register int i=0;i<e.size();++i)
	{
		if(!vis[e[i].id])
			continue;
		res+=merge(e[i].u,e[i].v,e[i].w);
	}
	return res;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=input();
	m=input();
	k=input();
	b=1<<k;
	for(register int i=1;i<=m;++i)
	{
		edge x;
		x.u=input();
		x.v=input();
		x.w=input();
		x.id=1;
		e.push_back(x);
	}
	sort(e.begin(),e.end(),cmp);
	for(int i=1;i<=n;++i)
		fa[i]=i;
	for(register int i=0;i<e.size();++i)
	{
		if(find(e[i].u)!=find(e[i].v))
			e[i].id=0;
		merge(e[i].u,e[i].v,1);
	}
	vector<edge>e1;
	e1.clear();
	for(register int i=0;i<e.size();++i)
		if(!e[i].id)
			e1.push_back(e[i]);
	e.clear();
	for(register int i=0;i<e1.size();++i)
		e.push_back(e1[i]);
	for(register int i=1;i<=k;++i)
	{
		c[i]=input();
		for(register int j=1;j<=n;++j)
		{
			edge x;
			x.w=input();
			x.u=j;
			x.v=i+n;
			x.id=i;
			e.push_back(x);
		}
	}
	sort(e.begin(),e.end(),cmp);
	for(register int i=0;i<b;++i)
	{
		ll res=0;
		memset(vis,0,sizeof vis);
		vis[0]=1;
		for(register int j=0;j<k;++j)
		{
			if(((1<<j)&i))
			{
				vis[j+1]=1;
				res+=c[j+1];
			}
		}
		res+=kru();
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
