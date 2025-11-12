#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 200010

int n, q;
string s[N][3];
map<string, bool> f;
int chang[N];
string t1, t2;
int cnt = 0;
void calc(string a) {
	if(a == t2) {
		cnt++;
		return;
	}
	if(f[a] == true) {
		return;
	}
	f[a] = true;
	for(int l = 1;l <= n;l++) {
		int fd = a.find(s[l][1]);
		while(0 <= fd && fd <= n) {
			if(chang[l] == true) {
				fd = a.find(s[l][1], fd + 1);
				continue;
			}
			chang[l] = true;
			string x = a.substr(0, fd);
			string z = a.substr(fd + s[l][1].size(), n - fd - s[l][1].size() + 1);
			if(x + s[l][2] + z == t2) {
				cnt++;
			}
			fd = a.find(s[l][1], fd + 1);
			chang[l] = false;
		}
	}
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++) {
		cin >> s[i][1] >> s[i][2];
	}
	while(q--) {
		cin >> t1 >> t2;
		cnt = 0;
		f.clear();
		calc(t1);
		cout << cnt << "\n";
	}
	return 0;
} 
