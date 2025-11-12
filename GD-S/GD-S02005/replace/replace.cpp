#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	map<string, vector<string> > m;
	for(int i = 0;i < n;i++){
		string s1, s2;
		cin >> s1 >> s2;
		m[s1].push_back(s2);
	}
	
	while(q--){
		string t1, t2;
		cin >> t1 >> t2;
		t1 = ' ' + t1 + ' ';
		t2 = ' ' + t2 + ' ';
		int len = t1.length();
		int cnt = 0;
		int frn = 0, bck = len - 1;
		for(;frn < len && t1[frn + 1] == t2[frn + 1];frn++);
		for(;bck >= 0 && t1[bck - 1] == t2[bck - 1];bck--);
		for(int i = 1;i <= frn + 1;i++){
			for(int j = len - 2;j >= bck - 1;j--){
//				cout << t1.substr(i, j - i + 1) << '\n';
				vector <string> tmp = m[t1.substr(i, j - i + 1)];
				string tt = t2.substr(i, j - i + 1);
				if(tmp.size()){
					for(int k = 0;k < tmp.size();k++){
						if(tmp[k] == tt) cnt++;
					}
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
xabcx

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
