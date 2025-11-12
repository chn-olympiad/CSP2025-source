#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
using namespace std;
using ll = long long;
const int N = 1e4 + 5, M = 2e6 + 5;
int n, m, k;
int c[15], val[15][N];
int p[N + 10];
int n0, m0;

struct edge{
	int u, v, w;
	friend bool operator < (edge x, edge y){
		return x.w < y.w;
	}
}e[M], e2[M], e0[M];

int get(int x){
	if(p[x] == x)	return x;
	return p[x] = get(p[x]);
}

ll sol(){
	for(int i = 1;i <= n0;i++)	p[i] = i;
	for(int i = 1;i <= m0;i++)	e2[i] = e[i];
	sort(e2 + 1, e2 + m0 + 1);
	ll res = 0;
	int cnt = 0;
	for(int i = 1;i <= m0;i++){
		int u = e2[i].u, v = e2[i].v, w = e2[i].w;
		if(get(u) == get(v)){
			continue;
		}
		cnt++;
		p[get(u)] = get(v);
		res += w;
		if(cnt == n0 - 1)	break;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		int u, v, w;	cin>>u>>v>>w;
		e0[i] = {u, v, w};
	}
	sort(e0 + 1, e0 + m + 1);
	for(int i = 1;i <= n;i++)	p[i] = i;
	int tot = 0;
	for(int i = 1;i <= m;i++){
		int u = e0[i].u, v = e0[i].v, w = e0[i].w;
		if(get(u) == get(v))	continue;
		p[get(u)] = get(v);
		e[++tot] = {u, v, w};
	}
	for(int i = 1;i <= k;i++){
		cin>>c[i];
		for(int j = 1;j <= n;j++)	cin>>val[i][j];
	}
	ll pans = LLONG_MAX;
	for(int zt = 0;zt <= (1 << k) - 1;zt++){
		m0 = tot;
		n0 = n;
		ll ans = 0;
		for(int i = 0;i <= k;i++)	if((zt >> i) & 1){
			n0++;
			ans += c[i + 1];
			for(int j = 1;j <= n;j++)	e[++m0] = {n0, j, val[i+1][j]};
		}
		pans = min(pans, sol() + ans);
	}
	cout<<pans;
	return 0;
}

