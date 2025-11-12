#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int maxn = 2e5 + 10;
const int maxl = 5e6 + 10;
const int A = 29;
const int B = 31;
const int mod = 1e9 + 7;

int pA[maxl];
int pB[maxl];

int n, q;

struct Hsh{
	int len;
	int h1, h2;
	Hsh() {}
	Hsh(string s): len(s.size()) {
		h1 = h2 = 0;
		for (int k = 0; k < (int)s.size(); k++) {
			h1 = ((LL)h1 * A + s[k] - 'a' + mod) % mod;
			h2 = ((LL)h2 * B + s[k] - 'a' + mod) % mod;
		}
	}
	
	Hsh(char c): len(1), h1(c - 'a'), h2(c - 'a') { }
	
	Hsh operator + (const Hsh &b) {
		Hsh res;
		res.len = len + b.len;
		res.h1 = ((LL)h1 * pA[b.len] + b.h1) % mod;
		res.h2 = ((LL)h2 * pB[b.len] + b.h2) % mod;
		return res;
	}
	
	bool operator == (const Hsh &b) {
		return len == b.len && h1 == b.h1 && h2 == b.h2;
	}
	
	friend ostream& operator << (ostream &os, const Hsh a) {
		os << a.len << " " << a.h1 << " " << a.h2;
		return os;
	}
};

pair<Hsh, Hsh> change[maxn];

Hsh st_list[maxn];
Hsh ed_list[maxn];

Hsh query(Hsh *lis, int l, int r) {
	Hsh res;
	res.len = r - l + 1;
	res.h1 = ((LL)lis[r].h1 - (LL)lis[l-1].h1 * pA[r - l + 1] % mod + mod) % mod;
	res.h2 = ((LL)lis[r].h2 - (LL)lis[l-1].h2 * pB[r - l + 1] % mod + mod) % mod;
	return res;
}

void subtask2() {
	// mo ban
}

void solve() {
	cin >> n >> q;
	bool ok = true;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		for (int j = 0; j < s1.size(); j++) if (s1[j] != 'a' && s1[j] != 'b') ok = false;
		for (int j = 0; j < s2.size(); j++) if (s2[j] != 'a' && s2[j] != 'b') ok = false;
		change[i] = make_pair(Hsh(s1), Hsh(s2));
	}
	
	if (ok) {
		subtask2();
	}
//	cout << change[1].first << endl;
	
	for (int i = 1; i <= q; i++) {
		int res = 0;
		string st, ed;
		cin >> st >> ed;
		if (st.size() != ed.size()) {
			cout << 0 << endl;
			continue;
		}
		int siz = st.size();
		st = ' ' + st;
		ed = ' ' + ed;
		for (int j = 1; j <= siz; j++) {
			st_list[j] = st_list[j-1] + Hsh(st[j]);
			ed_list[j] = ed_list[j-1] + Hsh(ed[j]);
//			cout << st_list[j] << " " << ed_list[j] << endl; //
		}
//		cout << query(ed_list, 3, 3) << endl; // 
		for (int i = 1; i <= n; i++) {
			int clen = change[i].first.len;
			for (int l = 1, r = clen; r <= siz; l++, r++) {
//				cout << i << " " << clen << " " << query(st_list, l, r) << endl; // 
				if (query(st_list, l, r) == change[i].first &&
						query(ed_list, l, r) == change[i].second &&
						query(st_list, 1, l-1) == query(ed_list, 1, l-1) &&
						query(st_list, r+1, siz) == query(ed_list, r+1, siz)) {
//							cout << i << " " << l << " " << r << endl; //
							res++;
						}
			}
		}
		cout << res << endl;
	}
}

void init() {
	pA[0] = pB[0] = 1;
	for (int i = 1; i < maxl; i++) {
		pA[i] = (LL)pA[i-1] * A % mod;
		pB[i] = (LL)pB[i-1] * B % mod;
	}
//	cout << pA[10] << endl; // 
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	init();
	solve(); // q*n*n
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
