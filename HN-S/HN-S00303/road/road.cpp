#include<bits/stdc++.h>
#define maxn 10005
#define maxm 1000006
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
int n,m,k,ans = inf,c[10];
struct edge{int u,v,w,id;}e[maxm],a[maxn*10],b[maxn];
inline int read()
{
	int x = 0,f = 1;char ch = getchar();
	while(ch<'0'||ch>'9')f = ch == '-'?-f:f,ch = getchar();
	while(ch>='0'&&ch<='9')x = (x<<3)+(x<<1)+(ch^'0'),ch = getchar();
	return x*f;
}
inline void write(int x)
{
	if(x<0)x = -x,putchar('-');
	static char sta[30];int top = 0;
	do sta[top++] = x%10,x/=10;while(x);
	while(top)putchar(sta[--top]^'0');
	putchar('\n');
}
inline bool cmp(edge&x,edge&y){return x.w<y.w;}
namespace dsu
{
	int fa[maxn],size[maxn];
	inline int find(int u){return u == fa[u]?u:fa[u] = find(fa[u]);}
	inline bool merge(int u,int v)
	{
		u = find(u),v = find(v);
		if(u == v)return false;
		if(size[u]>size[v])u^=v^=u^=v;
		fa[u] = v,size[v]+=size[u];
		return true;
	}
	inline void build(){for(int i = 1;i<=n+k;++i)size[i] = 1,fa[i] = i;}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(),m = read(),k = read();
	for(int i = 1;i<=m;++i)
		e[i] = {read(),read(),read()};
	std::sort(e+1,e+1+m,cmp);
	for(int i = 0;i<k;++i)
	{
		c[i] = read();
		for(int j = 1;j<=n;++j) 
			a[i*n+j] = {n+i+1,j,read(),i};
	}
	dsu::build();
	for(int i = 1,cnt = 0;i<=m&&cnt<n-1;++i)
		if(dsu::merge(e[i].u,e[i].v))b[++cnt] = e[i];
	std::sort(a+1,a+1+n*k,cmp);
	for(int s = 0,now,pc;s<(1<<k);++s)
	{
		dsu::build(),now = pc = 0;
		for(int i = 0;i<k;++i)if(s>>i&1)now+=c[i],++pc;
//		printf("%d %d\n",s,now);
		for(int i = 1,j = 1,cnt = 0;i<n&&cnt<n+pc-1;++i)
		{
			while(a[j].w<b[i].w)
			{
				if(s>>a[j].id&1&&dsu::merge(a[j].u,a[j].v))
					now+=a[j].w,++cnt;
				++j;
			}
			if(dsu::merge(b[i].u,b[i].v))now+=b[i].w,++cnt;
		}
//		printf("%d %d\n",s,now);
		ans = std::min(ans,now); 
	}
	write(ans);
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4

