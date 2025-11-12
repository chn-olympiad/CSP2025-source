#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool st;
bool check(string str) {
	int cnt = 0;
	for(int i = 0; i < str.size(); i++) {
		if(str[i] != 'a' && str[i] != 'b') return 0;
		else if(str[i] == 'b') {
			if(!cnt) cnt = 1;
			else return 0;
		} 
	}
	return 1;
}

const int N = 2e5, M = 5e6;
const int Mod[2] = {1000000000 + 7, 998244353};
const int ba[2] = {14329, 343893};
int bas[2][M + 10], n, q;

struct hsh {
	int val[2];
	bool operator == (const hsh &other) const {
		return ((val[0] == other.val[0]) && (val[1] == other.val[1]));
	}
} ptmp[N + 10], qtmp[N + 10];
hsh get(hsh B, hsh A, int len) {
	return (hsh){(ll)(B.val[0] - 1ll * A.val[0] * bas[0][len] % Mod[0] + Mod[0]) % Mod[0],
				(ll)(B.val[1] - 1ll * A.val[1] * bas[1][len] % Mod[1] + Mod[1]) % Mod[1]};
}
vector <hsh> hs1[N + 10], hs2[N + 10];
string s1[N + 10], s2[N + 10], t1[N + 10], t2[N + 10];
int stpos[N + 10], edpos[N + 10];
namespace solve1 {
	void solve() {
		for(int i = 1; i <= n; i++) {
			s1[i] = "#" + s1[i], s2[i] = "#" + s2[i];

			hsh tmp; tmp.val[0] = tmp.val[1] = 0;
			hs1[i].push_back(tmp);
			for(int j = 1; j < s1[i].size(); j++) {
				for(int k = 0; k < 2; k++) 
					tmp.val[k] = (1ll * tmp.val[k] * ba[k] % Mod[k] + s1[i][j]) % Mod[k];
				hs1[i].push_back(tmp);
			}

			tmp.val[0] = tmp.val[1] = 0;
			hs2[i].push_back(tmp);
			for(int j = 1; j < s2[i].size(); j++) {
				for(int k = 0; k < 2; k++)
					tmp.val[k] = (1ll * tmp.val[k] * ba[k] % Mod[k] + s2[i][j]) % Mod[k];
				hs2[i].push_back(tmp);
			}

			for(int j = 1; j < s1[i].size(); j++)
				if(s1[i][j] != s2[i][j]) {
					if(!stpos[i]) stpos[i] = j;
					edpos[i] = j;
				}
		}
		for(int i = 1; i <= q; i++) {
			if(t1[i].size() != t2[i].size()) {
				cout << "0\n";
				continue;
			}
			t1[i] = "#" + t1[i];
			t2[i] = "#" + t2[i];

			int ans = 0;
			ptmp[0].val[0] = ptmp[0].val[1] = 0;
			for(int k = 1; k < t1[i].size(); k++) {
				for(int l = 0; l < 2; l++)
					ptmp[k].val[l] = (1ll * ptmp[k - 1].val[l] * ba[l] % Mod[l] + t1[i][k]) % Mod[l];
			}
			qtmp[0].val[0] = qtmp[0].val[1] = 0;
			for(int k = 1; k < t2[i].size(); k++) {
				for(int l = 0; l < 2; l++) 
					qtmp[k].val[l] = (1ll * qtmp[k - 1].val[l] * ba[l] % Mod[l] + t2[i][k]) % Mod[l];
			}

			int st = 0, ed = 0;
			for(int j = 1; j < t1[i].size(); j++)
				if(t1[i][j] != t2[i][j]) {
					if(!st) st = j;
					ed = j;
				}

			for(int j = 1; j <= n; j++) {
				if(!stpos[j]) continue;

				if(get(hs1[j][edpos[j]], hs1[j][stpos[j] - 1], edpos[j] - stpos[j] + 1) ==
				get(ptmp[ed], ptmp[st - 1], ed - st + 1) &&
					get(hs2[j][edpos[j]], hs2[j][stpos[j] - 1], edpos[j] - stpos[j] + 1) == 
				get(qtmp[ed], qtmp[st - 1], ed - st + 1)) {
					int len = s1[j].size() - 1, rst = st - stpos[j] + 1;
					int red = rst + len - 1;
					if(rst >= 1 && red < t1[i].size() && 
						get(hs1[j][len], hs1[j][0], len) == get(ptmp[red], ptmp[rst - 1], len) &&
						get(hs2[j][len], hs2[j][0], len) == get(qtmp[red], qtmp[rst - 1], len))
					ans++;
				}
			}
			cout << ans << '\n';
		}
	}
}
namespace solve2 {
	int mp[2 * M + 10];
	struct node {
		int opt, st, rem, del, ind;
	} Q[6 * N + 10]; int tot = 0;
	bool cmp1(node &x, node &y) {
		if(x.st != y.st) return x.st < y.st;
		else if(x.rem != y.rem) return x.rem < y.rem;
		else return x.opt < y.opt;
	}
	bool cmp2(node &x, node &y) {
		if(x.rem != y.rem) return x.rem < y.rem;
		else return x.opt < y.opt;
	}
	int ans[N + 10];
	void divide(int l, int r) {
		if(l >= r) return ;
		int mid = (l + r) >> 1;
		divide(l, mid);
		divide(mid + 1, r);

		sort(Q + l, Q + mid + 1, cmp2);
		sort(Q + mid + 1, Q + r + 1, cmp2);

		int j = l;
		for(int i = mid + 1; i <= r; i++) {
			while(j <= mid && Q[j].rem <= Q[i].rem) {
				if(Q[j].opt == 0) mp[Q[j].del + M]++;
				j++;
			}
			if(Q[i].opt == 1) ans[Q[i].ind] += mp[Q[i].del + M];
		}
		for(int i = l; i < j; i++) mp[Q[i].del + M] = 0;
	}
	void solve() {
		for(int i = 1; i <= n; i++) {
			int st1 = 0, st2 = 0;
			for(int j = 0; j < s1[i].size(); j++) if(s1[i][j] == 'b') st1 = j;
			for(int j = 0; j < s2[i].size(); j++) if(s2[i][j] == 'b') st2 = j;
			Q[++tot] = ((node){0, st1, (int)s1[i].size() - 1 - st1, st2 - st1, 0});
		}
		for(int i = 1; i <= q; i++) {
			if(t1[i].size() != t2[i].size()) {
				cout << "0\n";
				continue;
			}
			int st1 = 0, st2 = 0;
			for(int j = 0; j < t1[i].size(); j++) if(t1[i][j] == 'b') st1 = j;
			for(int j = 0; j < t2[i].size(); j++) if(t2[i][j] == 'b') st2 = j;
			Q[++tot] = ((node){1, st1, (int)t1[i].size() - 1 - st1, st2 - st1, i});
		}
		sort(Q + 1, Q + tot + 1, cmp1);
		divide(1, tot);
		for(int i = 1; i <= q; i++)
			cout << ans[i] << '\n';
	}
}
bool ed;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	bas[0][0] = bas[1][0] = 1;
	for(int i = 0; i < 2; i++)
		for(int j = 1; j <= M; j++)
			bas[i][j] = 1ll * bas[i][j - 1] * ba[i] % Mod[i];

	cin >> n >> q;
	bool flag = 1;
	for(int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		if(flag) flag &= check(s1[i]);
		if(flag) flag &= check(s2[i]);
	}

	for(int i = 1; i <= q; i++) {
		cin >> t1[i] >> t2[i];
		if(flag) flag &= check(t1[i]);
		if(flag) flag &= check(t2[i]);
	}

	if(!flag)
		solve1::solve();
	else solve2::solve();
}