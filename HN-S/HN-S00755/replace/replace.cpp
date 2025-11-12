#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
string s1[N], s2[N];
int n, q;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
	while(q--){
		string str1, str2;
		cin >> str1 >> str2;
		long long cnt = 0;
		for(int i = 0; i < str1.size(); i++){
			for(int j = 1; j <= n; j++){
				string tmp = str1;
				if(str1.size() >= s1[j].size() && i <= str1.size() - s1[j].size()
					&& str1.substr(i, s1[j].size()) == s1[j]){
					tmp.replace(i, s1[j].size(), s2[j]);
					if(tmp == str2) cnt++;
				} 	
				//cout << i << "  " << j << "  " << tmp.replace(i, s1[j].size(), s2[j]) << "\n";
			}
		}
		cout << cnt << "\n";
	}
	return 0;
} 
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
