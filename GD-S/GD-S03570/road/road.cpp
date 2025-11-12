//56pts
#include<bits/stdc++.h>
//bool Mst;
#define ll long long
using namespace std;
const int K = 15;
const int N = 1e4 + K;
const int M = 1e6 + N * K;
int n, m, k, cntn, cntm;
int c[K], a[K][N], fa[N];
struct node{
	int v, u;
	ll w;
}vt0[M], vt[M];
ll ans;
int Get(int x){
	return fa[x] == x ? x : fa[x] = Get(fa[x]);
}
bool cmp(node x, node y){
	return x.w < y.w;
}
ll Kru(){
	for(int i = 1; i <= cntn; ++i) fa[i] = i;
	sort(vt + 1, vt + cntm + 1, cmp);
	ll res = 0;
	for(int i = 1; i <= cntm; ++i){
		int x = Get(vt[i].u);
		int y = Get(vt[i].v);
		ll w = vt[i].w;
		if(x == y) continue;
		fa[x] = y;
		res += w;
	}
	return res;
}
void dfs(int x, string s){
	if(x == k){
		ll res = 0;
		cntm = m;
		cntn = n;
		for(int i = 1; i <= m; ++i) vt[i] = vt0[i];
		s = ' ' + s;
		for(int i = 1; s[i]; ++i){
			if(s[i] == '1'){
				res += c[i];
				++cntn;
				for(int j = 1; j <= n; ++j){
					vt[++cntm] = {cntn, j, a[i][j]};
				}
			}
		}
		res += Kru();
//		cerr << s << ' ' << res << '\n';
		ans = min(ans, res);
		return ;
	}
	++x;
	dfs(x, s + '0');
	dfs(x, s + '1');
	return ;
}

//bool Med;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	cerr << abs((&Med) - (&Mst)) / 1024.0 / 1024 << "MB\n";
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i)
		cin >> vt0[i].u >> vt0[i].v >> vt0[i].w;
	
	bool flagA = 1;
	for(int i = 1; i <= k; ++i){
		cin >> c[i];
		if(c[i]) flagA = 0;
		for(int j = 1; j <= n; ++j){
			cin >> a[i][j];
		}
	}
	if(flagA){
		cntm = m;
		cntn = n;
		for(int i = 1; i <= m; ++i) vt[i] = vt0[i];
		for(int i = 1; i <= k; ++i){
			++cntn;
			for(int j = 1; j <= n; ++j){
				vt[++cntm] = {cntn, j, a[i][j]};
			}
		}
		cout << Kru();
	}
	else if(k){
		ans = 1e18;
		dfs(0, "");
		cout << ans;
	}
	else {
		cntm = m;
		cntn = n;
		for(int i = 1; i <= m; ++i) vt[i] = vt0[i];
		cout << Kru();
	}
	
	return 0;
}
