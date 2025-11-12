#include <cstdio>
#include <cctype>
typedef long long ll;
typedef __uint128_t u128;
typedef __int128_t i128;
typedef unsigned long long ull;
char *p1,*p2, buf[1<<20];
#define gc() (p1 == p2 && (p2 = (p1 = buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
template <typename T>
inline void read(T& cnt){
	cnt = 0;
	bool flag = 0;
	char c = getchar();
	for (;!isdigit(c);c = getchar())if (c == '-')flag = !flag;
	for (;isdigit(c);c = getchar())(cnt *= 10) += (c - 48);
}
template <typename T>
inline void write(T cnt){
	if (cnt < 0){
		putchar('-');
		cnt = -cnt;
	}
	if (cnt > 9)write(cnt / 10);
	putchar(cnt % 10 + 48);
}
#define fio(ifile,ofile) freopen(ifile,"r",stdin);freopen(ofile,"w",stdout);
