#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define ll long long
#define space putchar(' ')
#define enter putchar('\n')
using namespace std;

typedef vector <int> vi;
typedef pair <int, int> pii;

template <typename T> inline void rd(T& x) {
	x = 0; int f = 1;
	char c = getchar();
	while (!isdigit(c)) f = c == '-' ? -1 : f, c = getchar();
	while (isdigit(c)) x = (x<<3)+(x<<1)+(c^48), c = getchar();
	x *= f;
}

template <typename T> inline void write(T x) {
	if (x < 0) x = -x, putchar('-');
	static short s[20], _ = 0;
	do s[++_] = x%10, x /= 10; while (x);
	while (_) putchar(s[_--]|48);
}

template <typename T, typename ...Args> inline void rd(T &x, Args&... _) { rd(x); rd(_...); }

const int N = 2e5+5;
int n, q, p1[N], p2[N];
string s1[N], s2[N], t1, t2;
vector <pii> v1[N], v2[N];

void solve1() {
	cin >> t1 >> t2; int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int x = t1.find(s1[i]);
		if (x == -1) continue;
		string _ = t1.substr(0, x)+s2[i]+t1.substr(x+s1[i].size());
		if (_ == t2) ++ans;
	}
	write(ans), enter;
}

void solve2() {
	cin >> t1 >> t2;
	int x, y, p, q, ans = 0;
	for (int i = 0; t1[i]; ++i) if (t1[i] == 'b') x = i;
	for (int i = 0; t2[i]; ++i) if (t2[i] == 'b') y = i;
	if (x < y) {
		p = x, q = t2.size()-y-1;
		for (pii t:v1[y-x]) if (p >= t.fi && q >= t.se) ++ans;
	}
	if (x > y) {
		p = y, q = t1.size()-x-1;
		for (pii t:v2[x-y]) if (p >= t.fi && q >= t.se) ++ans;
	}
	write(ans), enter;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	rd(n, q); bool flag = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> s1[i] >> s2[i];
		int c1 = 0, c2 = 0;
		for (int j = 0; s1[i][j]; ++j) {
			if (s1[i][j] != 'a' && s1[i][j] != 'b') flag = 0;
			c1 += s1[i][j] == 'b';
		}
		for (int j = 0; s2[i][j]; ++j) {
			if (s2[i][j] != 'a' && s2[i][j] != 'b') flag = 0;
			c2 += s2[i][j] == 'b';
		}
		if (c1 != 1 || c2 != 1) flag = 0;
	}
	if (flag) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; s1[i][j]; ++j) if (s1[i][j] == 'b') p1[i] = j;
			for (int j = 0; s2[i][j]; ++j) if (s2[i][j] == 'b') p2[i] = j;
			if (p1[i] < p2[i]) v1[p2[i]-p1[i]].pb({p1[i], s2[i].size()-p2[i]-1});
			if (p1[i] > p2[i]) v2[p1[i]-p2[i]].pb({p2[i], s1[i].size()-p1[i]-1});
		}
		while (q--) solve2();
	}
	else {
		while (q--) solve1();
	}
	return 0;
}
