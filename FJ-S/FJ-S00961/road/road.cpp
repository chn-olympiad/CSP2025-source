#include <bits/stdc++.h>
#define fi first
#define se second
#define mk(x,y) (make_pair(x,y))
#define ll long long
using namespace std;
const int N=2e4+100;
const int M=2e6+100;
int n,m,k;
int tot;
int c[N];
pair<int,pair<int,int>> f[M],g[M];
void read(int &v)
{
	v=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		v=v*10+ch-48;
		ch=getchar();
	}
}
int fa[N],siz[N];
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
bool merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)
		return 0;
	if(siz[fx]<siz[fy])
	{
		swap(fx,fy); 
	}
	fa[fy]=fx;
	siz[fx]+=siz[fy];
	return 1;
}
void init()
{
	for(int i=1;i<=n+k;++i)
	{
		fa[i]=i;
		siz[i]=1;
	}
}
void get_g()
{
	sort(f+1,f+m+1);
	init();
	for(int i=1;i<=m;++i)
	{
		if(merge(f[i].se.fi,f[i].se.se))
		{
			g[++tot]=f[i];
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	for(int i=1;i<=m;++i)
	{
		read(f[i].se.fi);
		read(f[i].se.se);
		read(f[i].fi);
	}
	get_g();
	for(int i=1;i<=k;++i)
	{
		read(c[i]);
		for(int j=1;j<=n;++j)
		{
			++tot;
			g[tot].se.fi=n+i;
			g[tot].se.se=j;
			read(g[tot].fi);
		}
	}
	sort(g+1,g+tot+1);
	ll ans=0x3f3f3f3f3f3f3f3f;
	for(int o=0;o<(1<<k);++o)
	{
		ll res=0;
		for(int i=0;i<k;++i)
		{
			if(o&(1<<i))
			{
				res+=c[i+1];
			}
		}
		init();
		for(int i=1;i<=tot;++i)
		{
			//cout<<"p"<<g[i].se.fi<<" "<<g[i].se.se<<" "<<(1<<(g[i].se.fi-1))<<'\n';
			if(g[i].se.fi>n&&!(o&(1<<(g[i].se.fi-1-n))))
				continue ;
			//	cout<<"p"<<g[i].se.fi<<" "<<g[i].se.se<<'\n';
			if(merge(g[i].se.fi,g[i].se.se))
			{
				//if(o==1)
				//cout<<g[i].se.fi<<" "<<g[i].se.se<<'\n';
				res+=g[i].fi;
			}
		}
		ans=min(ans,res);
		//cout<<o<<" "<<res<<'\n';
	}
	printf("%lld\n",ans);
	return 0;
}













