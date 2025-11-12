#include <iostream>
#include <map>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
bool cmp(vector <int> a, vector <int> b){
	for (int i = 0; i < a.size(); i++){
		if (a[i] != b[i])return a[i] < b[i];
	}
}
map <vector<int>, vector<int> > m;
vector <int> com(string a, string b){
	vector <int> v(26);
	for (int i = 0; i < a.size(); i++)v[a[i] - 'a']++;
	for (int i = 0; i < b.size(); i++)v[b[i] - 'a']--;
	return v;
}
int n, q;
string s[200010][2];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++){
		cin >> s[i][0] >> s[i][1];
	}
	for (int i = 0; i < n; i++){
		m[com(s[i][0], s[i][1])].push_back(i);
	}
	for (int i = 0; i < q; i++){
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()){
			cout << 0 << endl;
			continue;
		}
		vector <int> ok = m[com(t1, t2)];
		int cnt = 0;
		for (int j = 0; j < ok.size(); j++){
			string s1 = s[ok[j]][0], s2 = s[ok[j]][1];
			for (int k = 0; k <= int(t1.size()) - int(s1.size()); k++){
				string y = t1;
				if (t1.substr(k, s1.size()) == s1 && t1.replace(k, s1.size(), s2) == t2)cnt++;
				t1 = y;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
} 
