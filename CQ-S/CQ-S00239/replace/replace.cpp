#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5000010, M = 5000010;
const int mod1 = 998244353, mod2 = 1e9 + 9;
ll S = 131, SS = 13331;
ll h1[N], h2[N], H1[N], H2[N], f1[N], f2[N];
int len[M], fi[M], id[M];
int lwz[M];
ll sum1[M], sum2[M];
string s1, s2;
string S1[M], S2[M];
vector<int> sl[M], sr[M];
unordered_map<ll, int> mp;
int cnt;
bool cmp(int x, int y) {
	if (S1[x].size() != S1[y].size()) return S1[x].size() < S1[y].size();
	if (S1[x] != S1[y]) return S1[x] < S1[y];
	return S2[x] < S2[y];
}
ll workh(int l, int r) {
	return ((h1[r] - h1[l - 1] * f1[r - l + 1]) % mod1 + mod1) % mod1 * mod2 + 
			((h2[r] - h2[l - 1] * f2[r - l + 1]) % mod2 + mod2) % mod2;
}
ll workH(int l, int r) {
	return ((H1[r] - H1[l - 1] * f1[r - l + 1]) % mod1 + mod1) % mod1 * mod2 + 
			((H2[r] - H2[l - 1] * f2[r - l + 1]) % mod2 + mod2) % mod2;
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	f1[0] = f2[0] = 1;
	for (int i = 1; i < N; i ++ ) f1[i] = f1[i - 1] * S % mod1, f2[i] = f2[i - 1] * SS % mod2;
	int n, Q;cin >> n >> Q;
	for (int i = 1; i <= n; i ++ ) cin >> S1[i] >> S2[i], id[i] = i, lwz[i] = 1;
	sort(id + 1, id + n + 1, cmp);
	for (int i = 2; i <= n; i ++ ) if (S1[id[i]] == S1[id[i - 1]] && S2[id[i]] == S2[id[i - 1]]) lwz[i] += lwz[i - 1], lwz[i - 1] = 0;
	for (int i = 1; i <= n; i ++ ) if (lwz[i]) {
		s1 = S1[id[i]], s2 = S2[id[i]];
		len[i] = s1.size();
		s1 = "#" + s1, s2 = "#" + s2;
		if (s1 == s2) continue;
		int L = 1, R = len[i];
		while (s1[L] == s2[L]) L ++;
		while (s1[R] == s2[R]) R --;
		ll A = 0, B = 0;
		for (int j = 1; j <= len[i]; j ++ ) A = (A * S + s1[j] - 'a' + 1) % mod1, B = (B * SS + s1[j] - 'a' + 1) % mod2;
		sum1[i] = A * mod2 + B;
		A = 0, B = 0;
		for (int j = 1; j <= len[i]; j ++ ) A = (A * S + s2[j] - 'a' + 1) % mod1, B = (B * SS + s2[j] - 'a' + 1) % mod2;
		sum2[i] = A * mod2 + B;
		A = 0, B = 0;
		for (int j = R; j; j -- ) A = (A * S + s1[j] - 'a' + 1) % mod1, B = (B * SS + s1[j] - 'a' + 1) % mod2;
		ll it = A * mod2 + B;
		if (!mp[it]) mp[it] = ++ cnt;
		sr[mp[it]].push_back(i);
		A = 0, B = 0;
		for (int j = L; j <= len[i]; j ++ ) A = (A * S + s1[j] - 'a' + 1) % mod1, B = (B * SS + s1[j] - 'a' + 1) % mod2;
		it = A * mod2 + B;
		if (!mp[it]) mp[it] = ++ cnt;
		sl[mp[it]].push_back(i);
	}
	cerr << clock() << '\n';
	while (Q -- ) {
		cin >> s1 >> s2;
		int m = s1.size();
		s1 = "#" + s1, s2 = "#" + s2;
		int l = 1, r = m;
		while (s1[l] == s2[l]) l ++;
		while (s1[r] == s2[r]) r --;
		for (int i = 1; i <= m; i ++ )
			h1[i] = (h1[i - 1] * S + s1[i] - 'a' + 1) % mod1, h2[i] = (h2[i - 1] * SS + s1[i] - 'a' + 1) % mod2;
		for (int i = 1; i <= m; i ++ )
			H1[i] = (H1[i - 1] * S + s2[i] - 'a' + 1) % mod1, H2[i] = (H2[i - 1] * SS + s2[i] - 'a' + 1) % mod2;
		ll A = 0, B = 0, suml = 0, sumr = 0, ans = 0;
		for (int i = l; i <= m; i ++ ) {
			A = (A * S + s1[i] - 'a' + 1) % mod1, B = (B * SS + s1[i] - 'a' + 1) % mod2;
			if (i >= r) {
				int u = mp[A * mod2 + B];
				if (!u) continue;
				suml += sl[u].size();
			}
		}
		A = 0, B = 0;
	 	for (int i = r; i; i -- ) {
	 		A = (A * S + s1[i] - 'a' + 1) % mod1, B = (B * SS + s1[i] - 'a' + 1) % mod2;
			if (i <= l) {
				int u = mp[A * mod2 + B];
				if (!u) continue;
				sumr += sr[u].size();
			}
		}
		if (suml <= sumr) {
			A = 0, B = 0;
			for (int i = l; i <= m; i ++ ) {
				A = (A * S + s1[i] - 'a' + 1) % mod1, B = (B * SS + s1[i] - 'a' + 1) % mod2;
				if (i >= r) {
					int u = mp[A * mod2 + B];
					if (!u) continue;
					for (int x : sl[u]) if (len[x] <= i && workh(i - len[x] + 1, i) == sum1[x] && workH(i - len[x] + 1, i) == sum2[x])
						ans += lwz[x];
				}
			}
		}
		else {
			A = 0, B = 0;
			for (int i = r; i; i -- ) {
				A = (A * S + s1[i] - 'a' + 1) % mod1, B = (B * SS + s1[i] - 'a' + 1) % mod2;
				if (i <= l) {
					int u = mp[A * mod2 + B];
					if (!u) continue;
					for (int x : sr[u]) if (i + len[x] - 1 <= m && workh(i, i + len[x] - 1) == sum1[x] && workH(i, i + len[x] - 1) == sum2[x])
						ans += lwz[x];
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
