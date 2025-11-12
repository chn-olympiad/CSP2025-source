#include<bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
const int lim = 50; 
#define ll long long
int inline read() {
	int num = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') { num = (num << 3) + (num << 1) + (ch ^ 48); ch = getchar(); }
	return num * f;
}
int nn, n, q, L1, m, len[N]; 
#define pii pair<ll, ll>
#define mp make_pair
map<pii, int> val[105]; 
char t1[N], ch1[N]; 
char t2[N], ch2[N]; 
ll w1[N], w2[N], pw[N]; 
const ll bas = 13331, mod = 998244353; 
const ll inc(const ll x, const ll y) { return x + y >= mod ? x + y - mod : x + y; }
void binc(ll &x, const ll y) { x += y; if(x >= mod) x -= mod; }
ll h1[N], h2[N]; 
void solve() {
	int ans = 0; 
	scanf("%s%s", t1 + 1, t2 + 1); 
	m = strlen(t1 + 1); 
	for(int i = 1; i <= m; ++i) h1[i] = (h1[i - 1] * bas + (t1[i] + 131)) % mod; 
	for(int i = 1; i <= m; ++i) h2[i] = (h2[i - 1] * bas + (t2[i] + 131)) % mod; 
//	for(int i = 1; i <= m; ++i) printf("%lld %lld\n", h1[i], h2[i]); printf("\n"); 
	for(int i = 1; i <= m; ++i) {
		ll tail1 = (h1[m] + (mod - h1[i]) * pw[m - i]) % mod; 
		ll tail2 = (h2[m] + (mod - h2[i]) * pw[m - i]) % mod; 
		if(tail1 != tail2) continue; 
		for(int j = lim; j >= 0; --j) {
			ll head1 = h1[i - j]; 
			ll head2 = h2[i - j]; 
			if(head1 != head2) continue; 
			ll k1 = (h1[i] + (mod - h1[i - j]) * pw[j]) % mod; 
			ll k2 = (h2[i] + (mod - h2[i - j]) * pw[j]) % mod; 
			ans += val[j][mp(k1, k2)]; 
		}
		for(int j = 1; j <= n; ++j) {
			if(i < len[j]) continue; 
//			printf("%d to %d\n", i, j); 
			ll k1 = (h1[i] + (mod - h1[i - len[j]]) * pw[len[j]]) % mod; 
			ll k2 = (h2[i] + (mod - h2[i - len[j]]) * pw[len[j]]) % mod; 
//			printf("%lld %lld\n", k1, k2); 
			if(k1 != w1[j] || k2 != w2[j]) continue; 
//			printf("hello\n"); 
			ll head1 = h1[i - len[j]]; 
			ll head2 = h2[i - len[j]]; 
			if(head1 == head2) ++ans; 
		}
	}
	printf("%d\n", ans); 
}
int main() {
#define file
#ifdef file
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
#endif
	nn = read(), q = read(); 
	for(int i = 1; i <= nn; ++i) {
		scanf("%s", ch1 + 1); 
		scanf("%s", ch2 + 1); 
		len[i] = strlen(ch1 + 1); 
		for(int j = 1; j <= len[i]; ++j) {
			w1[i] = (w1[i] * bas + (ch1[j] + 131)) % mod; 
			w2[i] = (w2[i] * bas + (ch2[j] + 131)) % mod; 
		}
		if(len[i] <= lim) ++val[len[i]][mp(w1[i], w2[i])]; 
		else {
			++n; 
			w1[n] = w1[i], w2[n] = w2[i], len[n] = len[i]; 
		}
		L1 += len[i]; 
	}
	pw[0] = 1; 
	for(int i = 1; i <= 5000000; ++i) pw[i] = pw[i - 1] * bas % mod; 
	while(q--) solve(); 
	return 0;
}
/*
一开始看错题了，以为可以无限替换
先写个字符串哈希。 

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

发现要前后缀对应相同 
答案怎么这么多零。。。不可以总司令是吧。 

长的串这样做是有性价比的。
短的串可以用桶。 
似乎挺好的。 
*/



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//#define ll long long
//int inline read() {
//	int num = 0, f = 1;
//	char ch = getchar();
//	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
//	while(ch >= '0' && ch <= '9') { num = (num << 3) + (num << 1) + (ch ^ 48); ch = getchar(); }
//	return num * f;
//}
//int n, q, L1, m, len[N]; 
//char s1[N], t1[N], ch1[N]; 
//char s2[N], t2[N], ch2[N]; 
//ll w1[N], w2[N], pw[N]; 
//const ll bas = 13331, mod = 998244353; 
//const ll inc(const ll x, const ll y) { return x + y >= mod ? x + y - mod : x + y; }
//void binc(ll &x, const ll y) { x += y; if(x >= mod) x -= mod; }
//ll h1[N], h2[N]; 
//void solve() {
//	int ans = 0; 
//	scanf("%s%s", t1 + 1, t2 + 1); 
//	m = strlen(t1 + 1); 
//	for(int i = 1; i <= m; ++i) h1[i] = (h1[i - 1] * bas + (t1[i] + 131)) % mod; 
//	for(int i = 1; i <= m; ++i) h2[i] = (h2[i - 1] * bas + (t2[i] + 131)) % mod; 
////	for(int i = 1; i <= m; ++i) printf("%lld %lld\n", h1[i], h2[i]); printf("\n"); 
//	for(int i = 1; i <= m; ++i) {
//		for(int j = 1; j <= n; ++j) {
//			if(i < len[j]) continue; 
////			printf("%d to %d\n", i, j); 
//			ll k1 = (h1[i] + (mod - h1[i - len[j]]) * pw[len[j]]) % mod; 
//			ll k2 = (h2[i] + (mod - h2[i - len[j]]) * pw[len[j]]) % mod; 
////			printf("%lld %lld\n", k1, k2); 
//			if(k1 != w1[j] || k2 != w2[j]) continue; 
////			printf("hello\n"); 
//			ll head1 = h1[i - len[j]]; 
//			ll head2 = h2[i - len[j]]; 
//			ll tail1 = (h1[m] + (mod - h1[i]) * pw[m - i]) % mod; 
//			ll tail2 = (h2[m] + (mod - h2[i]) * pw[m - i]) % mod; 
//			if(head1 == head2 && tail1 == tail2) ++ans; 
//		}
//	}
//	printf("%d\n", ans); 
//}
//int main() {
//#define file
//#ifdef file
//	freopen("replace3.in", "r", stdin);
//	freopen("replace.out", "w", stdout);
//#endif
//	n = read(), q = read(); 
//	for(int i = 1; i <= n; ++i) {
//		scanf("%s", ch1 + 1); 
//		scanf("%s", ch2 + 1); 
//		len[i] = strlen(ch1 + 1); 
//		for(int j = 1; j <= len[i]; ++j) {
//			s1[L1 + j] = ch1[j]; 
//			s2[L1 + j] = ch2[j]; 
//			w1[i] = (w1[i] * bas + (ch1[j] + 131)) % mod; 
//			w2[i] = (w2[i] * bas + (ch2[j] + 131)) % mod; 
//		}
//		L1 += len[i]; 
////		printf("%d %lld %lld\n", len[i], w1[i], w2[i]);
//	}
//	pw[0] = 1; 
//	for(int i = 1; i <= 1000000; ++i) pw[i] = pw[i - 1] * bas % mod; 
//	while(q--) solve(); 
//	return 0;
//}
