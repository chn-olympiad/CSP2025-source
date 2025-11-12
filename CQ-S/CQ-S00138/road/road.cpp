#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define ff(i,a,b) for(int i=(a);i>=(b);i--)
#define sd std::
#define dbg(x) sd cout<<#x<<":"<<x<<" "
#define dg(x) sd cout<<#x<<":"<<x<<"\n"
#define inf 1e10
int read(){int w=1,c=0;char ch=getchar();for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') w=-1;for(;ch>='0'&&ch<='9';ch=getchar()) c=(c<<3)+(c<<1)+ch-48;return w*c;}
void printt(int x){if(x>9) printt(x/10);putchar(x%10+48);}
void print(int x){if(x<0) putchar('-'),x=-x;printt(x);}
void printk(int x){print(x);putchar(' ');}
void put(int x){print(x);puts("");}
const int N=2e4+10,M=2e6+10,P=1e9+7;
void fre()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
int n,m,k,cnt,tmp;
struct edge
{
	int u,v,w,id;//如果有id就是说这条边对应的哪个乡村 
	edge(int uu,int vv,int ww,int iid)
	{
		u=uu,v=vv,w=ww,id=iid;
	}
	edge(){}
}a[M],e[M];
int cmp(edge x,edge y)
{
	return x.w<y.w;
}
int fa[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int val[15][N],c[N],ma,vis[N];//vis[i]表示这个点能不能选 
ll ans;
void solve()
{
	n=read(),m=read(),k=read();
	F(i,1,n) fa[i]=i;
	F(i,1,m) a[i].u=read(),a[i].v=read(),a[i].w=read();
	sd sort(a+1,a+1+m,cmp);
	F(i,1,m)
	{
		int u=find(a[i].u),v=find(a[i].v),w=a[i].w;
		if(u==v) continue;
		a[++cnt]=a[i];
		ans+=w;
		ma=sd max(ma,w);
		fa[u]=v;
		if(cnt==n-1) break;
	}
	F(i,1,k)
	{
		c[i]=read();
		F(j,1,n)
		{
			val[i][j]=read();
			if(val[i][j]<ma) a[++cnt]=edge(j,n+i+1,val[i][j],i);
		}
	}
	sd sort(a+1,a+1+cnt,cmp);
	vis[0]=1;
	F(S,1,(1<<k)-1)
	{
		F(i,1,n+k+1) fa[i]=i;
		int now=0,sum=n;//sum是一共要联通的点个数 
		ll res=0;
		F(i,0,k-1)
		{
			if((S>>i)&1)
			{
				sum++;
				res+=c[i+1];
				vis[i+1]=1;
			}
			else vis[i+1]=0;
		}
		F(i,1,cnt)
		{
			int u=find(a[i].u),v=find(a[i].v),w=a[i].w;
			if(u==v||!vis[a[i].id]) continue;
			++now;
			res+=w;
			fa[u]=v;
			if(now==sum-1||res>=ans) break;
		}
		ans=sd min(ans,res);
	}
	printf("%lld",ans);
}
int main()
{
	fre();
	int T=1;
//	T=read();
	while(T--) solve();
}
/*
搞一个最小生成树出来，然后钦定乡村之后跑kruskal
这样是kn2^klogn的
然后发现可以先把所有边搞上，然后钦定的时候用 vis 记录一下即可
这样就是kn2^k，大概是 10^8
不知道能不能跑过 
*/

