#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;
using std::pair;
#define fi first
#define se second
typedef long long ll;
typedef __uint128_t u128;
typedef __int128_t i128;
typedef unsigned long long ull;
char *p1,*p2, buf[1<<20];
#define gc() (p1 == p2 && (p2 = (p1 = buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
template <typename T>
inline void read(T& cnt) {
	cnt = 0;
	bool flag = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar())if (c == '-')flag = !flag;
	for (; isdigit(c); c = getchar())(cnt *= 10) += (c - 48);
}
template <typename T>
inline void write(T cnt) {
	if (cnt < 0) {
		putchar('-');
		cnt = -cnt;
	}
	if (cnt > 9)write(cnt / 10);
	putchar(cnt % 10 + 48);
}
#define fio(ifile,ofile) freopen(ifile,"r",stdin);freopen(ofile,"w",stdout);
const int N = 1e4 + 5;
ll n, m, k, x, y, z, f[N], cur, ans, rem, temp;
vector <pair<ll,ll> >g[N];
vector <pair <ll, pair <ll,ll> > >si;
inline ll find(ll x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
inline void comb(ll x,ll y) {
	int p = find(x), q = find(y);
	if (p!=q)f[p] = q;
}
int main() {
	fio("road.in","road.out")
	read(n),read(m),read(k);
	for (int i = 1;i <= n;i++)f[i] = i;
	for (int i = 1; i <= n; i++) {
		read(x),read(y),read(z);
		g[x].push_back({y,z});
		g[y].push_back({x,z});
		si.push_back({z,{x,y}});
	}
	for (int i = 1;i <= k;i++){
		read(cur);
		for (int j = 1;j <= n;j++){
			read(temp);
		}
	}
	rem = n - 1;
	sort (si.begin(),si.end());
	for (int i = 0;i < m;i++){
		int p = si[i].se.fi,q = si[i].se.se;
		if (find(p) != find(q)){
//			write(p);putchar(' ');write(q);putchar('\n');
			comb(p, q);
			ans += si[i].fi;
			rem--;
			if (rem == 0){
				write(ans);
				return 0;
			}
		}
	}
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4*/
