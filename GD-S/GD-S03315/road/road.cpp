#include<bits/stdc++.h>
#define ______ namespace
#define _______ std
using ______ _______;
int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
using ll=long long;
const int mxn=2e6+5;
struct edge
{
	int x,y,v;
	friend bool operator <(const edge &x,const edge &y)
	{
		return x.v<y.v;
	}
}a[mxn];
int cnt;
int f[mxn];
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
int c[mxn];
int n,m,k;
vector<edge> v[15];
vector<edge> mst(vector<edge> tp)
{
	for(int i=1;i<=n+k;i++)
		f[i]=i;
	vector<edge> res;
	for(auto e:tp)
	{
		int x=find(e.x),y=find(e.y);
		if(x==y) continue;
		f[x]=y;
		res.push_back(e);
	}
	return res;
}
ll ans=1e18;
void dfs(int d,vector<edge> mst,ll s)
{
	if(d>k)
	{
		for(auto x:mst)
			s+=x.v;
		ans=min(ans,s);
		return;
	}
	dfs(d+1,mst,s);
	vector<edge> tp(mst.size()+n);
	merge(mst.begin(),mst.end(),v[d].begin(),v[d].end(),tp.begin());
	dfs(d+1,::mst(tp),s+c[d]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	int i,j;
	vector<edge> tp;
	while(m--)
	{
		int x=read(),y=read(),v=read();
		tp.push_back({x,y,v});
	}
	sort(tp.begin(),tp.end());
	tp=mst(tp);
	for(i=1;i<=k;i++)
	{
		c[i]=read();
		for(j=1;j<=n;j++)
			v[i].push_back({n+i,j,read()});
		sort(v[i].begin(),v[i].end());
	}
	dfs(1,tp,0);
	cout<<ans;
}
