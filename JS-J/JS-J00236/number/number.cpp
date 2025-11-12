// JS-J00236
// XD

#include<bits/stdc++.h>
using namespace std;
string s;
string out;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); ++i){
		if (s[i] >= '0' && s[i] <= '9'){
			out += s[i];
		}
	}
	sort(out.begin(), out.end());
	for (int i = out.size() - 1; i >= 0; --i){
		cout << out[i];
	}
	return 0;
}
