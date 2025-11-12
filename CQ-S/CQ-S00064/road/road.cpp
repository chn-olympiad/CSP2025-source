#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
const int maxn = 1e4 + 10,maxm = 1e6 + 10,maxk = 15;
ll c[maxk];
ll a[maxk][maxn];
int etot;
bool f[maxk];
ll ans;
ll csum;
ll dis[1010][1010];
//
struct Edges{
	int u,v;
	ll w;
};Edges E[maxm];
Edges e[maxm + maxn*maxk];
bool cmp(Edges e1,Edges e2){
	return e1.w < e2.w;
}
int fa[maxn+maxk];
void init(){
	for(int i=1;i<=n+k;i++) fa[i] = i;
}
int finding(int x){
	if(fa[x] == x) return x;
	else return fa[x] = finding(fa[x]);
}
void unioning(int u,int v){
	u = finding(u),v = finding(v);
	fa[u] = v;
}
void setEdges(){
	etot = 0;
	for(int i=1;i<=m;i++) e[i] = E[i];
	etot = m;
	for(int i=1;i<=k;i++){
		if(f[i]){
			for(int j=1;j<=n;j++){
				e[++etot] = {i+n,j,a[i][j]};
			}
		}
	}
}
ll Kruscal(){
	init();
	ll sum = 0;
	sort(e+1,e+etot+1,cmp);
	for(int i=1;i<=etot;i++){
		if(finding(e[i].u) != finding(e[i].v)){
			sum += e[i].w;
			unioning(e[i].u,e[i].v);
		}
	}
	for(int i=1;i<=n;i++){
		if(finding(1) != finding(i)){
			return 1e18;
		}
	}
	return sum;
}
bool isA(){
	for(int i=1;i<=k;i++){
		if(c[i]) return false;
		int fl = 0;
		for(int j=1;j<=n;j++) fl += (a[i][j] == 0);
		if(fl == 0) return false;
	}
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>k;
	if(n <= 1000){
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++){
				if(i == j) continue;
				dis[i][j] = 1e18;
			}
		}
		for(int i=1;i<=m;i++){
			int u,v;
			ll w;
			cin>>u>>v>>w;
			dis[u][v] = dis[v][u] = min(dis[u][v],w);
		}
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++) cin>>a[i][j];
		}
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				for(int i=1;i<=k;i++){
					dis[u][v] = dis[v][u] = min(dis[u][v],a[i][u] + a[i][v] + c[i]);
				}
			}
		}
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				e[++etot] = {u,v,dis[u][v]};
			}
		}
		cout<<Kruscal();
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>E[i].u>>E[i].v>>E[i].w;
		e[i] = E[i];
	}
	etot = m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(isA()){
		etot = 0;
		for(int i=1;i<=m;i++) e[i] = E[i];
		etot = m;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j] == 0){
					for(int x=1;x<=n;x++){
						if(j == x) continue;
						e[++etot] = {j,x,a[i][x]};
					}
					break;
				}
			}
		}
		cout<<Kruscal();
		return 0;
	}
	return 0;
}
