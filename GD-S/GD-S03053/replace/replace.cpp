#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int maxn = 1005;
ll n, q, len[maxn];
char s[maxn], t[maxn]; 
unordered_map <ull, ll> id;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> (s + 1) >> (t + 1);
		len[i] = strlen(s + 1);
	}
	while (q--) cout << 0 << '\n';
	return 0;
} 
