#include<bits/stdc++.h>
#define int long long
using namespace std;
struct ed{
	int to,va;
};
struct edg{
	int from,to,va;
};
vector<ed> a[10086];
vector<edg> edge;
int fa[10086],vill[15][10086],c[15],minx[15],n,m,k,cnt,ans,nowans,minn[15];
bool cmp(edg x,edg y){
	return x.va<y.va;
}
int findr(int x){
	if(fa[x]==x) return x;
	else return fa[x]=findr(fa[x]);
}
bool use[15];
void dfs2(int x,int pre){
	for(auto f:a[x]){
		//cout<<f.to<<' ';
		if(f.to!=pre){
			int now=f.va;
			for(int i=1;i<=k;i++) if(use[i]){
				if(minx[i]!=f.to) now=min(now,vill[i][f.to]);
			}
			nowans+=now;
			dfs2(f.to,x);
			//cout<<now<<' ';
		}
	}
	return;
}
void solve()
{
	int rt=0;
	nowans=0;
	for(int i=1;i<=k;i++){
		if(use[i]){
			rt=minx[i];
			nowans+=minn[i];
		}
	} 
	if(!rt) return;
	dfs2(rt,0);
}
void dfs1(int x,int nowsum)
{
	if(x)solve();
	if(x){
		ans=min(ans,nowans+nowsum);
		//cout<<x<<' '<<nowsum<<' '<<nowans<<'\n';
	} 
	for(int i=x+1;i<=k;i++)
	{
		use[i]=1;
		dfs1(i,nowsum+c[i]);
		use[i]=0;
	}
	return;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edge.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		minn[i]=1e18;
		for(int j=1;j<=n;j++){
			cin>>vill[i][j];
			if(vill[i][j]<minn[i]) minn[i]=vill[i][j],minx[i]=j;
		} 
	}
	sort(edge.begin(),edge.end(),cmp);
	for(int i=0;i<m;i++)
	{
		int u=findr(edge[i].from),v=findr(edge[i].to);
		if(u!=v){
			ans+=edge[i].va,cnt++,fa[u]=v;
			a[edge[i].from].push_back({edge[i].to,edge[i].va});
			a[edge[i].to].push_back({edge[i].from,edge[i].va});
		} 
		if(cnt==n-1) break;
	}
	//cout<<ans<<'\n';
	dfs1(0,0);
	cout<<ans;
	return 0;
}
