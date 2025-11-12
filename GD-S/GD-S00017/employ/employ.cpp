#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define gc getchar
template<typename T> void read(T &x) {x=0; char c, s = 1;while (!isdigit(c=gc())) if (c=='-') s = -1;for (; isdigit(c); c=gc()) x = (x<<1)+(x<<3)+(c^48);x*=s;}
template<typename TT, typename ...T> void read(TT &x, T &...y) {read(x), read(y...);}
int n, m, ans, a[100], v[100], s[100], b[100];
void dfs(int pos) {
	if (pos == n+1) {
		int w = 0;
		rep(i, 1, n) {
			if (i-w-1 < b[a[i]] && s[i]) w++;
		}
		if (w >= m) ans++;
		return;
	}
	rep(i, 1, n) {
		if (v[i]) continue;
		v[i] = 1;
		a[pos] = i;
		dfs(pos+1);
		v[i] = 0;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	read(n, m);
	char c;
	while (isspace(c=gc()));
	rep(i, 1, n) s[i] = c-'0', c = gc();
	rep(i, 1, n) read(b[i]);
	dfs(1);
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
