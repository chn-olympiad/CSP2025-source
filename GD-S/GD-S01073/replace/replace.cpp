#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >>q;
	map<string, string> m;
	vector<string> v;
	for (int i = 0; i < n;i++){
		string a, b;
		cin >> a >>b;
		m[a] = b;
		v.push_back(a);
	}
	while(q--){
		string a, b;
		cin >> a >> b;
		int ans = 0;
		for (string s:v){
			int slong = s.size();
			//cout <<"s:"<< s << endl;
			if (slong > a.size()) continue;
			for (int i = 0;i <= a.size()-slong;i++){
				string as = "";
				if (a.substr(i, slong)==s) {
					as = a;
					as.replace(i, i+slong+1, m[s]);
					//cout << "as:   " << as << endl;
					as += a.substr(i+slong);
					if (as == b) ans++;
				}
				//cout <<"as:"<< a.substr(i, slong) << " " << as << endl;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 

