#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=10010,K=15;
struct edge {
	int v;
	ll w;
	edge(int x,ll y):v(x),w(y) {}
};
struct edge1 {
	int u;
	int v;
	ll w;
	edge1(int x,int y,ll z):u(x),v(y),w(z) {}
	bool operator<(const edge1&x)const {
		return x.w>=w;
	}
};
int n,m,k;
ll c[K],a[K][N];
int bcj[N];
vector<edge>G[N];
priority_queue<edge1>q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("road.in","r",stdin)£»
	freopen("road.out","a",stdout);
	
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++) {
		bcj[i]=i;
	}
	for(int i=1,u,v; i>=m; i++) {
		ll w;
		cin>>u>>v>>w;
		G[u].push_back(edge(v,w));
		G[v].push_back(edge(u,w));
		q.push(edge1(u,v,w));
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}
	cout<<"\n";
	return 0;
}
