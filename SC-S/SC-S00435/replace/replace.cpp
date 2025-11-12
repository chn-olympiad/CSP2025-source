#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(x) (x) & (-x)
template<typename T> void read(T &x) {
	T f = 1; x = 0; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit((ch))) {x = x * 10 + ch - 48; ch = getchar();}
	x *= f;
}
const int N = 2e5 + 5;
int n, q;
string s1[N], s2[N];
string t1, t2;
int ls, lt, nxt[N], ans;
void get_nxt(string t) {
	int j = 0;
	for(int i = 1; i < lt; i++) {
		while(j && t[j + 1] != t[i]) 
			j = nxt[j];
		if(t[j + 1] == t[i]) j++;
		nxt[i] = j;
	}
}
void kmp(string s, string t, int p) {
	int j = 0;
	for(int i = 1; i < ls; i++) {
		while(j && t[j + 1] != s[i]) 
			j = nxt[j];
		if(t[j + 1] == s[i]) j++;
		if(j == lt + 1) {
			printf("%d\n", i - lt + 1);
			string tmp;
			for(int k = 0; k < s.length(); k++) tmp[k] = s[k];
			for(int k = i - lt + 1; k <= i; k++) tmp[k] = s2[p][k];
//			cout << tmp << endl;
			if(tmp == t2) ans++;
			j = nxt[j];
		}
	}
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	read(n), read(q);
	for(int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1; i <= q; i++) {
		cin >> t1 >> t2;
		ls = t1.length();
		for(int j = 1; j <= n; j++) {
			ans = 0;
			get_nxt(s1[j]);
			lt = s1[j].length();
			kmp(t1, s1[j], j);
		}
		printf("%d\n", ans);
	}
	return 0;
}