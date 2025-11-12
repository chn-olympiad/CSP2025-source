#include <bits/stdc++.h>
using namespace std;
string s, res = "";
int len, len2;
vector<char> a;
bool cmp(char x, char y){
	return x > y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	len = s.size();
	for (int i=0; i<len; i++){
		if (s[i] >= '0' && s[i] <= '9'){
			a.push_back(s[i]);
		}
	}
	len2 = a.size();
	sort (a.begin(), a.end(), cmp);
	for (int i=0; i<len2; i++){
		res += a[i];
	}
	cout << res << "\n";
	return 0;
}
