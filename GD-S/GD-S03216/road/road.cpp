#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e4 + 10;
const int MXM = 1e6;
const int MXK = 10;
const int INFi = 0x3f3f3f3f;
const long long INFll = 0x3f3f3f3f3f3f3f3f;

int n, m, k, c[MXK], a[MXK][MXN];
struct edge{
	int u, v, w;
}e[MXM], t[MXM];
long long ns = INFll;
int cnt, tp;
struct DSU{
	int f[MXN];

	void clear(){
		int i;
		for(i = 0;i < n + k;++i) f[i] = i;
	}

	int fnd(int x){
		return x != f[x] ? f[x] = fnd(f[x]) : x;
	}
}f;

int read(){
	int x = 0;
	char c = getchar();
	for(;c < '0' || c > '9';) c = getchar();
	for(;c >= '0' && c <= '9';c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	return x;
}

bool cmp(edge x, edge y){
	return x.w < y.w;
}

void pre_kruskal(){
	int i;
	sort(e, e + m, cmp);
	f.clear();
	for(i = 0;i < m;++i){
		int u = f.fnd(e[i].u), v = f.fnd(e[i].v);
		if(u != v){
			t[cnt++] = e[i];
			f.f[u] = v;
		}
	}
}

long long work_kruskal(){
	int i;
	long long res = 0;
	sort(e, e + tp, cmp);
	f.clear();
	for(i = 0;i < tp;++i){
		int u = f.fnd(e[i].u), v = f.fnd(e[i].v), w = e[i].w;
		if(u != v){
			res += w;
			f.f[u] = v;
		}
	}
	return res;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int i, j, s;
	n = read();
	m = read();
	k = read();
	for(i = 0;i < m;++i){
		e[i].u = read() - 1;
		e[i].v = read() - 1;
		e[i].w = read();
	}
	for(i = 0;i < k;++i){
		c[i] = read();
		for(j = 0;j < n;++j) a[i][j] = read();
	}
	pre_kruskal();
	for(s = 0;s < (1 << k);++s){
		long long res = 0;
		for(i = 0;i < k;++i)
			if(s >> i & 1) res += c[i];
		for(i = 0;i < cnt;++i) e[i] = t[i];
		tp = cnt;
		for(i = 0;i < n;++i){
			int b = INFi, id;
			for(j = 0;j < k;++j)
				if((s >> j & 1) && a[j][i] < b){
					b = a[j][i];
					id = j;
				}
			if(b != INFi) e[tp++] = {i, id + n, b};
		}
		res += work_kruskal();
		ns = min(ns, res);
	}
	printf("%lld", ns);
	return 0;
}
