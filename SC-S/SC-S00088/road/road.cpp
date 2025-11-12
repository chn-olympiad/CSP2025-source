#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int w,v;
}a[10010];
int n,m,k,cnt,ans,d[10010],wg[1000010],c[15];
int mina=1e8,minl,minv,lt;
vector<int>G[10010];
map<int,int>mp,sm;
void dfs(int x,int step){
	cout<<x<<'\n';
	if(step==n){
		return;
	}
	lt=cnt;
	for(auto v1:G[x]){
		if(sm[v1]==1)continue;
		a[++cnt].v=v1;
		a[cnt].w=min(d[x]+d[v1],wg[mp[x*10000+v1]]);
	}
	mina=1e18;
	for(int i=lt;i<=cnt;i++){
		if(mina>a[i].w){
			mina=a[i].w;
			minl=a[i].v;
			minv=i;
		}
	}
	sm[minl]=1;
	ans+=mina;
	a[minv].w=1e18;
	mina=1e8;
	for(int i=lt;i<=cnt;i++){
		mina=min(mina,a[i].w);
	}
	a[cnt].w=mina;
	dfs(minl,step+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=0;i<=10010;i++){
		a[i].w=1e18;d[i]=1e8;
	}
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(v);
		G[v].push_back(u);
		mp[u*10000+v]=i;
		mp[v*10000+u]=i;
		wg[i]=w;
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			int w;cin>>w;
			d[i]=min(d[i],w);
		}
	}
	sm[1]=1;
	dfs(1,1);
	cout<<ans;
	return 0;
}
