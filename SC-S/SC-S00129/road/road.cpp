#include<bits/stdc++.h>
#define int long long
using namespace std;
#define pc putchar
#define we(x) (write(x),pc('\n'))
#define ws(x) (write(x),pc(' '))
#define rep(i,x,y) for(int i=x;i<=y;i++)
const int N=2e5,M=4e6,mod=998244353;
inline void read(int &x)
{
	x=0;
	register char ch;
	while((ch=getchar())<'0'||ch>'9');
	do
	{
		x=(x<<1)+(x<<3)+ch-'0';
	}while((ch=getchar())>='0'&&ch<='9');
}
inline void write(int x)
{
	if(x==0)
	{
		pc('0');
		return;
	}
	if(x>=10)write(x/10);
	pc(x%10+'0');
}
struct forward
{
	int v,w,nxt;
};
int a[15][N+5],head[N+5],fa[N+5],c[N+5],tot;
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
struct node
{
	int u,v,w;
}t[M+5],g[M+5];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int dp[N+5][(1<<10)+5],cnt[N+5];
vector<node>gt;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	read(n),read(m),read(k);
	rep(i,1,m)
	{
		int u,v,w;
		read(u),read(v),read(w);
		t[++tot]={u,v,w};
		g[tot]={u,v,w};
		head[u]=tot;
	}
	int flag=1,tot2=tot;
	rep(i,1,k)
	{
		read(c[i]);
		if(c[i]!=0)flag=0;
		rep(j,1,n)read(a[i][j]),t[++tot2]={n+i,j,a[i][j]};
	}
	if(flag)
	{
		sort(t+1,t+1+tot2,cmp);
		int tt=0;
		long long ans=0;
		rep(i,1,n+k)fa[i]=i;
		rep(i,1,tot2)
		{
			int fu=find(t[i].u),fv=find(t[i].v);
			if(fu!=fv)
			{
				fa[fu]=fv;
				++tt;
				ans+=t[i].w;
			}
			if(tt==n+k-1)break;
		}
		we(ans);
		return 0;
	}
	long long rr=1e18;
	rep(i,0,(1<<k)-1)
	{
		//cout<<"ff"<<i<<endl;
		long long ans=0;
		int tt=0,ttt=0,now=0;
		rep(j,0,k-1)
			if((i>>j)&1)
			{
				++ttt;
				rep(l,1,n)
				{
					++now;
					g[m+now]={n+j+1,l,a[j+1][l]};
				}
				ans+=c[j+1];
			}
		//cout<<m+now<<endl;
		sort(g+1,g+1+m+now,cmp);
		rep(j,1,n+k)fa[j]=j,cnt[j]=0;
		rep(j,1,m+now)
		{
			int fu=find(g[j].u),fv=find(g[j].v);
		//	ws(g[j].u),ws(g[j].v),we(g[j].w);
			if(fu!=fv)
			{
				fa[fu]=fv;
				if(g[j].u<=n)++tt;
			//	we(gt[i].w);
				ans+=g[j].w;
			//	cout<<g[j].w<<endl;
			}
			if(tt==n-1)break;
		}
		//we(ans);
		//we(n+ttt-1)
		if(tt==n-1)rr=min(rr,ans);
	}
	we(rr);
}