#include<algorithm>
#include<iostream>
#include<cstdio>
namespace io
{
	void read()
	{
		return;
	}
	template<typename nowtype,typename ...nexttype>
	void read(nowtype &now,nexttype &...next)
	{
		now=0;
		char c=getchar();
		bool sign(false);
#define isdigit(c) ((c)>='0'&&(c)<='9')
		while(!isdigit(c)){if(c=='-') sign=true;c=getchar();}
		while(isdigit(c)){now=(now<<1)+(now<<3)+(c^48);c=getchar();}
#undef isdigit
		if(sign) now=-now;
		read(next...);
	}
	template<typename nowtype>
	void write(nowtype now,char end='\n')
	{
		if(now<0) putchar('-');
		int c[40],top(0);
#define abs(x) ((x)<0?-(x):(x))
		do c[top++]=abs(now%10),now/=10;while(now);
#undef abs
		while(top) putchar(c[--top]+48);
		putchar(end);
	}
	template<typename nowtype,typename ...nexttype>
	void write(nowtype now,char sep,nexttype ...next)
	{
		if(now<0) putchar('-');
		int c[40],top(0);
#define abs(x) ((x)<0?-(x):(x))
		do c[top++]=abs(now%10),now/=10;while(now);
#undef abs
		while(top) putchar(c[--top]+48);
		putchar(sep);
		write(next...);
	}
}
using namespace io;
namespace Sol
{
	typedef long long ll;
	typedef unsigned long long ull;
	const int const1=1e6+20;
	struct edges
	{
		int next,from,to,cost;
	}edge[const1*3];
	int n,m,k,Head[const1],f[const1],c[12],a[12][const1],cnt;
	std::vector<edges> ed;
	bool cmp(edges x,edges y)
	{
		return x.cost<y.cost;
	}
	void AddEdge(int from,int to,int cost)
	{
		edge[++cnt].to=to;
		edge[cnt].from=from;
		edge[cnt].cost=cost;
		edge[cnt].next=Head[from];
		Head[from]=cnt;
	}
	int find(int x)
	{
		if(f[x]!=x) f[x]=find(f[x]);
		return f[x];
	}
	void merge(int x,int y)
	{
		int fx=find(x),fy=find(y);
		f[fx]=fy;
	}
	ll kurskal()
	{
		int i,ss(0);
		ll ans(0);
		std::sort(edge+1,edge+cnt+1,cmp);
		for(i=1;i<=n+k;++i) f[i]=i;
		for(i=1;i<=cnt;++i)
		{
			for(int j=1;j<=n+k;++j) f[j]=find(f[j]);
			if(ss>n+k-1) break;
			if(find(edge[i].from)==find(edge[i].to)) continue;
			++ss;
			merge(edge[i].from,edge[i].to);
			if(edge[i].from>n||edge[i].to>n) ed.push_back(edge[i]);
			if(edge[i].from>n) ++c[edge[i].from-n];
			if(edge[i].to>n) ++c[edge[i].to-n];
			ans+=edge[i].cost;
		}
		for(auto it:ed)
		{
			if(it.from>n&&c[it.from]==1) ans-=it.cost;
			if(it.to>n&&c[it.to]==1) ans-=it.cost;
		}
		return ans;
	}
	void solve()
	{
		int i,j,u,v,w;
		bool zero(true);
		read(n,m,k);
		putchar('!');
		for(i=1;i<=m;++i)
		{
			read(u,v,w);
			AddEdge(u,v,w);
		}
		for(i=1;i<=k;++i)
		{
			read(c[i]);
			if(c[i]) zero=false;
			for(j=1;j<=n;++j)
			{
				read(a[i][j]);
				AddEdge(i+n,j,a[i][j]);
			}
		}
		write(kurskal());
		return;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Sol::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
