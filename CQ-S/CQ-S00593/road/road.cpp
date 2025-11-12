//luogu uid 755230 jzc114514
//80+
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define fs first
#define se second
#define pii pair<int, int>
#define db double
#define lp (p * 2)
#define rp (p * 2 + 1)
#define all(s) s.begin(), s.end()
using namespace std;
inline void cmax(int &a, int b){if(a < b)a = b;}
inline void cmin(int &a, int b){if(a > b)a = b;}
const int N = 1e4 + 50;
struct UnionFind{
	int f[N] = {};
	void unionfind(int n){
		for(int i = 1; i <= n; i ++)f[i] = i;
	}
	inline int find(int x){
		return x == f[x] ? x : f[x] = find(f[x]);
	}
	void merge(int a, int b){
		int aa = find(a), bb = find(b);
		if(aa == bb)return ;
		f[aa] = bb;
	}
	bool connected(int a, int b){
		return find(a) == find(b);
	}
};
int kruskal(int n, vector<pair<int, pii>>edge){
	int ans = 0;
	UnionFind f;
	f.unionfind(n);
	sort(all(edge));
	for(auto tmp : edge){
		int a = tmp.se.se, b = tmp.se.fs, w = tmp.fs;
//		cout << a << " " << b << " " << w << "\n";
		if(!f.connected(a, b)){
			f.merge(a, b);
			ans += w;
		}
	}
//	cout << "-------------\n";
	return ans;
}
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, pii>>edge, g;
	for(int i = 1; i <= m; i ++){
		int a, b, w; cin >> a >> b >> w;
		edge.push_back({w, {a, b}});
	}
	int ans = 0;
	UnionFind f;
	f.unionfind(n);
	sort(all(edge));
	for(auto tmp : edge){
		int a = tmp.se.se, b = tmp.se.fs, w = tmp.fs;
		if(!f.connected(a, b))
			f.merge(a, b),
			ans += w,
			g.push_back(tmp);
	}
	if(k == 0){
		cout << ans;
		return ;
	}
	int s[12][N] = {}, c[N] = {};
	for(int i = 1; i <= k; i ++){
		cin >> c[i];
		for(int j = 1; j <= n; j ++)
			cin >> s[i][j];
	}
	vector<pair<int, pii> > tmp = g;
	for(int i = 1; i < (1 << k); i ++){
		int res = 0;
		for(int j = 1; j <= k; j ++)
			if(i >> (j - 1) & 1){
				for(int w = 1; w <= n; w ++)
					g.push_back({s[j][w], {j + n, w}});
				res += c[j];
			}
		cmin(ans, res + kruskal(n + 10, g));
		g = tmp;
	}
	cout << ans;
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T --){
		solve();
	}
}
