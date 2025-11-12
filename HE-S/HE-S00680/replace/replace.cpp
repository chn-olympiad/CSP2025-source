#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
using namespace std;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	vector<string> s1, s2, t1, t2;
	for (int i = 0; i < n; i++) {
		string si1, si2;
		cin >> si1 >> si2;
		s1.push_back(si1);
		s2.push_back(si2);
	}
	for (int j = 0; j < q; j++) {
		string tj1, tj2;
		cin >> tj1 >> tj2;
		t1.push_back(tj1);
		t2.push_back(tj2);
	}
	 
	for (int j = 0; j < q; j++) {
		int cnt = 0;
		int len = t1[j].length();
		for (int l = 0; l < len; l++) {
			for (int i = 0; i < n; i++) {
				if (t1[j].substr(0, l) == t2[j].substr(0, l) && (l+s1[i].length()>t1[j].length()||l+s2[i].length()>t2[j].length()||t1[j].substr(l+s1[i].length()) == t2[j].substr(l+s2[i].length())) && t1[j].substr(l, s1[i].length()) == s1[i] && s2[i] == t2[j].substr(l, s2[i].length()))
					cnt++;
			}
		}
		cout << cnt << endl;
	}
}
