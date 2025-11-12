#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4+10,M = 1e6+10,K = 12,INF = 1e18;
int n,m,k,a[K][N],c[K],fa[N],ans;
struct edg{
	int u,v,w;
} e[M],t[M];
vector<edg> tr;

int find(int u){
	if(fa[u]==u) return u;
	return fa[u] = find(fa[u]);
}
void merge(int u,int v){
	fa[find(u)] = find(v);
}
void rst(){
	for(int i=1;i<=n+k;i++) fa[i] = i;
}
bool cmp(edg x,edg y){
	return x.w<y.w;
}
int cal(int pl){ //枚举点后在原有生成树上加边后跑最小生成树 pl为枚举方案
	int sum = 0,len = tr.size();
	for(int i=0;i<len;i++) t[i] = tr[i];
	for(int d=1;d<=k;d++){
		if((pl>>(d-1))&1){
			sum+=c[d];
			for(int i=1;i<=n;i++) t[len++] = {n+d,i,a[d][i]};
		}
	}
	rst();
	sort(t,t+len,cmp);
	for(int i=0;i<len;i++){
		if(find(t[i].u)!=find(t[i].v)){
			sum+=t[i].w;
			merge(t[i].u,t[i].v);
		}
	}
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i] = {u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	rst();
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			ans+=e[i].w;
			merge(e[i].u,e[i].v);
			tr.push_back(e[i]);
		}
	}
	for(int i=1;i<(1<<k);i++){ //复杂度略超，O2神力祝我通关！！！ 
		int sum = cal(i);
		ans = min(ans,sum);
	}
	cout<<ans;
	return 0;
}
