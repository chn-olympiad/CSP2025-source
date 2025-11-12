#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	vector<char> ans;
	for(char c:s){
		if(c>='0' and c<='9'){
			ans.push_back(c);
		}
	}
	sort(ans.begin(), ans.end(), greater<char>());
	for(char c:ans){
		cout << c;
	}
	cout << endl;
	return 0;
}
