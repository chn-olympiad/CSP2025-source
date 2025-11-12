#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+15,M=1e6+5,Q=11e4+5;
int n,m,p,fa[N],num,c[Q],al,nm[11],d[N][11],bj[11],ans=1e18;
vector<pair<int,int> >v[Q];
struct node{int x,y,v;}a[M],b[N];
bool cmp(node x,node y){return x.v<y.v;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void dfs(int x)
{
	if(x>p)
	{
		int as=0;
		for(int i=1;i<=p;i++) if(bj[i]) as+=nm[i];
		for(int i=1;i<=n+p;i++) fa[i]=i;
		for(int x,y,i=1;i<=al;i++)
		{
			for(auto j:v[i])
			{
				x=find(j.first),y=find(j.second);
				if(x!=y) fa[x]=y,as+=c[i];
			}
		}
		ans=min(ans,as);
		return;
	}
	bj[x]=0,dfs(x+1);
	for(int i=1;i<=n;i++) v[d[i][x]].push_back({n+x,i});
	bj[x]=1,dfs(x+1);
	for(int i=1;i<=n;i++) v[d[i][x]].pop_back();
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>p;
	for(int x,y,v,i=1;i<=m;i++) cin>>x>>y>>v,a[i]={x,y,v};sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int x,y,i=1;i<=m;i++){x=find(a[i].x),y=find(a[i].y);if(x!=y) fa[x]=y,b[++num]=a[i];}
	for(int i=1;i<=num;i++) c[++al]=b[i].v;
	for(int i=1;i<=p;i++){cin>>nm[i];for(int j=1;j<=n;j++) cin>>d[j][i],c[++al]=d[j][i];}
	sort(c+1,c+al+1),al=unique(c+1,c+al+1)-c-1;
	for(int i=1;i<=p;i++) for(int j=1;j<=n;j++) d[j][i]=lower_bound(c+1,c+al+1,d[j][i])-c;
	for(int i=1;i<=num;i++) b[i].v=lower_bound(c+1,c+al+1,b[i].v)-c,v[b[i].v].push_back({b[i].x,b[i].y});
	dfs(1),cout<<ans;
	return 0;
}
