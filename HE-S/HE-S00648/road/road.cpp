#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=10050;
struct Edge{
	int u,v,w;
}E[maxn*100];
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
vector<Edge> to[maxn];
int n,m,k,c[15],a[15][maxn],idx,fa[maxn],rk[maxn];
void build(){for(int i=1;i<=n;i++) fa[i]=i,rk[i]=1;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	if(rk[x]>rk[y]) swap(x,y);
	fa[x]=y;
	if(rk[x]==rk[y]) rk[y]++; 
}
int Kruskal()
{
	build();
	int cnt=0,sum=0;
	for(int i=1;i<=m;i++)
	{
		int u=E[i].u,v=E[i].v,w=E[i].w;
		if(find(u)!=find(v))
		{
			merge(u,v);
			cnt++,sum+=w;
		}
		if(cnt==n-1) return sum; 
	}
	return 0;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		int u,v,w; cin>>u>>v>>w;
		to[u].push_back(Edge{u,v,w});
		E[++idx]=Edge{u,v,w};
	}
	if(k==0)
	{
		sort(E+1,E+m+1,cmp);
		int ans=Kruskal();
		cout<<ans<<endl;
	}
	return 0;
} 
