#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e4 + 15;
int n,m,k,vis[1 << 10],c[16];
long long ans[1 << 10];
struct edge{
	int u,v,w;
};
vector<edge> e;
vector<int> cl;
struct tree{
	int f[N],sz[N];
	void init(){
		iota(f + 1,f +n + k + 1,1);
		fill(sz + 1,sz + n + k + 1,1);
	}
	int find(int x){
		return (x == f[x])?x:f[x] = find(f[x]);
	}
	int merge(int u,int v){
		u = find(u),v = find(v);
		if (u == v){
			return 0;
		}
		(sz[u] > sz[v]) && (swap(u,v),1);
		f[u] = v;
		sz[v] += sz[u];
		return 1; 
	}
}f[1 << 10];
void add(int su,int u,int v,int w){
	queue<int> q;
	q.push(su),vis[su] = 1,cl.push_back(su);
	while (!q.empty()){
		int sv = q.front();
		q.pop();
	  if (f[sv].merge(u,v)){
	  	ans[sv] += w;
		  for (int i = 0;i < k;i++){
			  int nsu = sv | (1 << i);
			  if ((!vis[nsu])){
			  	vis[nsu] = 1;
			  	cl.push_back(nsu);
			  	q.push(nsu);
			  }
		  }
	  }
  }
  for (auto i : cl){
  	vis[i] = 0;
	}
	cl.clear();
}
signed main(){
	freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1,u,v,w;i <= m;i++){
  	cin >> u >> v >> w;
  	e.push_back({u,v,w});
	}
	for (int i = 1;i <= k;i++){
		cin >> c[i];
		for (int j = 1,x;j <= n;j++){
			cin >> x;
			e.push_back({n + i,j,x});
		}
	}
	for (int i = 0;i < (1 << k);i++){
		for (int j = 0;j < k;j++){
			(i & (1 << j)) && (ans[i] += c[j + 1]);
		}
		f[i].init();
	}
	sort(e.begin(),e.end(),[](edge a,edge b){return (a.w == b.w)?a.u < b.u:a.w < b.w;});
	for (auto xt : e){
		int u = xt.u,v = xt.v,w = xt.w;
		int su = (u > n)?(1 << (u - n - 1)):0;
		add(su,u,v,w);
	}
	long long sum = 1e18;
	for (int i = 0;i < (1 << k);i++){
		sum = min(sum,ans[i]);
	}
	cout << sum;
}
