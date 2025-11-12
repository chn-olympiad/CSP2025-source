/*-- Confidence works miracles. --*/
// Time Limit: 1.0 s
// Memory Limit: 2048 MB
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef __int128 i128;
#define I inline
#define reg register
typedef pair<int, int> pint;
#define fi first
#define se second
#define mk make_pair

char BG;

namespace FastIO {
	char ibuf[(1<<21)+1], *p1 = ibuf, *p2 = ibuf, obuf[1<<22], *O = obuf;
	#define gh() (((p1==p2)&&(p2=(p1=ibuf)+fread(ibuf,1,1<<21,stdin)),p1==p2)?EOF:*p1++)
	I int read() {
		reg int x = 0, sgn = 1;
		reg char c = gh();
		while (!isdigit(c)) (c=='-')&&(sgn=-1), c = gh();
		while (isdigit(c)) x = (x<<3)+(x<<1)+(c^48), c = gh();
		return x*sgn;
	}
	I void putc(char c) { *O++ = c; }
	void write(int x) {
		if (x < 0) *O++ = '-', x = -x;
		if (x > 9) write(x/10);
		*O++ = x%10+'0';
	}
	I void flush() {
		fwrite(obuf, O-obuf, 1, stdout);
		O = obuf;
	}
}
using namespace FastIO;

constexpr int N = 2e5+5;
constexpr int M = 5e6+5;
constexpr int B = 131;
constexpr int MOD = 998244853;

int base[M], val1[M], val2[M], sum1[M], sum2[M];

int n, m, q, rst[N];
struct Node {
	string s1, s2;
	int L, R, len;
} a[N], b[N];

void init() {
	base[0] = 1;
	for (int i = 1; i < M; i++) base[i] = (i64)base[i-1]*B%MOD;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < a[i].len; j++) {
			val1[i] = (val1[i]+(i64)(a[i].s1[j]-'a'+1)*base[j]%MOD)%MOD;
			val2[i] = (val2[i]+(i64)(a[i].s2[j]-'a'+1)*base[j]%MOD)%MOD;
		}
	}
}

namespace S50 {
	void solve() {
		init();
		for (int i = 1; i <= q; i++) {
			if (b[i].s1.size() != b[i].s2.size()) {
				rst[i] = 0; continue;
			}
			for (int j = 0; j < b[i].len; j++) {
				sum1[j] = (i64)(b[i].s1[j]-'a'+1)*base[j]%MOD;
				sum2[j] = (i64)(b[i].s2[j]-'a'+1)*base[j]%MOD;
				if (j) {
					sum1[j] += sum1[j-1];
					(sum1[j] >= MOD) && (sum1[j] -= MOD);
					sum2[j] += sum2[j-1];
					(sum2[j] >= MOD) && (sum2[j] -= MOD);
				}
			}
			for (int j = 1; j <= n; j++) {
				if (a[j].L == -1) continue;
				if (b[i].R-b[i].L != a[j].R-a[j].L) continue;
				int l = b[i].L-a[j].L, r = b[i].R+a[j].len-a[j].R-1;
				if (l < 0 || r >= b[i].len) continue;
				int now1 = sum1[r]-(l?sum1[l-1]:0);
				int now2 = sum2[r]-(l?sum2[l-1]:0);
				(now1 < 0) && (now1 += MOD);
				(now2 < 0) && (now2 += MOD);
				if ((i64)val1[j]*base[l]%MOD == now1 && (i64)val2[j]*base[l]%MOD == now2)
					++rst[i];
			}
		}
		for (int i = 1; i <= q; i++) cout << rst[i] << '\n';
	} 
} 

