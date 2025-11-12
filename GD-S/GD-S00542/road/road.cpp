#include<bits/stdc++.h>
using namespace std;

#define F(i, l, r) for(int i = (l); i <= (r); ++i)
#define dF(i, r, l) for(int i = (r); i >= (l); --i)
#define pb push_back
#define vi vector<int>

template<typename T> void debug(string s, T x) {
	cerr << "[" << s << "] = [" << x << "]\n";
}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {
	int t = 0;
	F(i, 0, (int)s.size() - 1) if(s[i] =='(') t++;
	else if(s[i] == ')') t--;
	else if(s[i] == ',' && !t) {
		cerr << "[" << s.substr(0, i) << "] = [" << x << "] | ";
		debug(s.substr(s.find_first_not_of(' ', i + 1)), args...);
		break;
	}
}

#ifdef orzz
#define Debug(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define Debug(...) 
#endif

int ri() {
	int x = 0,f = 1;
	char c = getchar();
	while(c < '0' ||c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - 48;
		c = getchar();
	} return x * f;
}

const int _ = 1e4 + 5;

int n, m, k, c[_];

struct edge {
	int u, v, w;
} e[1000005], e2[11][_], e3[_];

vector<edge> e4[(1<<5)+2], e5[(1<<5)+2];

int fa[_], sz[_]; int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void merge(int u, int v) {
	if(sz[u] > sz[v]) swap(u, v);
	fa[u] = v;
	sz[v] += sz[u];
}

#define Try fprintf(stderr, "Time = %.4lf s\n", 1. * (clock()) / CLOCKS_PER_SEC)

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w",stdout);
	n = ri(), m = ri(), k = ri();
	F(i, 1, m) {
		e[i].u = ri(), e[i].v = ri(), e[i].w = ri();
	}
	F(i, 1, k) {
		c[i] = ri();
		F(j, 1, n) {
			e2[i][j].u = i + n, e2[i][j].v = j, e2[i][j].w = ri();
		}
		sort(e2[i] + 1, e2[i] + n + 1, [&](const edge &a, const edge &b) { return a.w < b.w;});
	}
	sort(e + 1, e + m + 1, [&](const edge &a, const edge &b) { return a.w < b.w;});
	F(i, 1, n) fa[i] = i;
	int M = 0;
	long long ans = 0;
	F(i, 1, m) {
		int u = e[i].u, v = e[i].v;
		if(find(u) == find(v)) continue;
		e3[++M] = e[i];
		fa[find(u)] = find(v);
		ans += e[i].w;
	}
	Debug(ans);
	m = M;
	F(i, 1, m) e[i] = e3[i];
	vector<edge> B;
	F(i, 1, m) B.pb(e[i]);
	int mid = k / 2;
	F(s, 0, (1 << mid) - 1) {
		vector<edge> C;
		F(j, 1, mid) if(s >> (j - 1) & 1) {
			C.resize(e4[s].size()+n);
			merge(e4[s].begin(), e4[s].end(), e2[j]+1, e2[j]+n+1, C.begin(), [&](const edge &a, const edge &b) { return a.w < b.w;});
			e4[s] = C;
		}
	}
	F(s, 0, (1 << (k - mid)) - 1) {
		vector<edge> C;
		F(j, mid + 1, k) if(s >> (j - mid - 1) & 1) {
			C.resize(e5[s].size()+n);
			merge(e5[s].begin(), e5[s].end(), e2[j]+1, e2[j]+n+1, C.begin(), [&](const edge &a, const edge &b) { return a.w < b.w;});
			e5[s] = C;
		}
	}
	Try;
	const int Z = (1 << mid) - 1;
	const int Z2 = ((1 << k) - 1) ^ Z;
	F(s, 0, (1 << k) - 1) {
		F(i, 1, n + k) fa[i] = i, sz[i] = 1;
		vector<edge> A = B, C;
		{
			int s2 = s & Z;
			C.resize(A.size()+e4[s2].size());
			merge(A.begin(), A.end(), e4[s2].begin(), e4[s2].end(), C.begin(), [&](const edge &a, const edge &b) { return a.w < b.w;});
			A = C;
		}
		{
			int s2 = (s & Z2) >> mid;
			C.resize(A.size()+e5[s2].size());
			merge(A.begin(), A.end(), e5[s2].begin(), e5[s2].end(), C.begin(), [&](const edge &a, const edge &b) { return a.w < b.w;});
			A = C;
		}
		long long ans2 = 0;
		F(j, 1, k) if(s >> (j - 1) & 1) ans2+=c[j];
		// int Z = 0;
		// F(j, 1, k) if(s >> (j - 1) & 1) {
		// 	C.resize(A.size() + n);
		// 	merge(A.begin(), A.end(), e2[j] + 1, e2[j] + n + 1, C.begin(), [&](const edge &a, const edge &b) { return a.w < b.w;});
		// 	A = C;
		// 	ans2 += c[j];
		// 	Z++;
		// }
		for(auto &[u, v, w] : A) {
			if(find(u) == find(v)) continue;
			ans2 += w;
			merge(find(u), find(v));
			// if(sz[find(u)] == n + Z) break;
		}
		// Debug(s, __builtin_popcount(s), A.size(), ans2);
		ans = min(ans, ans2);
	}
	cout << ans << '\n';
	Try;
}