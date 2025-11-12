#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;
int u[1000010], v[1000010], w[1000010];
int c[15], d[15][10010];
int fa[10050];
int query(int x){
	if(fa[x] == x) return x;
	return fa[x] = query(fa[x]);
}
struct dat{
	int u, v;
	int len;
};
inline bool operator<(const dat& a, const dat& b){
	return a.len < b.len;
}
ll mn = LLONG_MAX;
vector<dat> vec;
vector<dat> sec;
ll mst(int stat){
	sec.clear();
	ll ans = 0;
	int cnt = n, num = 0;
	for(int i = 1; i <= k; i ++){
		if(stat & (1 << (i - 1))){
			ans += c[i];
			cnt ++;
			num ++;
			for(int j = 1; j <= n; j ++) sec.push_back({n + i, j, d[i][j]});
		}
	}
	for(int i = 1; i <= n + k; i ++) fa[i] = i;
	sort(sec.begin(), sec.end());
	sec.push_back({-1, -1, INT_MAX});
	int ptr = 0, ps = 0;
	while(cnt > 1){
		int st, en, len;
		if(vec[ptr] < sec[ps]){
			st = vec[ptr].u, en = vec[ptr].v, len = vec[ptr].len;
			ptr ++;
		}else{
			st = sec[ps].u, en = sec[ps].v, len = sec[ps].len;
			ps ++;
		}
		if(query(st) != query(en)){
			ans += len;
			if(ans > mn) return LLONG_MAX;
			cnt --;
			fa[query(st)] = query(en);
		}
	}
	return ans;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++) cin >> u[i] >> v[i] >> w[i];
	for(int i = 1; i <= m; i ++) vec.push_back({u[i], v[i], w[i]});
	sort(vec.begin(), vec.end());
	vec.push_back({-1, -1, INT_MAX});
	for(int i = 1; i <= k; i ++){
		cin >> c[i];
		for(int j = 1; j <= n; j ++) cin >> d[i][j];
	}
	for(int i = 0; i < (1 << k); i ++) mn = min(mn, mst(i));
	cout << mn;
}