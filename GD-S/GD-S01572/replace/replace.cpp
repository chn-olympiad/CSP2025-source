#include <iostream>
#include <map>
using namespace std;
map<string, string> mp;
int main() {
	freopen("replace.in", "r", stdin); 
	freopen("replace.out", "w", stdout);
	
	int r, q;
	cin >> r >> q;
	for (int i = 0; i < r; i++) {
		string a, b;
		cin >> a >> b;
		mp[a] = b;
	}
	
	for (int i = 0; i < q; i++) {
		string a, b;
		int cnt = 0;
		cin >> a >> b;
		for (const pair<string, string> pa: mp) {
			int fi = a.find(pa.first);
			if (fi != string::npos) {
				string a1 = a;
				for (int i = 0; i < pa.second.size(); i++) {
					a1[fi + i] = pa.second[i];
				}
				if (a1 == b) cnt++;
			}
		}
		cout << cnt << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
