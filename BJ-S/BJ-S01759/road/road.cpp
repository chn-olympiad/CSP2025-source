#include <bits/stdc++.h>
using namespace std;

char ch;
int ret;
int read()
{
	ch=getchar_unlocked();
	ret=0;
	while(ch<'0' || ch>'9') ch=getchar_unlocked();
	while(ch>='0' && ch<='9')
	{
		ret=ret*10+ch-'0';
		ch=getchar_unlocked();
	}
	return ret;
}

struct city
{
	struct ed
	{int v,w;};
	struct edge
	{
		int u,v,w;
		edge(){u=v=w=0;}
		edge(int _u,int _v,int _w) {u=_u;v=_v;w=_w;}
		edge& operator=(edge y)
		{
			u=y.u;
			v=y.v;
			w=y.w;
			return *this;
		}
		bool operator>(const edge& y) const
		{return w>y.w;}
	};
	int n,m,k;
	vector<ed> vec[10010];
	int a[10010][12], c[12];
	city() {n=m=0;}
	city(bool input)
	{
		int u,v,w;
		n=read(); m=read(); k=read();
		for(int i=1;i<=m;++i)
		{
			u=read(); v=read(); w=read();
			vec[u].push_back({v,w});
			vec[v].push_back({u,w});
		}
		for(int i=1;i<=k;++i)
		{
			c[i]=read();
			for(int j=1;j<=n;++j)
				a[j][i]=read();
		}
	}
	struct Dset
	{
		int fa[10010];
		Dset(){memset(fa,0,sizeof fa);}
		Dset(int __n)
		{for(int i=1;i<=__n;++i) fa[i]=i;}
		int find(int x)
		{
			if(fa[x]==x) return x;
			return fa[x]=find(fa[x]);
		}
		void merge(int x,int y)
		{
			x=find(x); y=find(y);
			if(x!=y) fa[y]=x;
		}
		bool check(int x,int y){return find(x)==find(y);}
	};
	int now=n;
	long long prim()
	{
		long long sum=0;
		Dset st(now);
		priority_queue<edge,vector<edge>,greater<edge> > q;
		for(ed e:vec[1])
		{
			q.push(edge(1,e.v,e.w));
			//cout<<'*'<<1<<' '<<e.v<<':'<<e.w<<'\n';
		}
		edge e=q.top();
		q.pop();
		for(int i=1;i<now;++i)
		{
			while(st.check(e.u,e.v) && !q.empty()) e=q.top(), q.pop();
			if(q.empty() && st.check(e.u,e.v)) return 1000000000000000000ll;
			//cout<<e.u<<' '<<e.v<<':'<<e.w<<'\n';
			st.merge(e.u,e.v);
			sum+=e.w;
			for(ed ee:vec[e.v])
			{
				if(!st.check(e.v,ee.v)) q.push({e.v,ee.v,ee.w});
			}
		}
		return sum;
	}
	long long solve()
	{
		long long ret=1000000000000000000ll, sum=0;
		for(int S=0;S<=(1<<k)-1;++S)
		{
			sum=0;
			now=n;
			for(int i=0;i<k;++i)
			{
				if((S>>i)&1)
				{
					sum+=c[i+1];
					++now;
					for(int j=1;j<=n;++j)
					{
						vec[j].push_back({n+i+1,a[j][i+1]});
						vec[n+i+1].push_back({j,a[j][i+1]});
					}
				}
			}
			//long long tmp=prim();
			//cout<<'%'<<sum<<','<<tmp<<endl;
			ret=min(ret,sum+prim());
			for(int i=0;i<k;++i)
			{
				if((S>>i)&1)
				{
					for(int j=1;j<=n;++j)
					{
						vec[j].pop_back();
						vec[n+i+1].pop_back();
					}
				}
			}
		}
		return ret;
	}
};

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	city cit(1);
	printf("%lld",cit.solve());
	return 0;
}
