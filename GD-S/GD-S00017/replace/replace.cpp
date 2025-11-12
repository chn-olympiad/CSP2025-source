#include <bits/stdc++.h>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define gc getchar
template<typename T> void read(T &x) {x=0; char c, s = 1;while (!isdigit(c=gc())) if (c=='-') s = -1;for (; isdigit(c); c=gc()) x = (x<<1)+(x<<3)+(c^48);x*=s;}
template<typename TT, typename ...T> void read(TT &x, T &...y) {read(x), read(y...);}
const ull P = 13131;
const int N = 5e6 + 10;
int n, q, same[N], len[N]; ull val[N], h1[N], h2[N], H1[N], H2[N], p[N];
char s1[N], s2[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	//srand(time(0));
	srand(time(0));
	rep(i, 'a', 'z')
		val[i-'a'] = (ull)rand() * rand();
	p[0] = 1;
	rep(i, 1, N-1) p[i] = p[i-1] * P;
	read(n, q);
	rep(i, 1, n) {
		scanf("%s", s1+1), scanf("%s", s2+1);
		len[i] = strlen(s1+1);
		rep(j, 1, len[i]) {
			h1[i] = h1[i]*P + val[s1[j]-'a'], h2[i] = h2[i]*P + val[s2[j]-'a'];
		}
		//printf("hash %d %llu %llu\n", i, h1[i], h2[i]);
	}
	rep(i, 1, q) {
		scanf("%s", s1+1), scanf("%s", s2+1);
		int l = strlen(s1+1), ans = 0;
		same[l+1] = 1;
		per(i, l, 1) same[i] = (s1[i] == s2[i]) && same[i+1];
		rep(j, 1, l) {
			H1[j] = H1[j-1]*P + val[s1[j]-'a'], H2[j] = H2[j-1]*P + val[s2[j]-'a'];
			
			
			rep(k, 1, n) {
				if (j - len[k] < 0) continue;
				ull tH1 = H1[j] - p[len[k]]*H1[j-len[k]], tH2 = H2[j] - p[len[k]]*H2[j-len[k]];
				//printf("q%d pos%d n%d %llu %llu\n", i, j, k, tH1, tH2);
				//printf("if %llu == %llu ? %d\n", tH1, h1[k], tH1 == h1[k]);
				//printf("if %llu == %llu ? %d\n", tH2, h2[k], tH2 == h2[k]);
				if (tH1 == h1[k] && tH2 == h2[k] && same[j+1] && H1[j-len[k]] == H2[j-len[k]]) ans++;
			}
		}
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
