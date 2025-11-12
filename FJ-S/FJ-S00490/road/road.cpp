#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;

struct node{
	int u,v,w;
};

int fa[N],n,m,k,cnt[N],ans;
vector<node> g;

bool cmp(node x,node y){
	return x.w < y.w;
}

int Find(int x){
	if(fa[x] == x)return x;
	return fa[x] = x;
}

void get(int x,int y){
	int z = Find(x);
	fa[z] = y;
	cnt[y] = cnt[x] = cnt[x] + cnt[y];
}

void solve(){
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)cnt[i] = 1;
	for(int i=1;i<=n+k;i++)fa[i] = i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		int a,c;
		cin >> c;
		g.push_back({n+i,0,c});
		for(int j=1;j<=n;j++){
			cin >> a;
			g.push_back({n+i,j,a});
		}
	}
	sort(g.begin(),g.end(),cmp);
	int len = g.size();
	for(int i=0;i<len;i++){
		if(Find(g[i].u) == Find(g[i].v))continue;
		get(g[i].u,g[i].v);
		//cout << g[i].u << " " << g[i].v << '\n';
		ans += g[i].w;
		if(cnt[g[i].v] == n)break;
	}
	cout << ans;
	return;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