namespace S70 {
	int tree[2][M];
	#define lowbit(x) ((x)&(-x))
	I void update(int* t, int x, int v) {
		while (x <= m) { t[x] += v; x += lowbit(x); }
	}
	I int query(int* t, int x) {
		int rst = 0;
		while (x) { rst += t[x]; x -= lowbit(x); }
		return rst;
	}
	struct Data {
		int L, R, len, idx, typ;
		friend bool operator < (const Data& x, const Data& y) {
			if (x.L == y.L) return x.idx < y.idx;
			return x.L < y.L;
		}
	};
	vector<int> arr;
	vector<Data> vec[N];
	void solve() {
		for (int i = 1; i <= n; i++) {
			if (a[i].L == -1) continue;
			arr.emplace_back(a[i].R-a[i].L);
		}
		for (int i = 1; i <= q; i++) {
			if (b[i].s1.size() != b[i].s2.size()) continue;
			arr.emplace_back(b[i].R-b[i].L);
		}
		sort(arr.begin(), arr.end());
		arr.erase(unique(arr.begin(), arr.end()), arr.end());
		for (int i = 1; i <= n; i++) {
			if (a[i].L == -1) continue;
			int idx = lower_bound(arr.begin(), arr.end(), a[i].R-a[i].L)-arr.begin()+1;
			vec[idx].push_back(Data{a[i].L, a[i].R, a[i].len, 0, a[i].s1[a[i].L] == 'b'});
		}
		for (int i = 1; i <= q; i++) {
			if (b[i].s1.size() != b[i].s2.size()) continue;
			int idx = lower_bound(arr.begin(), arr.end(), b[i].R-b[i].L)-arr.begin()+1;
			vec[idx].push_back(Data{b[i].L, b[i].R, b[i].len, i, b[i].s1[b[i].L] == 'b'});
		}
		for (int i = 1; i <= (int)arr.size(); i++) {
			sort(vec[i].begin(), vec[i].end());
			for (Data x : vec[i]) {
				if (!x.idx) {
					update(tree[x.typ], x.len-x.R, 1);
				} else {
					rst[x.idx] = query(tree[x.typ], x.len-x.R);
				}
			}
			for (Data x : vec[i]) {
				if (!x.idx) update(tree[x.typ], x.len-x.R, -1);
			}
		}
		for (int i = 1; i <= q; i++) cout << rst[i] << '\n';
	}
}

namespace Solve {
	vector<pint> arr1;
	vector<pint> vec[N<<1];
	void solve() {
		init();
		for (int i = 1; i <= n; i++) {
			if (a[i].L == -1) continue;
			int tmp1 = 0, tmp2 = 0;
			for (int j = a[i].L; j <= a[i].R; j++) {
				tmp1 = ((i64)tmp1*B+a[i].s1[j])%MOD;
				tmp2 = ((i64)tmp2*B+a[i].s2[j])%MOD;
			}
			arr1.emplace_back(a[i].R-a[i].L, tmp1^tmp2);
		}
		for (int i = 1; i <= q; i++) {
			if (b[i].s1.size() != b[i].s2.size()) continue;
			int tmp1 = 0, tmp2 = 0;
			for (int j = b[i].L; j <= b[i].R; j++) {
				tmp1 = ((i64)tmp1*B+b[i].s1[j])%MOD;
				tmp2 = ((i64)tmp2*B+b[i].s2[j])%MOD;
			}
			arr1.emplace_back(b[i].R-b[i].L, tmp1^tmp2);
		}
		sort(arr1.begin(), arr1.end());
		arr1.erase(unique(arr1.begin(), arr1.end()), arr1.end());
		for (int i = 1; i <= n; i++) {
			if (a[i].L == -1) continue;
			int tmp1 = 0, tmp2 = 0;
			for (int j = a[i].L; j <= a[i].R; j++) {
				tmp1 = ((i64)tmp1*B+a[i].s1[j])%MOD;
				tmp2 = ((i64)tmp2*B+a[i].s2[j])%MOD;
			}
			int idx = lower_bound(arr1.begin(), arr1.end(), mk(a[i].R-a[i].L, tmp1^tmp2))-arr1.begin()+1;
			vec[idx].push_back(pint{i, 0});
		}
		for (int i = 1; i <= q; i++) {
			if (b[i].s1.size() != b[i].s2.size()) continue;
			int tmp1 = 0, tmp2 = 0;
			for (int j = b[i].L; j <= b[i].R; j++) {
				tmp1 = ((i64)tmp1*B+b[i].s1[j])%MOD;
				tmp2 = ((i64)tmp2*B+b[i].s2[j])%MOD;
			}
			int idx = lower_bound(arr1.begin(), arr1.end(), mk(b[i].R-b[i].L, tmp1^tmp2))-arr1.begin()+1;
			vec[idx].push_back(pint{i, 1});
		}
		for (int t = 1; t <= (int)arr1.size(); t++) {
			sort(vec[t].begin(), vec[t].end(), [](auto x, auto y) {
				if (x.se == 0 && y.se == 0) {
					return a[x.fi].L < a[y.fi].L; 
				} else if (x.se == 0 && y.se == 1) {
					if (a[x.fi].L == b[y.fi].L) return x.se < y.se;
					return a[x.fi].L < b[y.fi].L;
				} else if (x.se == 1 && y.se == 0) {
					if (b[x.fi].L == a[y.fi].L) return x.se < y.se;
					return b[x.fi].L < a[y.fi].L;
				} else {
					return b[x.fi].L < b[y.fi].L;
				}
			});
			for (int x = 0; x < (int)vec[t].size(); x++) {
				if (!vec[t][x].se) continue;
				int i = vec[t][x].fi;
				for (int j = 0; j < b[i].len; j++) {
					sum1[j] = (i64)(b[i].s1[j]-'a'+1)*base[j]%MOD;
					sum2[j] = (i64)(b[i].s2[j]-'a'+1)*base[j]%MOD;
					if (j) {
						sum1[j] += sum1[j-1];
						(sum1[j] >= MOD) && (sum1[j] -= MOD);
						sum2[j] += sum2[j-1];
						(sum2[j] >= MOD) && (sum2[j] -= MOD);
					}
				}
				for (int y = 0; y < x; y++) {
					if (vec[t][y].se) continue;
					int j = vec[t][y].fi;
					int l = b[i].L-a[j].L, r = b[i].R+a[j].len-a[j].R-1;
					if (r >= b[i].len) continue;
					int now1 = sum1[r]-(l?sum1[l-1]:0);
					int now2 = sum2[r]-(l?sum2[l-1]:0);
					(now1 < 0) && (now1 += MOD);
					(now2 < 0) && (now2 += MOD);
					if ((i64)val1[j]*base[l]%MOD == now1 && (i64)val2[j]*base[l]%MOD == now2)
						++rst[i];
				}
			}
		}
		for (int i = 1; i <= q; i++) cout << rst[i] << '\n';
	}
}

