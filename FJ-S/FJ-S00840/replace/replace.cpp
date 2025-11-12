// C ( replace )
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> Puu;
const int N = 2e5 + 5, S = 5e6 + 5, maxs = 5e6 + 2;
const ull base = 37;
ull bp[S], h1[S], h2[S];
int n, q, len[N], m;
char s1[S], s2[S];
map<Puu, int> trs;
void init(){
	bp[0] = 1;
	for (int i = 1; i <= maxs; ++i){
		bp[i] = bp[i - 1] * base;
	}
	return;
}
ull calh(char *str){
	ull val = 0;
	for (int i = 1; str[i]; ++i){
		val = val * base + (str[i] ^ 96);
	}
	return val;
}
void geth(char *str, ull *h){
	h[0] = 0;
	for (int i = 1; str[i]; ++i){
		h[i] = h[i - 1] * base + (str[i] ^ 96);
	}
	return;
}
ull sumh(ull *h, int L, int R){
	return h[R] - h[L] * bp[R - L];
}
int read();
int readstr(char *str);
void write(int wx);
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	init();
	n = read();
	q = read();
	for (int i = 1; i <= n; ++i){
		len[i] = readstr(s1);
		readstr(s2);
		++trs[make_pair(calh(s1), calh(s2))];
	}
	sort(len + 1, len + n + 1);
	m = unique(len + 1, len + n + 1) - len - 1;
	for (int qq = 1, t, t2; qq <= q; ++qq){
		t = readstr(s1);
		t2 = readstr(s2);
		if (t != t2){
			putchar('0');
			putchar('\n');
			continue;
		}
		geth(s1, h1);
		geth(s2, h2);
		int ans = 0;
		for (int i = 1; i <= m; ++i){
			for (int R = len[i]; R <= t; ++R){
				if (h1[R - len[i]] == h2[R - len[i]] && sumh(h1, R, t) == sumh(h2, R, t) && trs.count(make_pair(sumh(h1, R - len[i], R), sumh(h2, R - len[i], R)))){
					ans += trs[make_pair(sumh(h1, R - len[i], R), sumh(h2, R - len[i], R))];
				}
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
int read(){
	int rx = 0;
	char rch = getchar();
	while (rch < '0' || '9' < rch){
		rch = getchar();
	}
	while ('0' <= rch && rch <= '9'){
		rx = (rx << 3) + (rx << 1) + (rch ^ 48);
		rch = getchar();
	}
	return rx;
}
int readstr(char *str){
	int Leng = 0;
	char rch = getchar();
	while (rch < 'a' || 'z' < rch){
		rch = getchar();
	}
	while ('a' <= rch && rch <= 'z'){
		str[++Leng] = rch;
		rch = getchar();
	}
	str[Leng + 1] = '\0';
	return Leng;
}
void write(int wx){
	static char ws[15];
	int wtp = 0;
	do{
		ws[++wtp] = wx % 10;
		wx /= 10;
	}while(wx);
	while (wtp){
		putchar(ws[wtp--] | 48);
	}
	return;
}
