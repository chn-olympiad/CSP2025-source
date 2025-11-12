#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

namespace IO {
	const int MAX_SIZE = 1 << 20;
	
	char buf[MAX_SIZE], *p1 = buf, *p2 = buf;
	char gc() {
		return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAX_SIZE, stdin), p1 == p2) ? EOF : *p1++;
	}
	template <typename T> void R(T &x) {
		x = 0;
		bool sign = 0;
		char ch = gc();
		while (ch < '0' || ch > '9') sign |= ch == '-', ch = gc();
		while (ch >= '0' && ch <= '9') {
			x = (x << 3) + (x << 1) + (ch ^ 48);
			ch = gc();
		}
		if (sign) x = -x;
	}
}
using IO::R;

const int maxn = 1e4 + 5, maxm = 1e6 + 5;

struct edge{
	int from, to, w;
	bool operator <(const edge &a) const{
		return w < a.w;
	}
}e[maxm << 1];

int prt[maxn + 10];
int find(int x){
	while(x ^ prt[x]) x = prt[x] = prt[prt[x]];
	return x;
}

int n, m, k, len;
bool chose[15];
long long Kruskal(int cho){
	for(int i = 1; i <= n + k; ++i) prt[i] = i;
	long long ans = 0;
	int cnt = 0;
	for(int i = 1; i <= len; ++i){
		int u = find(e[i].from), v = find(e[i].to);
		if((e[i].from > n && !chose[e[i].from - n]) || (e[i].to > n && !chose[e[i].to - n])) continue;
		if(u ^ v){
			ans += e[i].w;
			prt[u] = v;
			if(++cnt == n + cho - 1) return ans;
		}
	}
	return 0x3f3f3f3f;
}

int c[maxn];
void solve() {
	R(n), R(m), R(k);
	len = m;
	for(int i = 1; i <= m; ++i) R(e[i].from), R(e[i].to), R(e[i].w);
	bool all_zero = 1;
	for(int i = 1; i <= k; ++i){
		R(c[i]);
		if(c[i]) all_zero = 0;
		for(int j = 1; j <= n; ++j)
			R(e[++len].w), e[len].from = j, e[len].to = n + i;
	}
	sort(e + 1, e + len + 1);
	int en = 1 << k;
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = en - 1; i >= 0; --i){
		if(all_zero && i < en - 1) break;
		for(int j = 1; j <= k; ++j) chose[j] = 0;
		int _cnt = 0;
		long long sum = 0;
		for(int j = 0; j < k; ++j)
			if(1 << j & i) chose[j + 1] = 1, ++_cnt, sum += c[j + 1];
		ans = min(ans, Kruskal(_cnt) + sum);
	}
	printf("%lld", ans);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	solve();
	return 0;
}