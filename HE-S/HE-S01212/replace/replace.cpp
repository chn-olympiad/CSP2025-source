#include<bits/stdc++.h>

using namespace std;
const int maxn = 5e6 + 5;
string u[maxn], v[maxn];
int L[maxn], R[maxn];

void coder() {
	int n, q;
	cin >> n >> q;
	map<pair<string, string>, vector<int>> mp;
	for (int i = 1; i <= n; ++i) {
		string x, y;
		cin >> x >> y;
		u[i] = x;
		v[i] = y;
		int m = x.size();
		L[i] = 0, R[i] = m - 1;
		while (x[L[i]] == y[L[i]]) {
			++L[i];
		}
		while (x[R[i]] == y[R[i]]) {
			--R[i];
		}
		string a = "", b = "";
		for (int j = L[i]; j <= R[i]; ++j) {
			a.push_back(x[j]);
			b.push_back(y[j]);
		}
		mp[{a, b}].push_back(i);
	}
	while (q--) {
		string x, y;
		cin >> x >> y;
		int m = x.size();
		int k = y.size();
		if (m != k) {
			cout << 0 << '\n';
			continue;
		}
		int l = 0, r = m - 1;
		while (x[l] == y[l]) {
			++l;
		}
		while (x[r] == y[r]) {
			--r;
		}
		string a = "", b = "";
		for (int j = l; j <= r; ++j) {
			a.push_back(x[j]);
			b.push_back(y[j]);
		}
		int ans = 0;
		for (int j : mp[{a, b}]) {
			int len = u[j].size();
			if (len > m || L[j] > l || len - R[j] > m - r) {
				continue;
			}
			int flag = 1;
			int p = L[j] - 1, q = l - 1;
			while (p >= 0 && q >= 0) {
				if (u[j][p] != x[q]) {
					flag = 0;
					break;
				}
				--p;
				--q;
			}
			p = R[j] + 1, q = r + 1;
			
			while (p < len && q < m) {
				if (u[j][p] != x[q]) {
					flag = 0;
					break;
				}
				++p;
				++q;
			}
			ans += flag;
		}
		cout << ans << '\n';
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	coder();
	
	return 0; 
}
