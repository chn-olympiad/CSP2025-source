// 50pts
#include<bits/stdc++.h>
using namespace std;
using LL = unsigned long long;

const int kMaxN = 2e5 + 5, kMaxM = 5e6 + 5;

int n, q;
LL base = 233, bpow[kMaxM], has1[kMaxM], has2[kMaxM];
string t1, t2, s[kMaxN][3];
LL h1[kMaxN], h2[kMaxN];

LL get_hash(LL has[], int l, int r) {
	return has[r] - has[l - 1] * bpow[r - l + 1];
}

LL calc(LL has[], int l, int r, int n) {
	return has[n] - has[r] * bpow[n - r] + has[l - 1] * bpow[n - l + 1];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	bpow[0] = 1;
	for(int i = 1; i < kMaxM; i++) {
		bpow[i] = bpow[i - 1] * base;
	}
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
		int len = s[i][1].size();
		s[i][1] = " " + s[i][1], s[i][2] = " " + s[i][2];
		for(int j = 1; j <= len; j++) {
			h1[i] = h1[i] * base + s[i][1][j];
			h2[i] = h2[i] * base + s[i][2][j];
		}
	}
	while(q--) {
		cin >> t1 >> t2;
		if(t1.size() != t2.size()) {
			cout << "0\n";
			continue;
		}
		int len = t1.size();
		t1 = " " + t1, t2 = " " + t2;
		for(int i = 1; i <= len; i++) {
			has1[i] = has1[i - 1] * base + t1[i];
			has2[i] = has2[i - 1] * base + t2[i];
		}
		LL ans = 0;
		int l = 0, r = 0;
		for(int i = 1; i <= len; i++) {
			if(t1[i] != t2[i]) {
				if(!l) l = i;
				r = i;
			}
		}
		for(int i = 1; i <= n; i++) {
			int x = s[i][1].size() - 1;
			if(r - l + 1 > x) continue;
			for(int j = max(1, r - x + 1); j <= min(l, len - x + 1); j++) {
				if(get_hash(has1, j, j + x - 1) == h1[i] && get_hash(has2, j, j + x - 1) == h2[i]) {
					++ans;
				}
//				cout << j << ' ' << get_hash(has1, j, j + x - 1) << ' ' << h1[i] << '\n';
//				cout << t1.substr(j, x) << s[i][1] << '\n';
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
