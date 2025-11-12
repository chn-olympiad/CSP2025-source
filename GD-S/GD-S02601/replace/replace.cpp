// godmoo's code
#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define ep emplace
#define fi first
#define se second
#define lbd lower_bound
#define ubd upper_bound
#define mathmod(a, m) (((a) % (m) + (m)) % (m))
#define all(a) (a).begin(), (a).end()
typedef long long ll; typedef unsigned long long ull; typedef pair<int, int> pii;

const int N = 2e5 + 5, L = 3e6 + 5;
int n, q, ans[N];
char s[L], t[L];

struct Info {
	int l, r, op;
	Info(int _l = 0, int _r = 0, int _op = 0): l(_l), r(_r), op(_op) {}
	bool operator < (const Info &rhs) const {
		return l != rhs.l ? l < rhs.l : op < rhs.op;
	}
};

vector<Info> VP[L], VN[L];

struct Fenwick {
	int tr[L];
	void add(int u, int x){ for(u++; u < L; u += u & -u) tr[u] += x; } 
	int query(int u){ int res = 0; for(u++; u > 0; u -= u & -u) res += tr[u]; return res; }
} T;

#define file(a) freopen(#a ".in", "r", stdin), freopen(#a ".out", "w", stdout)

int main(){
	file(replace);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> (s + 1) >> (t + 1);
		int l = strlen(s + 1);
		int p = find(s + 1, s + l + 1, 'b') - s;
		int q = find(t + 1, t + l + 1, 'b') - t;
		if(p == q) continue;
		if(p < q) VP[q - p].eb(p - 1, l - q, 0);	
		else VN[p - q].eb(q - 1, l - p, 0);
	}
	for(int i = 1; i <= q; i++) {
		cin >> (s + 1) >> (t + 1);
		int l = strlen(s + 1), _l = strlen(t + 1);
		if(l != _l) continue;
		int p = find(s + 1, s + l + 1, 'b') - s;
		int q = find(t + 1, t + l + 1, 'b') - t;
		assert(p != q);
		if(p < q) VP[q - p].eb(p - 1, l - q, i);
		else VN[p - q].eb(q - 1, l - p, i);
	}
	for(int i = 1; i < L; i++) if(!VP[i].empty()){
		sort(all(VP[i]));
		for(auto info : VP[i]){
			int r = info.r, op = info.op;
			!op ? T.add(r, 1) : (ans[op] = T.query(r), void());
		} for(auto info : VP[i]) if(!info.op) T.add(info.r, -1);
	}
	for(int i = 1; i < L; i++) if(!VN[i].empty()){
		sort(all(VN[i]));
		for(auto info : VN[i]){
			int r = info.r, op = info.op;
			!op ? T.add(r, 1) : (ans[op] = T.query(r), void());
		} for(auto info : VN[i]) if(!info.op) T.add(info.r, -1);
	}
	for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


out:
2
0

---

3 4
a b
b c
c d
aa bb
aa b
a c
b a


out:
0
0
0
0

---

Hack:

1 1
abbbc akkkc
bbbbb bkkkb

out:
0

---

2 1
abaa aaba
aaaabaaa aaaaabaa
aaaaabaaa aaaaaabaa

out:
1

*/

