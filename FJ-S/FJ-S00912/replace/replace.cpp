#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, string> str;

int ans = 0;

void findx(string t1, string t2, int pl, int pr) {
	
	for(int i = 0; i < pl; i++) {
		for(int j = pr; j > i; j--) {
			string tr1 = t1.substr(j - i);
			string tr2 = t2.substr(j - i);
			if(str[tr1] == tr2) {
				ans++;
			}
			findx(t1.substr(j - i), t2.substr(j - i), i, j);
		}
	}
}


int main() {
	freopen("replace.out", "w", stdout);
	freopen("replace.in", "r", stdin);
	
	int n, q;
	cin >> n >> q;
	
	string u, v;
	for(int i = 1; i <= n; i++) {
		cin >> u >> v;
		str[u] = v;
	}
	
	string t1, t2;
	for(int i = 1; i <= q; i++) {
		cin >> t1 >> t2;
		
		int len = t1.size();
		findx(t1, t2, 0, len);
		
		cout << ans << endl;
	}
	return 0;
}
