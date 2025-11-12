#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ri register int
#define inl inline
#define rep(i,l,r) for(ri i = l;i <= r; i ++)
#define per(i,r,l) for(ri i = r;i >= l; i --)
#define N 10005
#define M 10000005
int n, m, k, fa[N];
inl int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
struct ss{
	int u, v, w;
}e[M];
int c[15][N], bc[15];
inl bool cmp(ss x, ss y){
	return x.w < y.w; 
}
struct cmmp{
	bool operator()(ss &x, ss &y){
		return x.w > y.w;
	}
};
priority_queue<ss, vector<ss>, cmmp> q;
inl bool check(){
	int fx = find(1);
	rep(i, 2, n){
		if(find(i) != fx) return 0;
	}
	return 1;
}
bool vis[15];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	rep(i, 1, m) cin >> e[i].u >> e[i].v >> e[i].w;
	rep(i, 1, k){
		cin >> bc[i];
		rep(j, 1, n) cin >> c[i][j], q.push(ss{n + i, j, bc[i] + c[i][j]}), q.push(ss{j, n + i, bc[i] + c[i][j]});
	}
	sort(e + 1, e + 1 + m, cmp);
	int tot = 0, ans = 0;
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, m){
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fx = find(u), fy = find(v);
		if(fx != fy){
			fa[fx] = fa[fy];
			ans += w;
			q.push(e[i]);
		}
	}
	if(k == 0) cout << ans;
	else{
		ans = 0;
		rep(i, 1, n + k) fa[i] = i;
		while(!check()){
			ss t = q.top();
			q.pop();
			int u = t.u, v = t.v, w = t.w;
			int fx = find(u), fy = find(v);
			if(fx != fy){
				if(u > n){
					if(!vis[u - n]){
						vis[u - n] = 1;
						rep(j, 1, n) q.push(ss{u, j, c[u - n][j]}), q.push(ss{j, u,c[u - n][j]});
					}
				}
				if(v > n){
					if(!vis[v - n]){
						vis[v - n] = 1;
						rep(j, 1, n) q.push(ss{v, j, c[v -n][j]}), q.push(ss{j, v,c[v-n][j]});
					}
				}
				fa[fx] = fa[fy];
				ans += w;
			}
		}
		cout << ans;
	}
	return 0;
}

