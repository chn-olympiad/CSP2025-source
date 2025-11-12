#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 10;
const ull P = 131;
int n, q;
ull h[N][2], ha[N][2], p[N] = {1};
string ch[N][2];
ull get0(int l, int r) {
	if (l > r) return 0;
	return h[r][0] - h[l - 1][0] * p[r - l + 1];
}
ull get1(int l, int r) {
	if (l > r) return 0;
	return h[r][1] - h[l - 1][1] * p[r - l + 1];
}
ull get2(int l, int r) {
	if (l > r) return 0;
	return ha[r][0] - ha[l - 1][0] * p[r - l + 1];
}
ull get3(int l, int r) {
	if (l > r) return 0;
	return ha[r][1] - ha[l - 1][1] * p[r - l + 1];
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++ )
		cin >> ch[i][0] >> ch[i][1];
	for (int i = 1; i < N; i ++ ) p[i] = p[i - 1] * P;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 0; j < ch[i][0].size(); j ++ ) h[i][0] = h[i][0] * P + (ch[i][0][j] - 'a' + 1);
		for (int j = 0; j < ch[i][1].size(); j ++ ) h[i][1] = h[i][1] * P + (ch[i][1][j] - 'a' + 1);
	}
	while (q -- ) {
		string a, b;
		cin >> a >> b;
		int nn = a.size(), mm = b.size();
		if (nn != mm) {
			cout << 0 << '\n';
			continue;
		}
		for (int i = 1; i <= nn; i ++ )
			ha[i][0] = ha[i - 1][0] * P + (a[i - 1] - 'a' + 1), ha[i][1] = ha[i - 1][1] * P + (b[i - 1] - 'a' + 1);
		int ans = 0;
		for (int i = 0; i < nn; i ++ ) {
			for (int j = 1; j <= n; j ++ ) {
				if (i + ch[j][0].size() - 1 >= nn) continue;
				if (get2(i + 1, i + ch[j][0].size()) == h[j][0]) {
					if (get2(1, i) == get3(1, i) && h[j][1] == get3(i + 1, i + ch[j][0].size()) && get2(i + ch[j][0].size() + 1, nn) == get3(i + ch[j][0].size() + 1, nn))
						ans ++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

