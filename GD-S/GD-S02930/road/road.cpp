#include <bits/stdc++.h>
using namespace std;

#define int long long

const int _ = 2e6 + 5;

struct Edge {
  int u,v,w;
};

int n,m,k;

int Cmp(Edge a,Edge b) { return a.w < b.w; }

int fa[_];
int Find(int x) { return (fa[x] == x ? x : fa[x] = Find(fa[x])); }

int c[_],a[_][15],cnt;
int vis[15];

vector<Edge> e,res;
int ans;

int Kruskal(vector<Edge> ee,int flagg = 0) {
  for(int i = 1;i <= n + k;i++) fa[i] = i;
  sort(ee.begin(),ee.end(),Cmp);
  int sum = 0;
  for(auto ed : ee) {
  	int x = ed.u,y = ed.v,w = ed.w,X = Find(x),Y = Find(y);
  	if(X == Y) continue;
  	fa[Y] = X;
  	sum += w;
  	if(flagg) res.push_back(ed);
  }
  return sum;
}

void Work() {
  vector<Edge> tmp;
  for(auto x : res) tmp.push_back(x);
  int sum = 0;
  for(int i = 1;i <= k;i++) {
  	if(!vis[i]) continue;
  	sum += c[i];
  	for(int j = 1;j <= n;j++) {
  	  tmp.push_back(Edge{n + i,j,a[i][j]});
	}
  }
  sum += Kruskal(tmp);
  ans = min(sum,ans);
}

void Get(int now) {
  if(now > k) {
  	Work();
  	return;
  }
  vis[now] = 0,Get(now + 1),vis[now] = 1,Get(now + 1),vis[now] = 0;
}

signed main() {
  freopen("road3.in","r",stdin);
  freopen("road.out","w",stdout);
  ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
  cin >> n >> m >> k;
  for(int i = 1,u,v,w;i <= m;i++) cin >> u >> v >> w,e.push_back(Edge{u,v,w});
  for(int i = 1;i <= k;i++) {
  	cin >> c[i];
  	for(int j = 1;j <= n;j++) {
  	  cin >> a[i][j];
	}
  }
  ans = Kruskal(e,1); 
  Get(1);
  cout << ans << '\n';
  return 0;
}

