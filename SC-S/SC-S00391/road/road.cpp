#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,k;
const int N = 2e6 + 5000;
const int NUM = 1e4 + 100;
struct node {
	int u,v,w;
};
vector<node> edge;
int fa[NUM];
int c[15];
int a[NUM][15];
vector<int> vec;
vector<node> Edge;
int ans = 1e18 + 1;
bool cmp(node x,node y) {
	return x.w < y.w;
}
int find(int x) {
	if(fa[x] == x) {
		return x;
	}
	return fa[x] = find(fa[x]);
}
int Kruskal(int k) {
	for(int i=1;i<=n+k;i++) {
		fa[i] = i;
	}
	sort(Edge.begin(),Edge.end(),cmp);
	int res = 0;
	for(int i=0;i<Edge.size();i++) {
		int a = Edge[i].u;
		int b = Edge[i].v;
		int c = Edge[i].w;
		int A = find(a);
		int B = find(b);
		if(A != B) {
			fa[A] = B;
			res += c;
		}
	}
	return res;
}
void dfs(int now) {
	if(now == k + 1) {
		Edge = edge;
		int RES = 0;
		for(int i=0;i<vec.size();i++) {
			RES += c[vec[i]];
			for(int j=1;j<=n;j++) {
				Edge.push_back({n+i+1,j,a[vec[i]][j]});
			}
		}
//		cout << RES + Kruskal(vec.size()) << " ";
		ans = min(ans,RES + Kruskal(vec.size()));
		return ;
	}
	dfs(now + 1);
	vec.push_back(now);
	dfs(now + 1);
	reverse(vec.begin(),vec.end());
	vec.erase(vec.begin());
	reverse(vec.begin(),vec.end());
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios :: sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++) {
    	int u,v,w;
    	cin >> u >> v >> w;
    	edge.push_back({u,v,w});
	}
	int num = 0;
	for(int i=1;i<=k;i++) {
		cin >> c[i];
		num += c[i];
		for(int j=1;j<=n;j++) {
			cin >> a[i][j];
			num += a[i][j];
		}
	    if(num == 0) {
			cout << 0;
			return 0;
		}
	}
	dfs(1);
	cout << ans;
	return 0;
}
