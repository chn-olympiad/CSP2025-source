#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using std::string;
using std::vector;
using std::greater;
using std::sort;
using std::unordered_map;
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
const int N = 5e5 + 5;
ll n, k, a[N], x[N], r, ans;
unordered_map <ll, ll> mp;
int main(){
	fio("xor.in","xor.out")
	read(n),read(k);
	for (int i = 1;i <= n;i++){
		read(a[i]);
		x[i] = x[i-1] ^ a[i];
	}
	mp[0] = 1;
	for (int i = 1;i <= n;i++){
//		mp[x[i]]++;
//		for (auto i : mp)write(i.first),putchar(' ');
//		putchar('\n');
		if (mp.find(x[i] ^ k) != mp.end()){
			ans++;
//			putchar('#');write(i);putchar('\n');
			mp.clear();
		}
		mp[x[i]]++;
	}
	write(ans);
	return 0;
}
