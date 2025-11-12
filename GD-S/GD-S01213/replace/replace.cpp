#include <bits/stdc++.h>
using namespace std;

const int base = 3413;
const int mod = 998244353;
int n, q;
vector <int> nxt[100005][5];
string t1, t2;
string s[100005][5];
long long hs[100005][5], ht[5][5000005], p[5000005];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	p[0] = 1;
	for (int i = 1; i <= 5000001; i++) p[i] = p[i-1]*base%mod;
	for (int i = 1; i <= n; i++) cin >> s[i][1] >> s[i][2];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < s[i][1].size(); j++) hs[i][1] = (hs[i][1]*base%mod+s[i][1][j]-96)%mod;
		for (int j = 0; j < s[i][2].size(); j++) hs[i][2] = (hs[i][2]*base%mod+s[i][2][j]-96)%mod;
	}	
	while (q--) {
		cin >> t1 >> t2;
		ht[1][0] = t1[0]-96;
		for (int j = 1; j < t1.size(); j++) ht[1][j] = (ht[1][j-1]*base%mod+t1[j]-96)%mod;
		ht[2][0] = t2[0]-96;
		for (int j = 1; j < t2.size(); j++) ht[2][j] = (ht[2][j-1]*base%mod+t2[j]-96)%mod;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = s[i][1].size(); j < t1.size(); j++) {
				int h = (ht[1][j]-ht[1][j-s[i][1].size()+1]*p[s[i][1].size()]+mod)%mod;
				if (h == hs[i][1]) {
					int htt = ((ht[1][t1.size()-1]-h*p[t1.size()-1-j]+mod)%mod+p[t1.size()-1-j]*hs[i][2]%mod)%mod;
					if (htt == ht[2][t2.size()-1]) sum++;
				}
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
