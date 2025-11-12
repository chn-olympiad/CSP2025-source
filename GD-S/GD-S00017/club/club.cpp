#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= inf(b); i--)
#define gc getchar
template<typename T> void read(T &x) {x=0; char c, s = 1;while (!isdigit(c=gc())) if (c=='-') s = -1;for (; isdigit(c); c=gc()) x = (x<<1)+(x<<3)+(c^48);x*=s;}
template<typename TT, typename ...T> void read(TT &x, T &...y) {read(x), read(y...);}
const int N = 1e5 + 10;
int T, n, a[N][3], b[N], c[N], num[3], ma, ans, cnt;
bool cmp(int x, int y) {
	return a[x][ma] - max(a[x][(ma+1)%3], a[x][(ma+2)%3]) < a[y][ma] - max(a[y][(ma+1)%3], a[y][(ma+2)%3]);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	read(T);
	while (T--) {
		read(n);
		ma = -1, ans = 0, cnt = 0, memset(num, 0, sizeof(num));
		rep(i, 1, n) read(a[i][0], a[i][1], a[i][2]);
		rep(i, 1, n)
			rep(j, 0, 2)
				if (a[i][j] == max(a[i][0], max(a[i][1], a[i][2]))) {
					b[i] = j, ans += a[i][j], num[j]++;
					break;
				}
		rep(i, 0, 2) if (num[i] > n>>1) ma = i;
		if (~ma) {
			rep(i, 1, n) if (b[i] == ma) c[++cnt] = i;
			sort(c+1, c+cnt+1, cmp);
			rep(i, 1, num[ma]-(n>>1)) ans -= a[c[i]][ma] - max(a[c[i]][(ma+1)%3], a[c[i]][(ma+2)%3]);
		}
		printf("%d\n", ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
