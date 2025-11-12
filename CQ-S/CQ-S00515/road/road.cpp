#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define fi first
#define sd second
#define pb push_back
#define mk make_pair
#define endl '\n'
#define int long long
namespace wilbur
{
	const int N=1e4+50,M=1e6+50;
	int n,m,k,ans,cnt;
	int fa[N];
	int Find(int x)
	{
		if(fa[x]==x)return x;
		return fa[x]=Find(fa[x]);
	}
	struct edge{
		int u,v,w;
		bool operator <(const edge &a)const{
			return w<a.w;
		}
	}e[M],e2[M],E[150000];
	int a[N],c[15][N];
	int main()
	{
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
		for(int i=1;i<=k;i++)
		{
			cin>>a[i];
			for(int j=1;j<=n;j++)cin>>c[i][j];
		}
		sort(e+1,e+1+m);
		for(int i=1;i<=m;i++)
		{
			if(Find(e[i].u)==Find(e[i].v))continue;
			fa[Find(e[i].u)]=Find(e[i].v);
			ans+=e[i].w;
			e2[++cnt]=e[i];
		}
		int all=(1<<k)-1;
		for(int i=0;i<=all;i++)
		{
			int res=0;
			for(int j=1;j<=cnt;j++)E[j]=e2[j];
			for(int j=1;j<=n+k;j++)fa[j]=j;
			int tot=cnt;
			for(int j=1;j<=k;j++)if(((i>>(j-1))&1))
			{
				res+=a[j];
				for(int l=1;l<=n;l++)E[++tot].u=j+n,E[tot].v=l,E[tot].w=c[j][l];
			}
			if(res>=ans)continue;
			sort(E+1,E+1+tot);
			bool flag=true;
			for(int j=1;j<=tot;j++)
			{
				if(Find(E[j].u)==Find(E[j].v))continue;
				res+=E[j].w;fa[Find(E[j].u)]=Find(E[j].v);
				if(res>=ans)
				{
					flag=false;
					break;
				}
			}
			if(!flag)continue;
			ans=min(ans,res);
		}
		//O(2^k n\log n) solution 
		cout<<ans<<endl;
		return 0;
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	wilbur::main();
	return 0;
}

