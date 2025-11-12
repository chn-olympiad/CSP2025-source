#include <bits/stdc++.h>

using namespace std;
const int M = 998244353, k = 31;
int n, q, L1, MP[5000006];
int ksm(int x, int y) {
	int ret = 1;
	while(y) {
		if(y & 1) ret = ret * 1ll * x % M;
		x = 1ll * x * x % M, y >>= 1;
	}
	return ret;
}
struct P {
	string od, nw;
	int len;
	vector<int> H[2];
	int get(int l, int r, int f) {
		return (H[f][r] - H[f][l - 1] * 1ll * MP[r - l + 1] % M + M) % M;
	}
	void build() {
		len = od.size() - 1;
		H[0].resize(od.size());
		H[1].resize(od.size());
		H[0][0] = H[1][0] = 0;
		for(int i = 1; i <= len; i ++) {
			H[0][i] = 1ll * H[0][i - 1] * k % M + (od[i] - 'a');
			H[1][i] = 1ll * H[1][i - 1] * k % M + (nw[i] - 'a');
			if(H[0][i] >= M)H[0][i] -= M;
			if(H[1][i] >= M)H[1][i] -= M;
		}
	}
}s[200005];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	MP[0] = 1;
	for(int i = 1; i <= 5000000; i ++)MP[i] = 1ll * MP[i - 1] * k % M;
	for(int i = 1; i <= n; i ++) {
		cin >> s[i].od >> s[i].nw;
		L1 += s[i].od.size();
		s[i].od = ' ' + s[i].od;
		s[i].nw = ' ' + s[i].nw;
		s[i].build();
	}
	while(q --) {
		P x;
		int l, r, ans = 0;
		cin >> x.od >> x.nw;
		if(x.od.size() != x.nw.size()) {
			cout << "0\n";
			continue;
		}
		x.od = ' ' + x.od;
		x.nw = ' ' + x.nw;
		x.build();
		for(int i = 1; i <= x.len; i ++) if(x.od[i] != x.nw[i]) {
			l = i;
			break;
		}
		for(int i = x.len; i; i --) if(x.od[i] != x.nw[i]) {
			r = i;
			break;
		}
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= min(s[i].len - (r - l), l); j ++) {
				int L = l - j + 1, R = L + s[i].len - 1;
				if(L > 0 && R <= x.len && s[i].get(1, s[i].len, 0) == x.get(L, R, 0) && s[i].get(1, s[i].len, 1) == x.get(L, R, 1))
					ans ++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}


