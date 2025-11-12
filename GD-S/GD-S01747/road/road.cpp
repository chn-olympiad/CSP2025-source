#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e4 + 5,M = 1e6 + 5,K = 15;
int n,m,k,c[K],ans = 1e18;
struct DSU{
	int fa[N];
	void init(int n){for(int i = 1;i <= n;i++)fa[i] = i;}
	int find(int x){return (fa[x] == x ? x : fa[x] = find(fa[x]));}
}dsu;
struct Edge{int u,v,w;}e[M],mst[N],now[N * K],tmp[K][N],now2[N * K];
vector<int> npos;
bool operator<(const Edge &a,const Edge &b){return a.w < b.w;}
int calc(int len){
	dsu.init(n + k);
	int ans = 0;
	for(int i = 1;i <= len;i++){
		int u = dsu.find(now[i].u),v = dsu.find(now[i].v);
		if(u != v){
			dsu.fa[u] = v;
			ans += now[i].w;
		}
	}
	return ans;
}
void dfs(int dep,int val){
	if(dep == k + 1){
		int len = n - 1;
		for(int i = 1;i < n;i++)now[i] = mst[i];
		for(auto i : npos){
			merge(now + 1,now + len + 1,tmp[i] + 1,tmp[i] + n + 1,now2 + 1);
			len += n;
			memcpy(now,now2,sizeof(Edge) * (len + 1));
		}
		ans = min(ans,calc(len) + val);
		return;
	}
	npos.push_back(dep);
	dfs(dep + 1,val + c[dep]);
	npos.pop_back();
	dfs(dep + 1,val);
}
void init(){
	dsu.init(n);
	sort(e + 1,e + m + 1);
	int cnt = 0;
	for(int i = 1;i <= m;i++){
		int u = dsu.find(e[i].u),v = dsu.find(e[i].v);
		if(u != v){
			mst[++cnt] = e[i];
			dsu.fa[u] = v;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)cin >> e[i].u >> e[i].v >> e[i].w;
	init();
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> tmp[i][j].w;
			tmp[i][j].u = i + n,tmp[i][j].v = j;
		}
		sort(tmp[i] + 1,tmp[i] + n + 1);
	}
	dfs(1,0);
	cout << ans;
}
