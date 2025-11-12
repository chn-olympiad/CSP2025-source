#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;
const int INF = 1e9+7;
const ll LLINF = (ll)1e18+7;
const lf LFINF = (lf)1e18+7;
const int maxn = 1e4+5;
const int maxm = 1e6+5;
const int maxk = 15;
int T, N, M, K;
ll ans = LLINF;
ll c[maxk];
int fa[maxn+maxk], siz;

struct node{
	ll w;
	int u, v, from;
	
	bool operator < (const node &x) const{
		return w > x.w;
	}
};
priority_queue<node> Q;
node a[maxk][maxn];

bool inline isdig(const char &ch){
	return ch >= '0' && ch <= '9';
}

template <typename type>
void inline read(type &x){
	x = 0; type f = 1;
	char ch = getchar();
	while (!isdig(ch)){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdig(ch)) x = x*10+ch-'0', ch = getchar();
	x = x*f;
} 

void init_fa(int l = 1, int r = N){
	for (int i = 1; i <= N; i++) fa[i] = i;
	siz = r-l+1;
}

stack<int> st;
inline int getf(int x){
	while (fa[x] != x){
		st.push(x);
		x = fa[x];
	}
	while (!st.empty()){
		fa[st.top()] = x;
		st.pop();
	}
	return x;
}

inline void merge(const int &u, const int &v){
	int fu = getf(u);
	int fv = getf(v);
	if (fu == fv) return;
	fa[fu] = fv;
	siz--;
}

bool vis[maxk]; int p[maxk];
void dfs(int now, ll res){
	if (res > ans) return;
	if (now > K){
		while (!Q.empty()) Q.pop();
		
		init_fa();
		for (int i = 0; i <= K; i++){
			if (vis[i]){
				if (i){
					fa[i+N] = i+N;
					siz++;
				}
				p[i] = i == 0 ? N-1 : N;
				Q.push(a[i][p[i]]);
			}
		}
		while (siz > 1){
			node now = Q.top(); Q.pop();
			if (p[now.from] > 1) Q.push(a[now.from][--p[now.from]]);		
			if (getf(now.u) != getf(now.v)){
				res += now.w;
				merge(now.u, now.v);
			}
		}
		ans = min(ans, res);
		
		return;
	}
	
	vis[now] = 0;
	dfs(now+1, res);
	vis[now] = 1;
	dfs(now+1, res+c[now]);
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	read(N); read(M); read(K);
	for (int i = 1; i <= M; i++){
		int u, v; ll w;
		read(u); read(v); read(w);
		Q.push({w, u, v, 0});
	}
	for (int i = 1; i <= K; i++){
		read(c[i]);
		for (int j = 1; j <= N; j++){
			a[i][j].u = N+i; a[i][j].v = j; 
			read(a[i][j].w);
			a[i][j].from = i;
		}
		sort(a[i]+1, a[i]+N+1);
	}
	
	init_fa();
	ll res = 0;
	int cur = N;
	while (siz > 1){
		node now = Q.top(); Q.pop();
		if (getf(now.u) != getf(now.v)){
			res += now.w;
			merge(now.u, now.v);
			a[0][--cur] = now;
		}
	}
	while (!Q.empty()) Q.pop();
		
	ans = res;
	vis[0] = 1;
	dfs(1, 0);
	
	printf("%lld\n", ans);
	
	
	
	return 0;
}
