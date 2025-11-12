#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
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
inline string read(){
	string cur = "";
	char c = getchar();
	for (; (!isdigit(c)) && (!isalpha(c));c = getchar());
	for (;isdigit(c) || isalpha(c);c = getchar())cur += c;
	return cur;
}
inline void write(string s){
	for (auto i : s)putchar(i);
}
#define fio(ifile, ofile) freopen(ifile,"r",stdin);freopen(ofile,"w",stdout);
vector <int> a;
string x;
int main(){
	fio("number.in","number.out")
	x = read();
//	write(x);
	for (int i = 0;i < x.length();i++){
		if (isdigit(x[i]))a.push_back(x[i] - '0');
	}
	sort (a.begin(),a.end(),greater<int>());
	for (auto i : a)write(i);
	return 0;
}
