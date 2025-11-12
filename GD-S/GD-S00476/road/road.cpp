#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e6 + 10, M = 20;
const ll INF = 2e16;

ll n, m, k, p[N];
bool st[N];
struct EDGE{
	ll a, b, w;
	bool operator< (const EDGE &edge) const{
		return w < edge.w;
	}
}e[N], tmp[N];
struct NODE{
	ll c, val[N];
}A[M];

void init(){
	for(int i = 1; i <= n + k; i++) p[i] = i;
	for(int i = 1; i <= m; i++)
		tmp[i].a = e[i].a, tmp[i].b = e[i].b, tmp[i].w = e[i].w;
}

ll find(ll x){
	return x == p[x] ? x : p[x] = find(p[x]);
}

void kruskal_k0(){
	init();
	sort(e + 1, e + m + 1);
	ll res = 0;
	for(int i = 1; i <= m; i++){
		ll pa = find(e[i].a), pb = find(e[i].b);
		if(pa == pb) continue;
		p[pa] = pb, res += e[i].w;
	}
	printf("%lld\n", res);
}

ll kruskal_try(){
	init();
	sort(tmp + 1, tmp + m + 1);
	ll res = 0, cnt = n;
	vector<vector<ll>> dist(k + 1, vector<ll>(n + 1));
	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= n; j++) dist[i][j] = A[i].val[j];
	for(int i = 1; i <= m && cnt > 0; i++){
		ll pa = find(tmp[i].a), pb = find(tmp[i].b);
		if(pa == pb) continue;
		ll cur = tmp[i].w;
		for(int j = 1; j <= k; j++) if(st[j])
			cur = min(cur, dist[j][pa] + dist[j][pb]);
		p[pa] = pb, res += cur, cnt--;
	}
	return res;
}

void solve(){
	scanf("%lld %lld %lld", &n, &m, &k);
	for(int i = 1; i <= m; i++)
		scanf("%lld %lld %lld", &e[i].a, &e[i].b, &e[i].w);
	bool flagA = true;
	for(int i = 1; i <= k; i++){
		scanf("%lld", &A[i].c);
		if(A[i].c != 0) flagA = false;
		for(int j = 1; j <= n; j++) scanf("%lld", &A[i].val[j]);
	}
	if(k == 0){
		kruskal_k0();
	}else if(flagA){
		ll res = INF;
		for(int t = 0; t < (1 << k); t++){
			int tot = m, cnt = n;
			for(int ii = 0; ii < k; ii++) if((t >> ii) & 1ll){
				int i = ii + 1 + n;
				cnt++, st[ii + 1] = true;
				for(int j = 1; j <= n; j++)
					tmp[++tot] = {i, j, A[ii + 1].val[j]};
			}
//			res = min(res, kruskal_flagA(tot, cnt));
			res = min(res, kruskal_try());
			for(int i = 1; i <= k; i++) st[i] = false;
		}
		printf("%lld\n", res);
	}else{
		ll res = INF;
		for(int t = 0; t < (1 << k); t++){
			int tot = m, sum = 0, cnt = n;
			for(int ii = 0; ii < k; ii++) if((t >> ii) & 1ll){
				int i = ii + 1 + n;
				sum += A[ii + 1].c, cnt++, st[ii + 1] = true;
				for(int j = 1; j <= n; j++)
					tmp[++tot] = {i, j, A[ii + 1].val[j]};
			}
//			res = min(res, kruskal_k5(tot, cnt) + sum);
			res = min(res, kruskal_try() + sum);
			for(int i = 1; i <= k; i++) st[i] = false;
		}
		printf("%lld\n", res);
	}
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int T = 1;
//	scanf("%d", &T);
	while(T--) solve();
	return 0;
}
