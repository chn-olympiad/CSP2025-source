#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
#define ll long long

using namespace std;

const int N = 2e5 + 5, M = 5e6 + 5, bs = 13331, Mod = 1e9 + 7;

string s1[N], s2[N], t1[N], t2[N];
int L[N], R[N];
int hs[N][2], hs1[M], p[M];

int get(int l, int r) {
//	printf("get(%d, %d) = hs1[%d] - hs1[%d] * p[%d]\n", l, r, r, l - 1, r - l + 1);
	return (hs1[r] - (l > 0 ? (ll)hs1[l - 1] * p[r - l + 1] % Mod : 0) + Mod) % Mod;
}

signed main() {
//	freopen("data.txt", "r", stdin);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	p[0] = 1;
	for (int i = 1; i < M; i ++) p[i] = (ll)p[i - 1] * bs % Mod;
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= n; i ++) {
		int fst = -1, lst = -1;
		for (int j = 0; j < (int)s1[i].size(); j ++) {
			if (s1[i][j] != s2[i][j]) {
				fst = j; break;
			}
		}
		for (int j = (int)s1[i].size() - 1; j >= 0; j --) {
			if (s1[i][j] != s2[i][j]) {
				lst = j; break;
			}
		}
		if (fst == -1) continue;
		for (int j = 0; j < fst; j ++) hs[i][0] = ((ll)hs[i][0] * bs + (s1[i][j] - 'a')) % Mod;
		for (int j = lst + 1; j < (int)s1[i].size(); j ++) hs[i][1] = ((ll)hs[i][1] * bs + (s1[i][j] - 'a')) % Mod;
		L[i] = fst, R[i] = lst;
		for (int j = fst; j <= lst; j ++) {
			t1[i] += s1[i][j], t2[i] += s2[i][j];
		}
	}
//	for (int i = 1; i <= n; i ++) {
//		cout << t1[i] << ' ' << t2[i] << ' ' << L[i] << ' ' << R[i] << endl;
//	}
	while (q --) {
		string q1, q2; cin >> q1 >> q2;
		if ((int)q1.size() != (int)q2.size()) {
			cout << 0 << endl; continue;
		}
		string p1, p2;
		int fst = -1, lst = -1;
		for (int j = 0; j < (int)q1.size(); j ++) {
			if (q1[j] != q2[j]) {
				fst = j; break;
			}
		}
		for (int j = (int)q1.size() - 1; j >= 0; j --) {
			if (q1[j] != q2[j]) {
				lst = j; break;
			}
		}
		if (fst != -1) {
			for (int j = fst; j <= lst; j ++) {
				p1 += q1[j], p2 += q2[j];
			}
		}
//		cout << fst << ' ' << lst << ' ' << p1 << ' ' << p2 << endl;
		hs1[0] = q1[0] - 'a';
		for (int i = 1; i < (int)q1.size(); i ++) hs1[i] = ((ll)hs1[i - 1] * bs + (q1[i] - 'a')) % Mod;
		
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (t1[i] != p1 || t2[i] != p2) continue;
			int len = s1[i].size();
			if (fst < L[i] || (int)q1.size() - lst < len - R[i]) continue;
//			printf("dep 2\n");
			if ((L[i] > 0 && get(fst - L[i], fst - 1) != hs[i][0])
				|| (R[i] < len && get(lst + 1, lst + len - 1 - R[i]) != hs[i][1])) continue;
				
			ans ++;
		}
		cout << ans << endl;
	}
	return 0;
}