char ED;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	bool flg = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s1 >> a[i].s2;
		a[i].len = a[i].s1.size();
		a[i].L = a[i].R = -1;
		int cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < a[i].len; j++) {
			if (a[i].s1[j] != 'a' && a[i].s1[j] != 'b') flg = false;
			if (a[i].s2[j] != 'a' && a[i].s2[j] != 'b') flg = false;
			if (a[i].s1[j] == 'b') ++cnt1;
			if (a[i].s2[j] == 'b') ++cnt2;
			if (a[i].s1[j] != a[i].s2[j]) {
				if (a[i].L == -1) a[i].L = j;
				a[i].R = j;
			}
		}
		if (cnt1 != 1 || cnt2 != 1) flg = false;
		m = max(m, a[i].len-a[i].R);
	}
	for (int i = 1; i <= q; i++) {
		cin >> b[i].s1 >> b[i].s2;
		if (b[i].s1.size() != b[i].s2.size()) continue;
		b[i].len = b[i].s1.size();
		b[i].L = b[i].R = -1;
		int cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < b[i].len; j++) {
			if (b[i].s1[j] != 'a' && b[i].s1[j] != 'b') flg = false;
			if (b[i].s2[j] != 'a' && b[i].s2[j] != 'b') flg = false;
			if (b[i].s1[j] == 'b') ++cnt1;
			if (b[i].s2[j] == 'b') ++cnt2;
			if (b[i].s1[j] != b[i].s2[j]) {
				if (b[i].L == -1) b[i].L = j;
				b[i].R = j;
			}
		}
		if (cnt1 != 1 || cnt2 != 1) flg = false;
		m = max(m, b[i].len-b[i].R);
	}
	if ((n <= 1000 && q <= 1000) || q == 1) {
		S50::solve();
	} else if (flg) {
		S70::solve();
	} else {
		Solve::solve();
	}
	
	return 0;
}
/*
Expectation: 70 pts +
Compare:
fc "D:\CQ-S00617\replace.out" "D:\CQ-S00617\replace3.ans"
Log: - 冷静一点。Subtask 至少有 70 pts。 
     - 加了一点点乱搞。。 
*/
