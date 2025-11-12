#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using std::string;
using std::vector;
using std::greater;
using std::sort;
typedef long long ll;
typedef __uint128_t u128;
typedef __int128_t i128;
typedef unsigned long long ull;
//#define isdigit(ch) (ch >='0' && ch <= '9')
const int BUF_SIZE = 1 << 20;
char buf[BUF_SIZE], *p1, *p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1<<20,stdin), p1 == p2) ? EOF : *p1++)
#define getchar gc
//template <typename T>
inline void read(ll& cnt) {
	cnt = 0;
	bool flag = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar())if (c == '-')flag = !flag;
	for (; isdigit(c); c = getchar())(cnt *= 10) += (c - 48);
	cnt = flag ? -cnt : cnt;
}
//template <typename T>
inline void write(ll cnt) {
	if (cnt < 0) {
		putchar('-');
		cnt = -cnt;
	}
	if (cnt > 9)write(cnt / 10);
	putchar(cnt % 10 + 48);
}
inline string read() {
	string cur = "";
	char c = getchar();
	for (; (!isdigit(c)) && (!isalpha(c)); c = getchar());
	for (; isdigit(c) || isalpha(c); c = getchar())cur += c;
	return cur;
}
inline void write(string s) {
	for (auto i : s)putchar(i);
}
#define fio(ifile, ofile) freopen(ifile,"r",stdin);freopen(ofile,"w",stdout);
const int MAXN = 1e3 + 5;
ll n,m,sc[MAXN],d, ans,ansx,ansy, modn;
int main() {
	fio("seat.in","seat.out")
	read(n),read(m);
	for (int i = 1; i <= (n*m); i++)read(sc[i]);
	d = sc[1];
//	write(d);
	sort (sc + 1,sc + 1 + (n*m),greater<int>());
//	for (int i = 1; i <= (n*m); i++)write(sc[i]);
	for (int i = 1;i <= (n*m);i++)if (sc[i] == d){
		ans = i;
	}
//	write(ans);putchar('\n');
	ansx = ceil((double)ans / n);
	modn = (ans % n == 0) ? (n) : (ans % n);
	ansy = ((ansx % 2 == 1)? modn : (m - modn+1));
	write(ansx);putchar(' ');write(ansy);
	return 0;
}
