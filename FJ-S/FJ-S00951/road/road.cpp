// 16:32 完成 T2 32pts 
// 16:41 完成 T2 48pts 
// 16:55 完成 T2 64pts 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define set0(a) memset((a),0,sizeof((a)))
#define setinf(a) memset((a),0x3f,sizeof((a)))
const int inf=0x3f3f3f3f, llinf=0x3f3f3f3f3f3f3f3f;
namespace IO
{
	void read(int &x)
	{
		x=0; char c=getchar();
		while(!isdigit(c)) c=getchar();
		while(isdigit(c)){ x=(x<<3)+(x<<1)+(c^48); c=getchar(); }
	}
	void write(int x)
	{
		if(x>9) write(x/10);
		putchar(x%10^48);
	}
	void writeln(int x)
	{
		write(x); putchar('\n');
	}
}
namespace W_C_B_H	// Luogu UID: 527300
{
	using namespace IO;
	const int N=10005, M=1000005, K=15;
	int n,m,k,kk,c[K],a[K][N],ans=llinf,fa[N+K],siz[N+K],flag=0;
	struct edge
	{
		int u,v,w;
		edge(int _u=0, int _v=0, int _w=0)
		{
			u=_u, v=_v, w=_w;
		}
		bool operator < (const edge &b) const
		{
			return w < b.w;
		}
	}g[M],e[M+N*K];
	int find(int x)
	{
		if(fa[x]==x)
		{
			return x;
		}
		int f=find(fa[x]);
//		siz[x]=siz[f];
		return f;
	}
	void merge(int x,int y)
	{
		int fx=find(x), fy=find(y);
		if(siz[fx]<siz[fy])
		{
			fa[fx]=fy;
		}
		else
		{
			fa[fy]=fx;
		}
	}
	int kruskal(int _n,int _m,int s)
	{
//		printf("kruskal(%lld,%lld)\n",_n,_m);
		int ret=s;
		for(int i=1;i<=_n;i++)
		{
			fa[i]=i;
			siz[i]=1;
		}
		sort(e+1,e+1+_m);
		for(int i=1;i<=_m;i++)
		{
			int u=e[i].u, v=e[i].v, w=e[i].w;
//			printf("(%lld,%lld,%lld)\n",u,v,w);
			if(find(u)^find(v))
			{
				ret+=w;
//				printf("ret=%lld\n",ret);
				if(ret>ans)
				{
					return ret;
				}
				merge(u,v);
			}
		}
		return ret;
	}
	void main()
	{
		read(n), read(m), read(k);
		kk=1<<k;
		for(int i=1,u,v,w;i<=m;i++)
		{
			read(u), read(v), read(w);
			g[i]=edge(u,v,w);
		}
		for(int j=1;j<=k;j++)
		{
			read(c[j]);
			if(!c[j])
			{
				flag|=1<<(j-1);
			}
			for(int i=1;i<=n;i++)
			{
				read(a[j][i]);
			}
		}
//		printf("flag=%lld\n",flag);
		for(int i=0;i<kk;i++)
		{
			if((i&flag)^flag)
			{
				continue;
			}
			int cnt=n,tot=m,sum=0;
			for(int j=1;j<=k;j++)
			{
				if((i>>(j-1))&1)
				{
					cnt++;
					sum+=c[j];
					if(sum>ans)
					{
						break;
					}
					for(int l=1;l<=n;l++)
					{
						e[++tot]=edge(cnt,l,a[j][l]);
					}
				}
			}
			if(sum>ans)
			{
				continue;
			}
			for(int j=1;j<=m;j++)
			{
				e[j]=g[j];
			}
//			printf("i=%lld, cnt=%lld, tot=%lld, sum=%lld\n",i,cnt,tot,sum);
			ans=min(ans,kruskal(cnt,tot,sum));
		}
		write(ans);
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	W_C_B_H::main();
	return 0;
}
/*
road2.in: 1.970s
road3.in: 1.563s
road4.in: 11.80s
*/
