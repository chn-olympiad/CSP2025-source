#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e6+7;
struct node{
	int u,v,w;
};
vector<node> V;
int n,m,k,c[N],rt[N],vis[N],ans = LONG_LONG_MAX;
bool cmp(node x,node y){
	return x.w < y.w;
}
int findrt(int x){
	if(rt[x] == x)
		return x;
	return rt[x] = findrt(rt[x]);
}
int kruskal(){
	int sum = 0;
	for(int i=1;i<=m+k;i++) rt[i] = i;
	sort(V.begin(),V.end(),cmp);
	for(auto e:V){
		int ru = findrt(e.u),rv = findrt(e.v);
		if(ru == rv) continue;
		if(e.u > m && vis[e.u]){
			rt[ru] = rv;
			sum += e.w;
		}
		if(e.u <= m){
			rt[ru] = rv;
			sum += e.w;
		}
	}
	return sum;
}
void dfs(int step,int sum){
	if(step > k){
		ans = min(ans,sum+kruskal());
		return ;
	}
	if(sum > ans) return ;
	dfs(step+1,sum);
	vis[step+m] = 1;
	dfs(step+1,sum+c[step]);
	vis[step+m] = 0;
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		V.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			V.push_back({m+i,j,x});
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
