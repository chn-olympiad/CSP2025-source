#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <type_traits>
#define For(i, s, t) for (int i = (s); i <= (t); ++i)
#define roF(i, t, s) for (int i = (t); i >= (s); --i)
using std::min; using std::max; using std::abs;
namespace FastI {
	char buf[1 << 20], *p1=nullptr, *p2=nullptr;
	inline char gc() { if (p1 == p2) p2 = (p1=buf) + fread(buf, 1, sizeof buf, stdin); return *p1++; }
	inline void in(char &x) { do x = gc(); while (x == ' ' || x == '\n' || x == '\r'); }
	inline void in(int &x) {
		char ch = gc();
		while (ch < '0' || ch > '9') ch = gc();
		for (x = ch ^ '0', ch = gc(); ch >= '0' && ch <= '9'; ch = gc())
			x = (x << 3) + (x << 1) + (ch ^ '0');
	}
	inline void in(char *s) {
		do *s = gc(); while (*s == ' ' || *s == '\n' || *s == '\r');
		do *(++s) = gc(); while (*s != ' ' && *s != '\n' && *s != '\r');
		*s = '\0';
	}
} using FastI::in;

constexpr int N = 200005;
struct Node {
	int a[4];
	int prefer;
	int& operator[](int p) {return a[p];}
	inline bool operator< (const Node &rhs) const {
		return prefer < rhs.prefer;
	}
} a[N];
int b[N];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T, n; in(T);
	while (T--) {
		in(n);
		For (i, 1, n) in(a[i][0]), in(a[i][1]), in(a[i][2]);
		int h[3]{};
		int ans = 0;
		For (i, 1, n) {
			a[i].prefer = std::max_element(&a[i][0], &a[i][3]) - &a[i][0];
			assert(a[i].prefer >= 0 && a[i].prefer <= 2);
			ans += a[i][a[i].prefer];
			++h[a[i].prefer];
		}
		int mxprfid = std::max_element(h, h+3) - h;
		int mxprf = h[mxprfid];
		if (mxprf > n/2) {
			int tot = 0;
			For (i, 1, n) {
				if (a[i].prefer == mxprfid) {
					b[++tot] = 1 << 30;
					For (j, 0, 2)
						if (j != a[i].prefer)
							b[tot] = min(b[tot], a[i][a[i].prefer] - a[i][j]);
				}
			}
			std::sort(b+1, b+1 + tot);
			For (i, 1, mxprf - n/2)
				ans -= b[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
