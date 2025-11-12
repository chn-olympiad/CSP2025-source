#include <bits/stdc++.h>
#define lint long long
#define endl '\n'
using namespace std;
const int N = 1e4+5;
const int M = 1e6+5;
const int K = 1e1+5;

struct node{
	int u,v;
	lint w;
	
	bool operator <(const node &other) const {
		return this->w < other.w;
	}
	bool operator >(const node &other) const {
		return this->w > other.w;
	}
	void print(){
		cout << this->u << " ";
		cout << this->v << " ";
		cout << this->w << endl;
	}
}e[M];

int n,m,k;
lint a[K][N];
lint fee[K];
int f[N];
bitset<100> b;
lint ans;

priority_queue<node,vector<node>,greater<node>> q,que;

inline int find(int x){
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

inline void merge(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) f[fx] = fy;
}

inline lint cal(){
	lint res = 0;
	que = q;
	for(int i = 1; i <= k; i++){
		if(b[i] == true){
			res += fee[i];
			for(int u = 1; u < n; u++){
				for(int v = u+1; v <= n; v++){
					que.push((node){u,v,a[i][u]+a[i][v]});
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++)
		f[i] = i;
	
	while(!que.empty()){
		node idx = que.top();
		int u = idx.u,v = idx.v,w = idx.w;
		if(find(u) != find(v)){
			merge(u,v);
			res += w;
		}
		que.pop();
	}
	return res;
}

inline void dfs(int idx){
//	cout << idx << endl;
	if(idx > k){
		ans = min(ans,cal());
		cout << cal() << endl;
		for(int i = 1; i <= k; i++)
			cout << b[i] << " ";
		cout << endl;
		return;
	}
	b[idx] = true;
	dfs(idx+1);
	b[idx] = false;
	dfs(idx+1);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		e[i] = (node){u,v,w};
	}
	for(int i = 1; i <= k; i++){
		cin >> fee[i];
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	
	for(int i = 1; i <= n; i++)
		f[i] = i;
	
	sort(e+1,e+1+m);
	
	for(int i = 1; i <= m; i++){
		int u = e[i].u,v = e[i].v;
		if(find(u) != find(v)){
			merge(u,v);
			q.push(e[i]);
			ans += e[i].w;
		}
		if(q.size() == n-1)
			break;
	}
	
	dfs(1);
	
	cout << ans << endl;
	return 0;
}
