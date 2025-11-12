#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <climits>
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
inline ll max(ll x,ll y){
	return x > y ? x : y;
}
#define fio(ifile, ofile) freopen(ifile,"r",stdin);freopen(ofile,"w",stdout);
const ll N  = 5005;
const ll MOD = 998244353;
ll n, a[N], ans, cnt1; 
void dfs(ll cur,ll maxn,ll sum){
	if (cur == n + 1){
		if (maxn * 2 < sum)ans = (ans + 1) % MOD;
		return;
	}
	dfs(cur+1,max(maxn,a[cur]),sum+a[cur]);
	dfs(cur+1,maxn,sum);
}
int main(){
//	fio("polygon.in","polygon.out")
	read(n);
	for (int i = 1;i <= n;i++){
		read(a[i]);
		if (a[i] == 1)cnt1++;
	}
//	if (cnt1 == n){
//		ans = 1;
//		for (int i = 3;i <= n;i++){
//			for (int j = n;j >= (n - i + 1);j--)ans *= j;
//			for (int j = 1;j <= i;j++)ans /= i;
//		}
////		return 0;
//	}
	dfs(1,LLONG_MIN,0);
	write(ans);
	return 0;
}
/*
3:1
4:5          4
5:16         11
6:42         
*/
