#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int maxn=2e5+50;
const int INF=1e6+5; 
int n,m,k,cnt,num;
struct Edge{
	int u,v;
	ll w;
}E1[INF],E2[maxn],E3[maxn],E4[maxn],a[11][maxn];
ll ans=0;
int fa[maxn];
int Size[maxn];
ll c[maxn];
bool Visit[20];
map<pair<int,int>,ll> p; 
int Find(int x){
	if(x==fa[x]) return x;
	return fa[x]=Find(fa[x]);
} 
void Merge(int x,int y){
	x=Find(x);
	y=Find(y);
	if(x==y) return;
	if(Size[x]>Size[y]) swap(x,y);
	fa[x]=y; 
	Size[y]+=Size[x];
} 
bool cmp(Edge x,Edge y){
	return x.w<y.w;
} 
void solve(){
	ll preans=0;
	num=0;
	for(int i=1;i<=cnt;i++) E3[++num]=E2[i];
	for(int i=1;i<=k;i++){
		if(!Visit[i]) continue;
		preans+=c[i];
		int k=1;
		int tot=0;
		for(int j=1;j<=n;j++){
			while(k<=num&&E3[k].w<a[i][j].w){
				E4[++tot]=E3[k];	
				k++;
			}
			E4[++tot]=a[i][j];
		}
		num=0;
		for(int j=1;j<=tot;j++) E3[++num]=E4[j];
	}
	if(preans>ans) return;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=n+k;i++) Size[i]=1;
	for(int i=1;i<=num;i++){
		int u=E3[i].u,v=E3[i].v;
		if(Find(u)!=Find(v)){
			preans+=E3[i].w;
			if(preans>ans) return;
		}
		Merge(u,v);
	}
	ans=min(preans,ans);
	return;
}
void dfs(int x){
	if(x==k+1){
		solve();
		return;
	}
	Visit[x]=false;
	dfs(x+1);
	Visit[x]=true;
	dfs(x+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin >> u >> v >> w;	
		E1[i]=(Edge){u,v,w};
	}
	sort(E1+1,E1+1+m,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++) Size[i]=1;
	for(int i=1;i<=m;i++){
		int u=E1[i].u,v=E1[i].v;
		if(Find(u)!=Find(v)){
			E2[++cnt]=E1[i];
			ans+=E1[i].w;
		}
		Merge(u,v);
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++){
			ll w;
			cin >> w;	
			a[i][j]=(Edge){i+n,j,w};
		}
		sort(a[i]+1,a[i]+1+n,cmp);
	}
	dfs(1);
	cout << ans;
	return 0;
} 
