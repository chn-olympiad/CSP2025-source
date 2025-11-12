/*
clear && ulimit -s 1024000 && g++ % -o %< -O2 -std=c++14 -DLOCAL -Wall -Wextra -Wshadow -Wconversion && ulimit -v 128000 && time ./%< && size %<
clear && ulimit -s 1024000 && g++ % -o %< -O2 -std=c++14 -DLOCAL -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined -g && ./%<
echo && cat out.out && echo
*/
#include <bits/stdc++.h>
using namespace std;
using llt = long long;
using llf = long double;
using ull = unsigned long long;
template<class T> void Cmin(T &a, T b){ if(a > b) a = b; }
template<class T> void Cmax(T &a, T b){ if(a < b) a = b; }
#define endl '\n'
#ifdef LOCAL
FILE *InFile = freopen("in.in", "r", stdin), *OutFile = freopen("out.out", "w", stdout);
#else
FILE *InFile = freopen("road.in", "r", stdin), *OutFile = freopen("road.out", "w", stdout);
#endif

const int N = 1e4 + 3, M = 1e6 + 3, K = 13;
int n, m, _k, _c[K]; llt aas = 0x3f3f3f3f3f3f3fll;
vector<tuple<int, int, int>> _e, ce; vector<pair<int, int>> ke[K];

class Dsu{
private:
	int f[N + K], sz[N + K];
public:
	int F(int u){ return f[u] ? f[u] = F(f[u]) : u; }
	void Uni(int u, int v){ u = F(u), v = F(v); if(u != v) sz[u] > sz[v] && (swap(u, v), 1), f[u] = v, sz[v] += sz[u]; }
	void Clr(){ for(int i = 1; i <= n + _k; ++i) f[i] = 0, sz[i] = 1; }
} uf;

llt Chk(int s){
	uf.Clr();
	auto pe = ce.begin(); vector<pair<int, int>>::iterator pk[K];
	llt sm = 0;
	for(int k = 0; k < _k; ++k){
		pk[k] = ke[k].begin();
		if(s >> k & 1) sm += _c[k];
	}
	for(int i = 1, _ = n + __builtin_popcount(s); i < _; ++i){
		int u = 0, v = 0, w = 0x3f3f3f3f;
		while(pe != ce.end()){
			tie(w, u, v) = *pe;
			if(uf.F(u) == uf.F(v)) ++pe;
			else break;
		}
		for(int k = 0; k < _k; ++k) if(s >> k & 1){
			int nu = n + k + 1, nv = 0, nw = 0x3f3f3f3f;
			while(pk[k] != ke[k].end()){
				tie(nw, nv) = *pk[k];
				if(uf.F(nu) == uf.F(nv)) ++pk[k];
				else break;
			}
			if(nw < w) u = nu, v = nv, w = nw;
		}
		sm += w, uf.Uni(u, v);
	}
	return sm;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> _k;
	for(int i = 1, u, v, w; i <= m; ++i) cin >> u >> v >> w, _e.emplace_back(w, u, v);
	sort(_e.begin(), _e.end()); for(auto [w, u, v] : _e) if(uf.F(u) != uf.F(v)) uf.Uni(u, v), ce.emplace_back(w, u, v);
	for(int i = 0; i < _k; ++i){
		cin >> _c[i];
		for(int j = 1, w; j <= n; ++j) cin >> w, ke[i].emplace_back(w, j);
		sort(ke[i].begin(), ke[i].end());
	}
	for(int s = 0, _ = (1 << _k) - 1; s < _; ++s) Cmin(aas, Chk(s));
	cout << aas;
}
