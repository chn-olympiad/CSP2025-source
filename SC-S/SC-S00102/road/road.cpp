#include<cstdio>
#include<bitset>
#include<algorithm>
namespace IO
{
	char in[1<<20];
	int maxp=0,idx=-1;
	char gc()
	{
		if(idx==-1)
		{
			maxp=fread(in,1,1<<20,stdin);
		}
		if(idx==maxp-1)
		{
			idx=-1;
			return in[maxp-1];
		}
		return in[++idx];
	}
}
template<typename T>
void read(T &x)
{
	char c=IO::gc();x=0;
	while(c<'0'||c>'9')c=IO::gc();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=IO::gc();
}
template<typename T>
void write(T x)
{
	static char c[70];
	int len=0;
	while(x)
	{
		c[++len]=x%10|48;
		x/=10;
	}
	for(int i=len;i>=0;--i)
	{
		putchar(c[i]);
	}
}
struct edge
{
	int u,v;
	long long w;
}g[1000005],e[10005],gragh[110005];
long long v[15][10005];
int n,m,k,f[10015],lene=0;
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
long long kruskal()
{
	std::sort(g+1,g+1+m,[](edge x,edge y){return x.w<y.w;});
	for(int i=1;i<=n;++i)f[i]=i;
	long long ans=0;
	for(int i=1,cnt=0;i<=m&&cnt<n-1;++i)
	{
		if(find(g[i].u)!=find(g[i].v))
		{
			f[find(g[i].u)]=find(g[i].v);
			++cnt;
			e[++lene]=g[i];
			ans+=g[i].w;
		}
	}
	return ans;
}
long long ans;
void dfs(int i,long long val,std::bitset<15> vis)
{
	if(i<=k)
	{
		dfs(i+1,val,vis);
		vis[i]=1;
		dfs(i+1,val+v[i][0],vis);
	}
	else
	{
		int leng=lene,point=n;
		for(int i=1;i<=lene;++i)
		{
			gragh[i]=e[i];
		}
		for(int i=1;i<=k;++i)
		{
			if(vis[i])
			{
				++point;
				for(int j=1;j<=n;++j)
				{
					gragh[++leng]={point,j,v[i][j]};
				}
			}
		}
		for(int i=1;i<=point;++i)f[i]=i;
		std::sort(gragh+1,gragh+1+leng,[](edge x,edge y){return x.w<y.w;});
		for(int i=1,cnt=0;i<=leng&&cnt<point-1;++i)
		{
			if(find(gragh[i].u)!=find(gragh[i].v))
			{
				f[find(gragh[i].u)]=find(gragh[i].v);
				++cnt;
				val+=gragh[i].w;
			}
		}
		if(ans>val)
		{
			ans=val;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;++i)
	{
		read(g[i].u),read(g[i].v),read(g[i].w);
	}
	ans=kruskal();
	if(k==0)
	{
		write(ans);
		return 0;
	}
	for(int i=1;i<=k;++i)
	{
		bool f=1;
		read(v[i][0]);
		for(int j=1;j<=n;++j)
		{
			read(v[i][j]);
			if(v[i][j])f=0;
		}
		if(f)
		{
			putchar('0');
			return 0;
		}
	}
	std::bitset<15> vis(0);
	dfs(1,0,vis);
	write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}