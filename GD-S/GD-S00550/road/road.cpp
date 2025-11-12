#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long
const int N = 1e4 + 6;
struct node{
	int u,v,val;
	friend bool operator < (node x,node y){
		return x.val < y.val;
	}
};
int n,m,k,ans = 1e9;
int c[N],a[20][N],vis[N],fa[N];
vector<node> tmp;
vector<node> edge;
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
int tr(){
	vector<node> choose;
	int res = 0,tot = 0;
	for(int i = 1;i <= n; i++) fa[i] = i;
	tmp = edge;
	sort(tmp.begin(),tmp.end());
	for(int i = 0;i < (int)tmp.size(); i++){
		int x = tmp[i].u;
		int y = tmp[i].v;
		int fy = find(x);
		int fx = find(y);
		if(fx == fy) continue;
		fa[fx] = fy;
		choose.push_back({fx,fy,tmp[i].val});
		res += tmp[i].val;
		if(++tot == n - 1) break;
	}
	return res;
}
vector<int> res;
void dfs(int x,int val){
	if(x == k + 1){
		ans = min(ans,tr() + val);
		return ;
	}
	for(int i = 1;i <= n; i++)
		for(int j = 1;j <= n; j++){
			if(i == j) continue;
			edge.push_back({i,j,a[x][i] + a[x][j]});
			edge.push_back({j,i,a[x][i] + a[x][j]});
		}
	res.push_back(x);
	dfs(x + 1,val + c[x]);
	res.pop_back();
	for(int i = 1;i <= n; i++) 
		for(int j = 1;j <= n; j++){
			if(i == j) continue;
			edge.pop_back();
			edge.pop_back();
		}
	dfs(x + 1,val);
}
void solve(){
	cin >> n >> m >> k;
	for(int i = 1;i <= m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		edge.push_back({u,v,w});
		edge.push_back({v,u,w});
	}
	for(int i = 1;i <= k; i++){
		cin >> c[i];
		for(int j = 1;j <= n; j++)
			cin >> a[i][j];
	}
	dfs(1,0);
	cout << ans << endl;
}
signed main(){
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	int T = 1;
	while(T--)
		solve();
}
