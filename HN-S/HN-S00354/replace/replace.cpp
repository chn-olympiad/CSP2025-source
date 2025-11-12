#include <bits/stdc++.h>
using namespace std;
long long base = 131;
const long long MOD1 = 482347;
const long long MOD2 = 131313;

int H1(string s) {
	long long sss = 0;
	for (int i = 0; i < s.size(); i++) {
		sss = sss * base + s[i] - 'a' + 1;
		sss %= MOD1;
	}
	return sss;
}
int H2(string s) {
	long long sss = 0;
	for (int i = 0; i < s.size(); i++) {
		sss = sss * base + s[i] - 'a' + 1;
		sss %= MOD2;
	}
	return sss;
}


int n, m;
vector <int> e1[500005];
vector <int> e2[500005];
long long p1[500005];
long long p2[500005];

int T;
int hashs1[500005], hashs2[500005];
int hasht1[500005], hasht2[500005];
int HS1(int l, int r) {
	return (hashs1[r] + MOD1 - (hashs1[l] * p1[r - l + 1]) % MOD1) % MOD1;
}
int HS2(int l, int r) {
	return (hashs2[r] + MOD2 - (hashs2[l] * p2[r - l + 1]) % MOD2) % MOD2;
}
void solve() {
	string s, t;
	cin >> s >> t;
	int l1 = s.size(), l2 = t.size();
	s = " " + s;
	t = " " + t;
	for (int i = 1; i <= l1; i++) {
		hashs1[i] = hashs1[i - 1] * base + s[i] - 'a' + 1;
		hashs2[i] = hashs2[i - 1] * base + s[i] - 'a' + 1;
		hashs1[i] %= MOD1;
		hashs2[i] %= MOD2;
	}
	for (int i = 1; i <= l2; i++) {
		hasht1[i] = hasht1[i - 1] * base + t[i] - 'a' + 1;
		hasht2[i] = hasht2[i - 1] * base + t[i] - 'a' + 1;
		hasht1[i] %= MOD1;
		hasht2[i] %= MOD2;
	}
	//for (int i = 1;)
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	p1[0] = 1;
	p2[0] = 1;
	
	for (int i = 1; i <= 500000; i++) {
		p1[i] = p1[i - 1] * base;
		p1 % MOD1;
		p2[i] = p2[i - 1] * base;
		p2 % MOD2;
		
	}
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		e1[H1(s1)].push_back(H1(s2));
		e2[H2(s1)].push_back(H2(s2));
	}
	while (m--) {
		solve();
	}
	return 0;
}
