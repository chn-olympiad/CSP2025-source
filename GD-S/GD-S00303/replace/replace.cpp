#include <bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define vi vetor<int>
#define sz(a) ((int)a.size())
#define mp make_pair
#define pb emplace_back
#define pii pair<int, int>
using namespace std;
const int N = 1e6 + 10;
int n, q;
string a[N], b[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	L(i, 1, n) {
		cin >> a[i] >> b[i];
	}
	while(q--) {
		string s1, s2;
		cin >> s1 >> s2;
		if(sz(s1) != sz(s2)) {
			cout << 0 << '\n';
			continue;
		}
		int ans = 0;
		for(int i = 0; i < sz(s1); i++) {
			bool flag = true;
			for(int j = 0; j < i; j++) if(s1[j] != s2[j]) {
				flag = 0;
				break;
			}
			for(int j = 1; j <= n; j++) {
				int len = sz(a[j]);
				string x = s1.substr(i, len);
				string y = s2.substr(i, len);
				for(int k = i + len; k < sz(s1); k++) {
					if(s1[k] != s2[k]) {
						flag = 0;
						break;
					}
				}
				if(!flag) continue;
				if(x == a[j] && y == b[j]) ans++;
			}
		} 
		cout << ans << '\n';
	}
	return 0;
} 
