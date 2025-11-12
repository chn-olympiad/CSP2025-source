#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
struct edge
{
	int v,w;
};
const int maxn=2e4+10,maxm=1e6+10;
int n,m,k,ans;
int c[maxn],from[maxn];
vector<edge> g[maxn];
bitset<maxn> vis,chk,vis2;
struct pri
{
	int from,id,val,w;
	bool operator <(const pri a) const
	{
		if(val+w==a.val+a.w) 
		{
			if(from==a.from) return id<a.id;
			return from<a.from;
		}
		return val+w>a.val+a.w;
	}
};
priority_queue<pri> q;
void prim()
{
	q.push({0,1,0,0});
	while(!q.empty())
	{
		if(k) if((chk&vis).count()==n+1) return;
		pri qnod=q.top(); q.pop();
		while(vis[qnod.id]) 
		{
			if(q.empty()) return ;
			qnod=q.top();
			q.pop();
		}
		vis[qnod.id]=1;
		ans+=qnod.w+qnod.val;
		if(qnod.id>n) 
		{
			vis2[qnod.id]=1;
			from[qnod.id]=qnod.w+qnod.val;
		}
		if(qnod.from>n) vis2[qnod.from]=0;
		for(auto &v:g[qnod.id])
		{
			if(vis[v.v]) continue;
			q.push({qnod.id,v.v,v.w,c[v.v]});
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(); m=read(); k=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		c[i+n]=read();
		for(int j=1;j<=n;j++)
		{
			int w=read();
			g[j].push_back({i+n,w});
			g[i+n].push_back({j,w});
		}
	}
	for(int i=0;i<=n;i++) chk[i]=1;
	vis[0]=1;
	prim();
	for(int i=n+1;i<=n+k;i++) if(vis2[i]) ans-=from[i];
	cout<<ans<<"\n";
}
//rp++
//finish 16:43