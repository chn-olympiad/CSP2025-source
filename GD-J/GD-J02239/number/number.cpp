#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    // program
    string s;
    cin >> s;
    int len = s.length();
    vector<char> c;
    for(int i = 0;i < len;i++){
    	if(s[i] >= '0' && s[i] <= '9') c.push_back(s[i]);
	}
	sort(c.begin(), c.end());
	len = c.size();
	for(int i = len - 1;i >= 0;i--){
		cout << c[i];
	}
	cout << endl;
    return 0;
}
