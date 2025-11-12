#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, m;
unordered_map<string, string>mp;
string h[N], l[N];
int d[N];
int main() {
	//freopen("replace.in", "r", stdin);
	//freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		string a, s;
		cin >> a >> s;
		h[i] = a, l[i] = s;
		mp[a] = s;
	}
	while(m--) {
		string a, s;
		cin >> a >> s;
		int p = 0;
		string z = "";
		for(int j = 1; j <= n; j++) {
			string z = a;
			while(z.size() >= 1) {
				int y = z.find(h[j]);
				if(y > z.size() ||y < 0) {
					break;
				}
				if(z.size() >= h[j].size() && z.find(h[j]) >= 0) {
					string y = z;
					string q = a;
					q.replace(z.find(h[j]) + a.size() - z.size(), h[j].size(), l[j]);
					if(q == s) {
						p++;
						break;
					}
					
					z = y;
				}
				z.replace(0, 1, "");
				y = z.find(h[j]);
				if(y > z.size() ||y < 0) {
					break;
				}
				z.replace(0, z.find(h[j]), "");
			}
		}
		cout << p << endl;
	}
	return 0;
}
/*
3 4
a b
aa ab
aaa aaa
aa bb
aaaa aaab
a c
b a
*/
