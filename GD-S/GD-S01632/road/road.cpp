#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10005,M=2e7+5;
int n,m,k,fa[N<<2],a[15][N],c[15],sz[N];
struct edge{
	int u,v,w;
	bool operator <(const edge&z)const{return w<z.w;}
}e[M];
int find(int x){return (fa[x]==x?x:fa[x]=find(fa[x]));}
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	bool f=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int x=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0) x=i;
		}
		f=f||x||c[i];
	}
	if(f==0){
		for(int i=1;i<=k;i++){
			int x=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0) x=i;
		}
		for(int u=1;u<=n;u++){
				if(u==x) continue;
				e[++m]={u,x,a[i][u]+c[i]};
			}
		}
		
	}
	else{
		for(int i=1;i<=k;i++){
			if(m>5000000) break;
			for(int u=1;u<=n;u++)
				for(int v=u+1;v<=n;v++){
				e[++m]={u,v,a[i][u]+a[i][v]+c[i]};
			}
		}

	}
	sort(e+1,e+m+1);
	int ans=0,cnt=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v)) continue;
		u=find(u),v=find(v);
		if(sz[u]>sz[v]) swap(u,v);
		fa[u]=v,sz[v]+=sz[u];
		ans+=w;cnt++;
		if(cnt==n-1) break;
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T;
	T=1;
	while(T--){
		solve();
	}
}
