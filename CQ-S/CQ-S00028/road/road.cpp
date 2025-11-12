#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+(c^48);c=getchar();}
	return res*f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m,k;
int a[100005];
struct node
{
	int u,v,w,id;
	bool operator<(const node &a)const{return w<a.w;}
}e[1000005],tmp[100005];
int f[100005],siz[100005];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void init(){for(int i=1;i<=n+k;i++)f[i]=i,siz[i]=1;}
inline void merge(int fx,int fy)
{
	if(siz[fx]<siz[fy]) swap(fx,fy);
	f[fy]=fx;siz[fx]+=siz[fy];
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+m+1);
	init();int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy) continue;
		merge(fx,fy);tmp[++cnt]=e[i];
	}
	m=cnt;for(int i=1;i<=cnt;i++) e[i]=tmp[i];
	for(int i=1;i<=k;i++)
	{
		a[i]=read();
		for(int j=1;j<=n;j++)
		{
			int w=read();
			e[++m]=(node){j,n+i,w,i};
		}
	}
	sort(e+1,e+m+1);
	int ans=1e18;
	for(int s=0;s<(1<<k);s++)
	{
		int res=0;
		for(int i=1;i<=k;i++) if(s&(1<<i-1)) res+=a[i];
		init();
		int ct=0;
		int sz=n+__builtin_popcount(s);
		for(int i=1;i<=m;i++)
		{
			if(e[i].id&&!(s&(1<<e[i].id-1))) continue;
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx==fy) continue;
			merge(fx,fy);res+=e[i].w;
			++ct;if(ct==sz-1) break;
		}
		ans=min(ans,res);
	}
	write(ans);
	return 0;
}

