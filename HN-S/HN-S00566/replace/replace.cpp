#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ullg;
const ullg P = 13331;
int n, q;
inline bool check(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 'a' && s[i] != 'b')
			return false;
		cnt += s[i] == 'b';
	}
	return cnt == 1;
}
string s[200005][2], t[200005][2];
ullg hs[200005][2], ths[200005], pw[200005];
ullg geths(int l, int r) {
	return ths[r] - ths[l - 1] * pw[r - l + 1]; 
}
namespace Work1 {
	void solve() {
		pw[0] = 1;
		for (int i = 1; i <= 2000; i++)
			pw[i] = pw[i - 1] * P;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < s[i][0].size(); j++)
				hs[i][0] = hs[i][0] * P + s[i][0][j];
			for (int j = 0; j < s[i][1].size(); j++)
				hs[i][1] = hs[i][1] * P + s[i][1][j];
		}
		for (int i = 1; i <= q; i++) {
			int m = t[i][0].size();
			t[i][0] = " " + t[i][0], t[i][1] = " " + t[i][1];
			ullg lst = 0;
			for (int j = 1; j <= m; j++)
				ths[j] = ths[j - 1] * P + t[i][0][j], lst = lst * P + t[i][1][j];
			int ans = 0;
			for (int k = 1; k <= n; k++) {
				int tmp = s[k][0].size();
				for (int j = 1; j + tmp - 1 <= m; j++) {
					if (geths(j, j + tmp - 1) == hs[k][0]) {
						ullg now = ths[j - 1] * pw[m - j + 1] + hs[k][1] * pw[m - (j + tmp - 1)] + geths(j + tmp, m);
						if (now == lst)
							ans++;
					}
				}
			}
			cout << ans << '\n';
		}
	}
}
 
namespace Work2 {
	const int Len = 5e6;
	struct M {
		int x, y, id;
	};
	inline bool cmp(M x, M y) { return x.x ^ y.x ? x.x < y.x : (x.y ^ y.y ? x.y < y.y : x.id < y.id); }
	unordered_map<int, vector<M>> mp;
	int ans[200005];
	struct Fenwick {
		int dat[5000005], mxn = 5e6;
		#define lowbit(x) x & -x
		void update(int x, int k) {
			if (!x)
				dat[x++]++;
			for (int i = x; i <= mxn; i += lowbit(i))
				dat[i] += k;
		}
		int ask(int x) {
			if (!x)
				return dat[x];
			int sum = 0;
			for (int i = x; i >= 1; i -= lowbit(i))
				sum += dat[i];
			return sum;
		}
		#undef lowbit
	} tr;
	void solve() {
		for (int i = 1; i <= q; i++) {
			int fst = 0, lst = 0;
			for (int j = 0; j < t[i][0].size(); j++) {
				if (t[i][0][j] == 'b')
					fst = j;
				if (t[i][1][j] == 'b')
					lst = j;
			}
			mp[lst - fst].push_back((M){fst, (int)t[i][0].size() - fst, i});
		}
		for (int x = 1; x <= n; x++) {
			int nfst = 0, nlst = 0;
			for (int j = 0; j < s[x][0].size(); j++) {
				if (s[x][0][j] == 'b')
					nfst = j;
				if (s[x][1][j] == 'b')
					nlst = j;
			}
			mp[nlst - nfst].push_back((M){nfst, (int)s[x][0].size() - nfst});
		}
		for (auto x : mp) {
			vector<M> now = x.second;
			sort(now.begin(), now.end(), cmp);
			for (auto y : now) {
				if (!y.id)
					tr.update(y.y, 1);
				else {
					ans[y.id] = tr.ask(y.y);
				}
			}
			for (auto y : now) {
				if (!y.id)
					tr.update(y.y, -1);
			}
		}
		for (int i = 1; i <= q; i++)
			cout << ans[i] << '\n';
		
	}
} 
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	cin >> n >> q;
	bool fg = 1;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
		fg &= check(s[i][0]), fg &= check(s[i][1]);
	}
	for (int i = 1; i <= q; i++) {
		cin >> t[i][0] >> t[i][1];
		fg &= check(t[i][0]), fg &= check(t[i][1]);
	}
	if (fg) {
		Work2::solve(); 
	}
	else {
		Work1::solve(); 
	}
	return 0;
}
