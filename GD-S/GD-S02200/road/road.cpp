#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e3+10,MAXM=1e6+10;
ll ans;
int fa[MAXN];
int g[MAXN][MAXN],id[MAXN][MAXN];
int a[20][MAXN],wk[20],tot;
struct edge{
	int u,v,w;
}e[MAXM];
int find(int x){
	if(!fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
int n,m,k;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	if(k==0){
		for(int i=1;i<=m;i++){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
//		for(int i=1;i<=k;i++){
//			cin>>wk[i];
//			for(int j=1;j<=n;j++){
//				cin>>a[k][i]; 
//			}
//		}
		sort(e+1,e+m+1,cmp);
		int p=1;
		int t=n-1;
		while(t){
			int u=e[p].u,v=e[p].v;
			u=find(u);
			v=find(v);
			if(u!=v){
				fa[u]=v;
				ans+=e[p].w;
				t--;
			}
			p++;
		}
		cout<<ans<<endl;
		return 0;
	}
	//
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=2e9+10;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>wk[i];
		for(int i=1;i<=n;i++){
			cin>>a[k][i];
		}
		for(int ii=1;ii<=n;ii++){
			for(int jj=1;jj<=n;jj++){
				if(ii==jj) continue;
				g[ii][jj]=min(g[ii][jj],a[k][ii]+a[k][jj]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			e[++tot].u=i;
			e[tot].v=j;
			e[tot].w=g[i][j];
//			cout<<g[i][j]<<endl;
		}
	}
	sort(e+1,e+tot+1,cmp);
//	cout<<n<<' '<<tot<<endl;
	int p=1;
	int t=n-1;
	while(t){
		int u=e[p].u,v=e[p].v;
		u=find(u);
		v=find(v);
		if(u!=v){
			fa[u]=v;
			ans+=e[p].w;
			t--;
		}
		p++;
	}
	cout<<ans<<endl;
	return 0;
}
