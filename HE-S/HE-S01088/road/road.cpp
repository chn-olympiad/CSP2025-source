#include<bits/stdc++.h>
#define int long long
using namespace std;
#define gc getchar_unlocked
void rd(int& x){
	x = 0; char c = 0;
	while(c < '0' || c > '9') c = gc();
	while(c <= '9' && c >= '0') (x *= 10) += c - '0' ,  c = gc();
}

const int M = 10010 , N = 1e6 + 5;
int n , m , m_ , k;
int c[12] , a[12][M] , fa[M] , ans;

int find(int x){ return fa[x] == x ? x : fa[x] = find(fa[x]); }
struct edge{ int u , v , w; }e[N] , e_[12][M << 1];
bool operator <(edge x , edge y){ return x.w < y.w; }

// cnt : count of village
// p : count of used village
void dfs(int cnt , int p , int sum){
	if(cnt == k) return ;
	dfs(cnt + 1 , p , sum);
	int q = p + 1 , s = m + p , m_ = 0 , val = sum + c[cnt];
	for(int i = 0; i < s; ++i) e_[q][i] = e_[p][i];
	for(int i = 1; i <= n; ++i , ++s){
		e_[q][s].w = a[cnt][i];
		e_[q][s].u = i , e_[q][s].v = n + q;
	}
	sort(e_[q] , e_[q] + s);
	for(int i = 1; i <= n + q; ++i) fa[i] = i;
	for(int i = 0; i < s; ++i){
		int u = find(e_[q][i].u) , v = find(e_[q][i].v);
		if(u == v) continue;
		fa[u] = v , val += e_[q][i].w;
		e_[q][m_++] = e_[q][i];
	}
	ans = min(ans , val);
	dfs(cnt + 1 , p + 1 , sum + c[cnt]);
}

signed main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

	rd(n) , rd(m), rd(k);
	for(int i = 0; i < m; ++i) rd(e[i].u) , rd(e[i].v) , rd(e[i].w);
	for(int i = 0; i < k; ++i){
		rd(c[i]);
		for(int j = 1; j <= n; ++j) rd(a[i][j]);
	}
	sort(e , e + m);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	int m_ = 0;
	for(int i = 0; i < m; ++i){
		int u = find(e[i].u) , v = find(e[i].v);
		if(u == v) continue;
		fa[u] = v , ans += e[i].w , e[m_++] = e[i];
	}
	m = m_;
/////////
	for(int i = 0; i < m; ++i) e_[0][i] = e[i];
	dfs(0 , 0 , 0);
	cout<<ans<<'\n';

	return 0;
}
// i'm not good at graph
// i'm not good at mst
// could O(n log n 2^k) be ok?