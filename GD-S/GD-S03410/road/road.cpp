#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+100,M = 120000,K=11;
int n,m,k;
struct edge{
	int f;
	int t;
	long long w;
	edge(int ff,int tt,long long ww) {
		f = ff;
		t = tt;
		w = ww;
	}
	bool operator < (const edge &other) {
		return w < other.w;
	}
};
vector<edge> rd;
int boss[N];
long long val[N],cts[N][K],c[K];
void init() {
	for (int i = 1; i <= n; i++) {
		boss[i] = i;
	}
}
int find(int x) {
	return x == boss[x] ? x : boss[x] = find(boss[x]);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	init();
	for (int i = 0; i < m; i++) {
		int f,t;
		long long w;
		scanf("%d%d%lld",&f,&t,&w);
		rd.emplace_back(f,t,w);
	}
	for (int i = 0; i < k; i++) {
		scanf("%d",&c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%lld",&cts[i][j]);
		}
	}
	sort(rd.begin(),rd.end());
	int stp = 0;
	long long ret = 0;
	for (int i = 0; i < rd.size(); i++) {
		int x = find(rd[i].f),y = find(rd[i].t);
		if (x != y) {
			ret += rd[i].w;
			boss[x] = boss[y];
			stp++;
		}
		if (stp == n - 1) break;
	}
	printf("%lld\n",ret);
	return 0;
}
