// O( nq + L1 + L2 )
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N = 2e5 + 5, M = 2.5e6 + 5, P = 13331;
int n, q;
char s[M], t[M];
ull x[N][2], y[N][2], z[N][2];
int l[N], r[N];
bool del[N];

void get(int id) {
	scanf("\n %s\n %s", s + 1, t + 1);
	int len = strlen(s + 1), ll = 1, rr = len;
	while (ll <= n && s[ll] == t[ll]) ll++; while (rr >= 1 && s[rr] == t[rr]) rr--;
	if (ll > rr) return del[id] = 1, void();	// same, delete
	ull h1 = 0, h2 = 0;
	for (int i = ll; i <= rr; i++) h1 = h1 * P + s[i], h2 = h2 * P + t[i]; y[id][0] = h1, y[id][1] = h2;
	h1 = 0, h2 = 0; for (int i = ll - 1; i >= 1; i--) h1 = h1 * P + s[i], h2 = h2 * P + t[i]; x[id][0] = h1, x[id][1] = h2;
	h1 = 0, h2 = 0; for (int i = rr + 1; i <= len; i++) h1 = h1 * P + s[i], h2 = h2 * P + t[i]; z[id][0] = h1, z[id][1] = h2;
	l[id] = ll - 1, r[id] = len - rr;
}

ull h1[M][2], h2[M][2];

int tot;
map< pair<ull, ull> , int > mp;
vector<int> v[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) get(i);
	for (int i = 1; i <= n; i++) {
		pair<ull, ull> res = {y[i][0], y[i][1]};
		if (!mp[res]) mp[res] = ++tot;
		v[mp[res]].push_back(i);
	}
	for (int e = 1; e <= q; e++) {
		scanf("\n %s\n %s", s + 1, t + 1);
		int len = strlen(s + 1), L = 1, R = len;
		while (s[L] == t[L]) L++; while (s[R] == t[R]) R--;
		
		ull mid1 = 0, mid2 = 0;
		for (int i = L; i <= R; i++) mid1 = mid1 * P + s[i], mid2 = mid2 * P + t[i];
		for (int i = 1, j = L - 1; j >= 1; i++, j--) h1[i][0] = h1[i - 1][0] * P + s[j], h1[i][1] = h1[i - 1][1] * P + t[j];
		for (int i = 1, j = R + 1; j <= len; i++, j++) h2[i][0] = h2[i - 1][0] * P + s[j], h2[i][1] = h2[i - 1][1] * P + t[j];
		
		int ans = 0;
		pair<ull, ull> ss = {mid1, mid2};
		for (int i : v[mp[ss]]) {
//			if (y[i][0] ^ mid1) continue; if (y[i][1] ^ mid2) continue;
			if (l[i] > L - 1 || r[i] > len - R) continue;	// out of range
			if (h1[l[i]][0] ^ x[i][0]) continue;
			if (h1[l[i]][1] ^ x[i][1]) continue;
			if (h2[r[i]][0] ^ z[i][0]) continue;
			if (h2[r[i]][1] ^ z[i][1]) continue;
			ans++;
//			cout << '\t' << i << '\t' << l[i] << ' ' << L - 1 << ' ' << r[i] << ' ' << len - R << endl;
		}
		printf("%d\n", ans);
	}
	return 0;
}
