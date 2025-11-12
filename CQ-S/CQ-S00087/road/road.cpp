#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
#define rep(i, j, k) for(int i = (j); i <= (k); i ++)
#define per(i, j, k) for(int i = (j); i >= (k); i --)
#define pb emplace_back
#define fi first
#define se second
using vi = vector<int>;
using pi = pair<int, int>;

template<typename T0, typename T1> bool chmin(T0 &x, const T1 &y){
	if(y < x){x = y; return true;} return false;
}
template<typename T0, typename T1> bool chmax(T0 &x, const T1 &y){
	if(x < y){x = y; return true;} return false;
}

template<typename T> void debug(char *s, T x){
	cerr << s <<" = "<< x << endl;
}
template<typename T, typename ...Ar> void debug(char *s, T x, Ar... y){
	int dep = 0;
	while(!(dep == 0 && *s == ',')){
		if(*s == '(') dep ++;
		if(*s == ')') dep --;
		cerr << *s ++;
	}
	cerr << " = " << x << ",";
	debug(s + 1, y...);
}
#define gdb(...) debug((char*)#__VA_ARGS__, __VA_ARGS__)

const int inf = 1e18;

struct dsu{
	vi fa;
	dsu(int n){
		fa.assign(n, -1);
	}
	int find(int u){
		return fa[u] < 0? u: fa[u] = find(fa[u]);
	}
	bool merge(int u, int v){
		if((u = find(u)) == (v = find(v))){
			return false;
		}
		fa[u] = v;
		return true;
	}
};

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector< tuple<int, int, int> > E(m);
	for(auto &[w, u, v]:E){
		cin >> u >> v >> w;
		u --, v --;
	}
	vi c(k);
	vector<vi> a(k, vi(n));
	rep(i, 0, k - 1){
		cin >> c[i];
		rep(j, 0, n - 1){
			cin >> a[i][j];
		}
	}
	sort(E.begin(), E.end());
	{
		dsu S(n);
		vector< tuple<int, int, int> > tmp;
		for(auto [w, u, v]:E){
			if(S.merge(u, v)){
				tmp.pb(w, u, v);
			}
		}
		E = move(tmp);
	}
	
	int ans = inf;

	rep(s, 0, (1 << k) - 1){
		dsu S(n + k);
		vector< tuple<int, int, int> > e = E;

		int cost = 0;
		rep(j, 0, k - 1){
			if(s >> j & 1){
				cost += c[j];
				rep(i, 0, n - 1){
					e.pb(a[j][i], n + j, i);
				}
			}
		}
		sort(e.begin(), e.end());
		for(auto [w, u, v]:e){
			if(S.merge(u, v)){
				cost += w;
			}
		}
		chmin(ans, cost);
	}
	cout << ans <<'\n';
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
