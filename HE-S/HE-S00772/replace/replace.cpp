/*
clear && ulimit -s 1024000 && g++ % -o %< -O2 -std=c++14 -DLOCAL -Wall -Wextra -Wshadow -Wconversion && ulimit -v 1024000 && time ./%< && size %<
clear && ulimit -s 1024000 && g++ % -o %< -O2 -std=c++14 -DLOCAL -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined -g && ./%<
echo && cat out.out && echo
*/
#include <bits/stdc++.h>
using namespace std;
using llt = long long;
using llf = long double;
using ull = unsigned long long;
template<class T> void Cmin(T &a, T b){ if(a > b) a = b; }
template<class T> void Cmax(T &a, T b){ if(a < b) a = b; }
#define endl '\n'
#ifdef LOCAL
FILE *InFile = freopen("in.in", "r", stdin), *OutFile = freopen("out.out", "w", stdout);
#else
FILE *InFile = freopen("replace.in", "r", stdin), *OutFile = freopen("replace.out", "w", stdout);
#endif

const int N = 2e5 + 3, L = 5e6 + 3, Bs = 23333;
int n, q; ull pw[L];
int Id(char x, char y){ return x - 'a' + 1 + (y - 'a' + 1) * 27; }

class Hs{
private:
	vector<ull> hs;
public:
	void In(string s, string t){
		hs.resize(s.size()), hs[0] = Id(s[0], t[0]);
		for(int i = 1, _ = s.size(); i < _; ++i) hs[i] = hs[i - 1] * Bs + Id(s[i], t[i]);
	}
	int Sz(){ return hs.size(); }
	ull Get(int l, int r){
		if(l) return hs[r] - hs[l - 1] * pw[r - l + 1];
		else return hs[r];
	}
} hs[N];

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	pw[0] = 1; for(int i = 1; i <= L - 3; ++i) pw[i] = pw[i - 1] * Bs;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i){ string s, t; cin >> s >> t, hs[i].In(s, t); }
	for(int i = 1; i <= q; ++i){
		string s, t; cin >> s >> t;
		Hs ht; ht.In(s, t);
		int ln = s.size(), l = 0, r = ln - 1, ans = 0;
		while(s[l] == t[l]) ++l;
		while(s[r] == t[r]) --r;
		for(int k = 1; k <= n; ++k){
			int ll = hs[k].Sz();
			for(int j = max(r, ll - 1); j < ln && j - ll + 1 <= l; ++j)
				ans += (hs[k].Get(0, ll - 1) == ht.Get(j - ll + 1, j));
		}
		cout << ans << endl;
	}
}
