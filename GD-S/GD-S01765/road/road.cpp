#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 10100;
const int M = 1001000;
int n,m,k;
ll ans=1e18;
struct edge{
	int u,v,w;
}e[M],g[M];
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
inline void init(int t){
	for(int i=1;i<=t;i++) fa[i]=i;
	return;
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int a[11][N],c[N],cnt,tot;
bool b[N];
ll solve(){
	init(tot);
	ll res=0;
	int _=0;
	for(int i=1,j=1;i<=m || j<=cnt;){
		if(_==tot-1) break;
		//cout<<i<<' '<<j<<'\n';
		if((j>cnt) || (i<=m && e[i].w<g[j].w)){
			//cout<<0<<'\n';
			int u=e[i].u,v=e[i].v,w=e[i].w;
			i++;
			int U=find(u),V=find(v);
			if(U==V) continue;
			fa[U]=V;
			res+=w;
			_++;
		}else{
			//cout<<1<<'\n';
			int u=g[j].u,v=g[j].v,w=g[j].w;
			j++;
			int U=find(u),V=find(v);
			if(U==V) continue;
			fa[U]=V;
			res+=w;
			_++; 
		}
	}
	return res;
}
inline void dfs(int u,ll sum){
	//cout<<u<<' '<<sum<<'\n';
	if(u>k){
		cnt=0,tot=n;
		if(sum>=ans) return;
		for(int i=1;i<=k;i++){
			if(b[i]){
				++tot;
				for(int j=1;j<=n;j++){
					g[++cnt].u=tot;
					g[cnt].v=j;
					g[cnt].w=a[i][j];
				}
			}
		}
		sort(g+1,g+1+cnt,cmp);
		ll res=solve();
		ans=min(ans,sum+res);
		//cout<<sum<<' '<<ans<<'\n';
		return;
	}
	if(!c[u]){
		b[u]=1;
		dfs(u+1,sum+c[u]);
		return;
	}
	b[u]=1;
	dfs(u+1,sum+c[u]);
	b[u]=0;
	dfs(u+1,sum);
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i].u=u;
		e[i].v=v;
		e[i].w=w;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	dfs(1,0);
	cout<<ans; 
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
