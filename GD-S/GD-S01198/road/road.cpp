#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
typedef long long ll;
int n,m,k,cnt;
bool f;
struct side
{
	int u,v,w;
}p[M];
bool cmp(side a,side b)
{
	return a.w<b.w;
} 
struct unionfound
{
	int fa[N];
	void init()
	{
		for(int i=1;i<=n;i++)
			fa[i]=i;
	}
	int find(int x)
	{
		if(fa[x]!=x)
			fa[x]=find(fa[x]);
		return fa[x];
	}
	bool unite(int x,int y)
	{
		int root_x=find(x),root_y=find(y);
		if(root_x==root_y)
			return false;
		fa[root_y]=root_x;
		return true;
	}
};
int kruskal()
{
	unionfound uf;
	uf.init();
	int cs=0,ans=0;
	if(f)
		for(int i=m-cnt+1;i<=m;i++)
			if(uf.unite(p[i].u,p[i].v))
				cs++;
	sort(p+1,p+1+m,cmp); 
	for(int i=1;i<=m;i++)
	{
		if(uf.unite(p[i].u,p[i].v))
		{
			cs++;
			ans+=p[i].w;	
		}
		if(cs>n)
			break;
	}
	 
	return ans;
} 
int a[N];  
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>p[i].u>>p[i].v>>p[i].w;
	f=true;
	for(int i=1,c;i<=k;i++)
	{	
		cin>>c;
		if(c!=0)
			f=false;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			for(int j=1;j<i;j++)
				p[++m]={i,j,a[i]+a[j]+c},cnt++;
		}
	}
	cout<<kruskal();
	return 0;
} 
