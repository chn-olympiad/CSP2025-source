#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
#define int long long 
using namespace std;
int n,m,k,ans;
struct node{
	int v,w;
};
vector<node>g[10015];
int a[10015][10],fm[10015],c[10005],fft[15];
bool vis[10015];
bool cmp(node l,node r){
	return l.w<r.w;
}
int find_set(int u){
	if(u!=fm[u])return fm[u] = find_set(fm[u]);
	return u;
}
void merge_set(int u,int v){
	u = find_set(u),v = find_set(v);
	fm[u] = v;
}
void solve(){
	stack<int>p;
	p.push(1);
	while(p.size()){
		int u = p.top();
		p.pop(); 
		int ff = 1;
		for(int i =1;i<=n;i++){
			if(find_set(i)!=find_set(u)){
				ff = 0;break; 
			}
		}
		if(ff)return;
		for(auto i:g[u]){
			int v = i.v,w = i.w;
			if(find_set(u)==find_set(v))continue;
			if(u>n)fft[u-n] = 1;
			if(v<=n){
				ans += w;
				merge_set(u,v);
				p.push(v);
			}
			else{
				c[v-n] = w;
				merge_set(u,v);
				p.push(v);
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i =1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i =1;i<=k;i++){
		cin>>c[i];
		for(int j =1;j<=n;j++){
			int x;cin>>x;
			g[i+n].push_back({j,x});
			g[j].push_back({i+n,x+c[i]});
		}
	}
	for(int i =1;i<=n+k;i++){
		fm[i] = i;
		sort(g[i].begin(),g[i].end(),cmp);
	}
	solve();
	for(int i =1;i<=k;i++)ans += fft[i]*c[i]; 
	cout<<ans;
	return 0;
}
/*
5 6 1
1 2 3
2 3 4
3 4 1
4 5 2
2 5 90
1 3 0
0 0 0 0 0 0
*/
