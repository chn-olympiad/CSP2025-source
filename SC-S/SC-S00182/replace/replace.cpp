#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 2e5 + 5, M = 5e6 + 5;
const int b1 = 233, b2 = 211, mo1 = 19260817, mo2 = 1e9 + 9;

int n, m, tmp1[M], tmp2[M], de1[M], de2[M], bg, ed;
int pw1[M], pw2[M];
struct node{int len, h1, h2, d1, d2, ed;}a[N];
char s[M], t[M];

inline int get1(int l, int r){return ((tmp1[r] - 1ll * tmp1[l - 1] * pw1[r - l + 1] % mo1) + mo1) % mo1;}
inline int get2(int l, int r){return ((tmp2[r] - 1ll * tmp2[l - 1] * pw2[r - l + 1] % mo2) + mo2) % mo2;}
inline int get11(int l, int r){return ((de1[r] - 1ll * de1[l - 1] * pw1[r - l + 1] % mo1) + mo1) % mo1;}
inline int get22(int l, int r){return ((de2[r] - 1ll * de2[l - 1] * pw2[r - l + 1] % mo2) + mo2) % mo2;}

int main(){
	ios :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m; pw1[0] = pw2[0] = 1;
	for(int i = 1; i < M; ++i)
		pw1[i] = 1ll * pw1[i - 1] * b1 % mo1,
		pw2[i] = 1ll * pw2[i - 1] * b2 % mo2;
	for(int i = 1; i <= n; ++i){
		cin >> s + 1 >> t + 1; a[i].len = strlen(s + 1);
		for(int j = 1; j <= a[i].len; ++j){
			a[i].h1 = (1ll * a[i].h1 * b1 + (s[j] - 'a')) % mo1;
			a[i].h2 = (1ll * a[i].h2 * b2 + (s[j] - 'a')) % mo2;
			a[i].d1 = (1ll * a[i].d1 * b1 + (s[j] - t[j] + 50)) % mo1;
			a[i].d2 = (1ll * a[i].d2 * b2 + (s[j] - t[j] + 50)) % mo2;
			if(s[j] != t[j])a[i].ed = j;
		}
	}
	for(int i = 1; i <= m; ++i){
		cin >> s + 1 >> t + 1; int len = strlen(s + 1), res = 0;
		tmp1[0] = tmp2[0] = de1[0] = de2[0] = ed = bg = 0;
		for(int j = 1; j <= len; ++j){
			tmp1[j] = (1ll * tmp1[j - 1] * b1 + (s[j] - 'a')) % mo1;
			tmp2[j] = (1ll * tmp2[j - 1] * b2 + (s[j] - 'a')) % mo2;
			de1[j] = (1ll * de1[j - 1] * b1 + (s[j] - t[j] + 50)) % mo1;
			de2[j] = (1ll * de2[j - 1] * b2 + (s[j] - t[j] + 50)) % mo2;
			if(s[j] != t[j]){if(! bg)bg = j; ed = j;}
		}
		for(int j = 1; j <= n; ++j)if(a[j].ed <= ed and ed - bg + 1 <= a[j].len){
			int l = ed + 1 - a[j].ed, r = l + a[j].len - 1;
			if(r > len or bg < l)continue;
			bool o1 = a[j].h1 == get1(l, r) and a[j].h2 == get2(l, r);
			bool o2 = a[j].d1 == get11(l, r) and a[j].d2 == get22(l, r);
			res += o1 and o2;
		}
		cout << res << endl;
	}
	return 0;
}