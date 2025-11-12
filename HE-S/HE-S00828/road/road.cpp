#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
	int x=0,c=getchar(),f=0;
	for(;c<'0'||c>'9';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c-'0');
	return f?-x:x;
}

inline void write(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int inf=1e17;
int sta[20];
int c[20];
int b[20][10005];
int n,m,k;
int ans=inf;
struct Node{
	int u,v,w;
}a[2<<20],d[100005];
int tot;
bool cmp(Node x,Node y) { return x.w<y.w; }

int f[10050];
int find(int x) 
{ 
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
bitset<32> vis;
void solve(int cnt)
{
	int nw=0;
	for(int i=1;i<=k;i++) vis[i]=0;
	for(int i=1;i<=cnt;i++)
	vis[sta[i]]=1,nw+=c[sta[i]];

	for(int i=1;i<=n+k;i++) f[i]=i;
	int p1=1,p2=1;
	int siz=1;
	while(siz<n+cnt)
	{
		while(p1<=m&&find(a[p1].u)==find(a[p1].v)) p1++;
		while(p2<=tot&&(!vis[d[p2].u-n]||find(d[p2].u)==find(d[p2].v))) p2++;
		siz++;
		if(a[p1].w<d[p2].w)
		{
			// cout<<a[p1].u<<" -> "<<a[p1].v<<"\n";
			nw+=a[p1].w;
			f[find(a[p1].u)]=find(a[p1].v);
			p1++;
		}
		else 
		{
			// cout<<d[p2].u<<" -> "<<d[p2].v<<"\n";

			nw+=d[p2].w;
			f[find(d[p2].u)]=find(d[p2].v);
			p2++;
		}
	}
	ans=min(ans,nw);
	// cout<<cnt<<" "<<nw<<"\n";
}

void dfs(int p,int cnt)
{
	if(p>k) { solve(cnt); return; }
	dfs(p+1,cnt);
	sta[cnt+1]=p;
	dfs(p+1,cnt+1);
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++)
	{
		a[i].u=read();
		a[i].v=read();
		a[i].w=read();
	}
	sort(a+1,a+1+m,cmp);
	a[m+1].w=inf;
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++) 
		{
			b[i][j]=read();
			d[++tot]={i+n,j,b[i][j]};
		}
	}
	d[tot+1].w=inf;
	sort(d+1,d+1+tot,cmp);
	dfs(1,0);
	cout<<ans;

	return 0;
}