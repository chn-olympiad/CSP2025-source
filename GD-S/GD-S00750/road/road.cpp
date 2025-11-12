#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define Rep(i,a,b) for(int i = (a);i >= (b);--i)

int read(){
//	int x;scanf("%d",&x);return x;
	int x = 0;
	char c = getchar();
	for(;!isdigit(c);c = getchar());
	for(;isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return x;
}

using ll = long long;

const int N = 2e4 + 5;

int n,m,k,fa[N],C[15];
ll ans;
vector<tuple<int,int,int> > E[15],G[15];

int fnd(int x){ return x == fa[x] ? x : fa[x] = fnd(fa[x]); }

ll kruskal(int x,int id,ll sum){
	rep(i,1,n + k) fa[i] = i;
	E[x + 1].clear();
	for(int i = 0,j = 0;i < E[x].size() || j < G[id].size();){
		int u1,v1,w1 = 2e9,u2,v2,w2 = 2e9;
		if(i < E[x].size()) tie(w1,u1,v1) = E[x][i];
		if(j < G[id].size()) tie(w2,u2,v2) = G[id][j];
		if(w1 < w2){
			if(fnd(u1) != fnd(v1)) fa[fnd(u1)] = fnd(v1),sum += w1,E[x + 1].push_back(E[x][i]);
			++i;
		} else {
			if(fnd(u2) != fnd(v2)) fa[fnd(u2)] = fnd(v2),sum += w2,E[x + 1].push_back(G[id][j]);
			++j;
		}
//		if(sum > ans) return 1e18;
	}
	return sum;
}

void dfs(int x,int i,ll sc){
	if(i == k) return;
	dfs(x,i + 1,sc);
	sc += C[i];
	ll val = kruskal(x,i,sc);
	ans = min(ans,val);
	dfs(x + 1,i + 1,sc);
}

int main(){
//	return system("fc road.out road4.ans");
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(),m = read(),k = read();
	rep(i,1,m){
		int u,v,w;
		u = read(),v = read(),w = read(),E[0].emplace_back(w,u,v);
	}
	rep(i,0,k - 1){
		C[i] = read();
		rep(j,1,n) G[i].emplace_back(read(),i + n + 1,j);
		sort(begin(G[i]),end(G[i]));
	}
	sort(begin(E[0]),end(E[0]));
	ans = 1e18,ans = min(ans,kruskal(0,k,0)),E[0] = E[1];
	dfs(0,0,0);
	printf("%lld\n",ans);
	return 0;
}
