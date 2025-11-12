#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, q;
string rep[200001];
string rep2[200001];
int ans = 0;
string q1, q2;
vector<int> getz(int j, string s) {
	int len = s.size();
	vector <int> z(len + 1, 0);
	int l = 0, r = 0;
	vector <int> v;
	for(int i = rep[j].size() + 2; i < len; i++) {
		if(i <= r && z[i - l] < r - l + 1) z[i] = z[i - l];
		else {
			z[i] = max(r - l + 1, 0);
			while(s[i + z[i]] == s[z[i]]) z[i]++;
			if(i + z[i] > r) {
				l = i;
				r = i + z[i];
			}
		}
		if(z[i] == rep[j].size()) v.push_back(i - rep[j].size() - 1);
//		cout << z[i] << " ";
	}
	return v;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> rep[i] >> rep2[i];
	}
	for(int i = 1; i <= q; i++) {
		int ans = 0;
		cin >> q1 >> q2;
		for(int j = 1; j <= n; j++) {
			string s = rep[j] + "#" + q1;
			vector <int> v = getz(j, s);
			if(v.size() == 0) continue;
			for(auto k : v) {
//				cout << k << " ";
				if(q1.substr(0, k) + rep2[j] + q1.substr(k) == q2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
