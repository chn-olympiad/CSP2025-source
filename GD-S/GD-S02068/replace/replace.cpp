#include<bits/stdc++.h>
using namespace std;
int n, q;
struct node{
	string s1, s2;
}s[200005], t;
int main(){
	freopen("replace4.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d", &n);
	scanf("%d", &q);
	for (int i = 1; i <= n; i++){
		cin >> s[i].s1 >> s[i].s2;
	}
	while (q--){
		int num = 0;
		cin >> t.s1 >> t.s2;
		for (int i = 1; i <= n; i++){
			int id = 0, jd = 0;
			string y = "", tt;
			for (int j = 0; j < t.s1.size(); j++){
				if (jd == s[i].s1.size()) break;
				if (t.s1[j] == s[i].s1[jd]){
					if (jd == 0)id = j;
					y = y + s[i].s1[j];
					jd++;
				} else y = "", id = 0, jd = 0;
			}
			if (y.size() == s[i].s1.size()){
				for (int j = 0; j < t.s1.size(); j++){
					if (j == id){
						tt = tt + s[i].s2;
						j += s[i].s2.size();
					}
					tt = tt + t.s1[j];
				}
			}
			if (tt == t.s2) num++;
		}
		cout << num << endl;
	}
	return 0;
}
